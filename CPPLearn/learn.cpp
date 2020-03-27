#include <iostream>
using namespace std;
#include <string>
#include <vector>

//学习sprintf  编译器提示 sprintf不是安全的操作  还是用to_string代替比较好

struct Sales_data
{
	std::string isbn() const { return bookNo; }    //注意此处的const  是在修改this指针的类型
	Sales_data& combine(const Sales_data&);    //没有const  此时可以通过this指针修改类的内容
	double avg_price() const;
	string bookNo;
	unsigned unit_sold;
	double revenue;
};
struct Sales_data s1 = { "ISN0026145", 1, 23.5 };

struct Person {
	//新增构造函数
	Person() = default;
	Person(const string &s1, const string &s2) : personName(s1), addr(s2) {};
	Person(const string &s1, const string &s2,const unsigned &k) : personName(s1), addr(s2),age(k) {};
	//添加成员函数
	string retName() const { return personName; }
	string retAddr(struct Person &p) const;
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


void test_sprintf();
void test_struct();

int main()
{
	//test_sprintf();
	//string mystring("cdsiao");
	//int num = mystring.size();
	/*
	//貌似  vs2015不支持范围for语句
	for (auto c = mystring)
	{
		//c = 'X';
		cout << c << endl;
	}
	cout << mystring;
	*/
	/*
		vector<string> My_vector;
		string istring;
		while (cin >> istring)	//可以使用结束符  ctrl + z 来结束输入
		{
			My_vector.push_back(istring);
		}
		for (size_t i = 0; i < My_vector.size(); i++)
			for (size_t j = 0; j < My_vector[i].length(); j++)
			{
				My_vector[i][j] = toupper(My_vector[i][j]);
			}
		for (size_t i = 0; i < My_vector.size(); i++)
		{
			cout << My_vector[i] << endl;
		}

	*/
	test_struct();
		return 0;
}

//void test_sprintf()
//{
//	char str[100];
//	sprintf(str,"%5.3f  %d % 8x ", 3.1415926, 26, 13);
//	cout << str << endl;
//}

void test_struct()
{
	//向类内添加
	Person per;
	//read(cin, per);
	
	print(cout,per)<<endl;
	//返回类内的数据
	cout << per.retName() << endl << per.retAddr(per);
	//测试构造函数
	Person wx("Wangxing", "鄂尔多斯市");
	Person guo("Guotaohong", "烟台市",25);
	print(cout,wx) << endl;
	print(cout,guo) << endl;
}
