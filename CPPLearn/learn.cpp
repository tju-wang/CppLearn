#include <iostream>
using namespace std;
#include <string>
#include <vector>

//ѧϰsprintf  ��������ʾ sprintf���ǰ�ȫ�Ĳ���  ������to_string����ȽϺ�

struct Sales_data
{
	std::string isbn() const { return bookNo; }    //ע��˴���const  �����޸�thisָ�������
	Sales_data& combine(const Sales_data&);    //û��const  ��ʱ����ͨ��thisָ���޸��������
	double avg_price() const;
	string bookNo;
	unsigned unit_sold;
	double revenue;
};
struct Sales_data s1 = { "ISN0026145", 1, 23.5 };

struct Person {
	//�������캯��
	Person() = default;
	Person(const string &s1, const string &s2) : personName(s1), addr(s2) {};
	Person(const string &s1, const string &s2,const unsigned &k) : personName(s1), addr(s2),age(k) {};
	//��ӳ�Ա����
	string retName() const { return personName; }
	string retAddr(struct Person &p) const;
	string personName;
	string addr;
	unsigned age;
};

//�ϳ�Ĭ�Ϲ��캯��
//���ص�ַ  ʵ���ϲ���Ҫ�������p  ��Ϊ��ʽ����this�Ѿ����Խ���Ϣ����
string Person::retAddr(struct Person &p) const	//ע��  ��Ҫ����������һ��  const�����
{
	//return p.addr;
	return this->addr;
}

//����read �� print����
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
	//ò��  vs2015��֧�ַ�Χfor���
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
		while (cin >> istring)	//����ʹ�ý�����  ctrl + z ����������
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
	//���������
	Person per;
	//read(cin, per);
	
	print(cout,per)<<endl;
	//�������ڵ�����
	cout << per.retName() << endl << per.retAddr(per);
	//���Թ��캯��
	Person wx("Wangxing", "������˹��");
	Person guo("Guotaohong", "��̨��",25);
	print(cout,wx) << endl;
	print(cout,guo) << endl;
}
