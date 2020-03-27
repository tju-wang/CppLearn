#include <iostream>
using namespace std;
#include <string>
#include <vector>




class Person {
	//�������캯��
public:
	//Person() = default;
	
	Person(const string &s1, const string &s2, const unsigned &k) : personName(s1), addr(s2), age(k) { cout << this->personName << endl << age << endl; };
	Person() : Person("", "", 0) {};	//ί�й��캯��
	Person(const string &s1, const string &s2) : Person(s1, s2, 0) { this->age = 26; };	//ί�й��캯�� ִ��˳��Ϊʹ��s1,s2,0�����������Ĺ��캯����֮����ִ��age=26�ĸ�ֵ����
	//��ӳ�Ա����
	string retName() const { return personName; }
	string retAddr(struct Person &p) const;
	friend istream &read(istream &is, Person &item);
	friend ostream &print(ostream &os, const Person &item);
private:
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


void test_struct();

int main()
{
	test_struct();
	return 0;
}


void test_struct()
{
	//���������
	Person per;
	//read(cin, per);	//������read������per���г�ʼ��  ʹ��Ĭ�Ϲ��캯������ʱ�ַ�������ʼ��Ϊ��  ��unsigned Ϊ����ֵ

	print(cout, per) << endl;
	//�������ڵ�����
	cout << per.retName() << endl << per.retAddr(per);
	//���Թ��캯��
	Person wx("Wangxing", "������˹��");
	Person guo("Guotaohong", "��̨��", 25);
	print(cout, wx) << endl;
	print(cout, guo) << endl;
	string tempAddr = "eeds";
	

}
