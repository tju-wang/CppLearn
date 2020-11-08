// CppPrimer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;




istream& func8_1(istream &is)
{
	std::string buf;
	while (is >> buf)	//���������� badbit  failbit �� eofbit����λʱ�������״̬��������ʧ��
		std::cout << buf << std::endl;
	is.clear();
	return is;
}
/*��pathָ�����ļ����ݶ�ȡ��vec���У�ÿһ����Ϊһ��������Ԫ��*/
void func8_4(string path, string pathOut,vector<string> &vec)
{
	ifstream fstr(path);	//���ļ�
	ofstream fout(pathOut,ofstream::app);	//����д���ļ�ģʽ  appָ��ÿ��д����ǰ��ָ�����ļ�ĩβ�����Ա����ļ�֮ǰ������
	if (!fstr)
	{
		cout << "open file failed." << endl;
	}
	string s;
	while (getline(fstr,s))
	{
		vec.push_back(s);
		fout << s << endl;
		s.clear();
	}
	fstr.close();	//�ر��ļ�
}
/*ʹ��istringstream��ȡvector<string>�е�����*/
void func8_10(vector<string> &vec)
{
	istringstream str;
	string s;
	for (auto it : vec)
	{
		str.str(it);
		while (str >> s)
		{
			cout << s << endl;
		}
		str.clear();	//һ��Ҫ���  ������ѭ���ڲ�����sstream
	}
}



void test_func8_1()
{
	istream& is = func8_1(std::cin);
	std::cout << is.rdstate() << std::endl;
}

void tset_func8_4()
{
	vector<string> str;
	func8_4("D:/CProgram/CppLearn/CppPrimer/file/read_file.txt","D:/CProgram/CppLearn/CppPrimer/file/out_file.txt",str);
	for (auto it = str.begin();it != str.end(); ++it)
	{
		cout << *it << endl;
	}
	func8_10(str);
}

int main()
{

	tset_func8_4();
	return 0;
}

