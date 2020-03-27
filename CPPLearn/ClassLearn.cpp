#include <iostream>
using namespace std;
#include <string>
#include <vector>




class Person {
	//新增构造函数
public:
	//Person() = default;
	
	Person(const string &s1, const string &s2, const unsigned &k) : personName(s1), addr(s2), age(k) { cout << this->personName << endl << age << endl; };
	Person() : Person("", "", 0) {};	//委托构造函数
	Person(const string &s1, const string &s2) : Person(s1, s2, 0) { this->age = 26; };	//委托构造函数 执行顺序为使用s1,s2,0传入三参数的构造函数，之后再执行age=26的赋值操作
	//添加成员函数
	string retName() const { return personName; }
	string retAddr(struct Person &p) const;
	friend istream &read(istream &is, Person &item);
	friend ostream &print(ostream &os, const Person &item);
private:
	string personName;
	string addr;
	unsigned age;
};

//合成默认构造函数
//返回地址  实质上不需要传入参数p  因为隐式调用this已经可以将信息返回
string Person::retAddr(struct Person &p) const	//注意  需要与声明保持一致  const必须加
{
	//return p.addr;
	return this->addr;
}

//定义read 和 print函数
istream &read(istream &is, Person &item)
{
	is >> item.personName >> item.addr >> item.age;
	return is;
}
ostream &print(ostream &os, const Person &item)
{
	os << item.personName << item.addr << item.age;
	return os;
}


void test_struct();

int main()
{
	test_struct();
	return 0;
}


void test_struct()
{
	//向类内添加
	Person per;
	//read(cin, per);	//不调用read函数对per进行初始化  使用默认构造函数，此时字符串被初始化为空  而unsigned 为任意值

	print(cout, per) << endl;
	//返回类内的数据
	cout << per.retName() << endl << per.retAddr(per);
	//测试构造函数
	Person wx("Wangxing", "鄂尔多斯市");
	Person guo("Guotaohong", "烟台市", 25);
	print(cout, wx) << endl;
	print(cout, guo) << endl;
	string tempAddr = "eeds";
	

}
