#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <memory>

/*
练习，使用shared_ptr和weak_ptr
*/
class StrBlobPtr;   //提前声明StrBlobPtr类，在StrBlob中要声明友元
//一个管理string的类
class StrBlob{
public:
    friend StrBlobPtr;
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); };
    bool empty() const { return data->empty(); };
    //添加删除元素
    void push_back(const std::string &t) { data->push_back(t); };
    void pop_back();
    //元素访问
    std::string& front();
    std::string& back();
private:
    std::shared_ptr<std::vector<std::string>> data;
    //如果data[i]不合法，抛出一个异常
    void check(size_type i,const std::string &msg) const;
};
//外部定义类的构造函数
StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}  //将data初始化为智能指针，指向vector<string> 
StrBlob::StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)) {}  //列表初始化 

void StrBlob::check(size_type i,const string &msg) const{
    if(i >= data->size())
        throw out_of_range(msg);
}

string & StrBlob::front()
{
    //如果vector为空 check将抛出一个异常
    check(0,"front on empty StrBlob");
    return data->front();
}

string& StrBlob::back()
{
    check(0,"back on empty StrBlob");
    return data->back();
}
void StrBlob::pop_back()
{
    check(0,"pop_back on empty StrBlob");
    data->pop_back();
}

//定义指向StrBlob类的指针管理类  通过指针管理类访问对象，在原始类资源有被释放的可能时，更安全
class StrBlobPtr{
public:
    StrBlobPtr(): curr(0) {}
    StrBlobPtr(StrBlob &a,size_t sz = 0):
        wptr(a.data),curr(sz) {}
    std::string& deref() const;
    StrBlobPtr& incr(); //前缀递增
    string& begin() { auto p = check(0,"no element"); return (*p)[0];}   //访问首元素
    string& end(); //访问尾元素
private:
    //检查函数 成功返回一个指向vector的shared_ptr
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t,const std::string&) const;
    //保存一个weak_ptr,意味着底层vector可能会被销毁
    std::weak_ptr<vector<std::string>> wptr;
    std::size_t curr;
};
std::shared_ptr<std::vector<std::string>> 
StrBlobPtr::check(std::size_t i,const std::string &msg) const{
    auto ret = wptr.lock(); //确认vector是否还存在
    if(!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if(i>= ret->size())
        throw std::out_of_range(msg);
    return ret; //否则，返回指向vector的shared_ptr
}
std::string& StrBlobPtr::deref() const
{
    auto p = check(curr,"derefrence past end");
    return (*p)[curr];  //（*p）是对象所指向的vector
}

StrBlobPtr& StrBlobPtr::incr()
{
    check(curr,"increment past end of StrBlobPtr");
    ++curr; //推进当前位置
    return *this;
}
string& StrBlobPtr::end()
{
    auto ret = wptr.lock();
     if(!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    auto p = check(ret->size()-1,"end() no element");

    return (*p)[ret->size()-1]; //返回最后一个元素
}

int main()
{ 
    StrBlob strb;
    StrBlob strc;
    string str;
    StrBlobPtr wp(strb,0);
    
    cin >> str;
    strb.push_back(str);
    str.clear(); cin >> str;
    strb.push_back(str);
    str += "797";
    strb.push_back(str);

    cout << wp.end() << endl;
    cout << wp.begin() << endl;
    cout << wp.deref() << endl;
    wp.incr();  //指向下一个元素
    //cout << wp.deref() << endl;
    cout << strb.size() << endl;

    wp.incr();  //指向下一个元素  实质上，指向了尾后迭代器
    // cout << wp.deref() << endl; //尝试访问尾后迭代器，失败!  抛出异常
 
    
    return 0;
}