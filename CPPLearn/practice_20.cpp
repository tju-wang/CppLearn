#include <iostream>
using namespace std;
#include <string>
#include <vector>


/*
���������������зǳ���Ҫ�Ķ��������ǵ���ôһ�㲻��˵�����ܾ�ȫ�����ˡ��۹���. ������Ԩ��Ҫ������֮���ټ�һ�����룬��Ȼ�򵥵�Ҳ��ȫ��
����Ԩ��ԭ��һ��BBS�ϵ�����Ϊzvbo9441987,Ϊ�˷�����䣬��ͨ��һ���㷨���������任��YUANzhi1987������������������ֺͳ�����ݣ�
��ô���������ˣ����ҿ�����Ŀ�ŵ��ط������۵ĵط�����������֪�����������롣
1--1�� abc--2, def--3, ghi--4, jkl--5, mno--6, pqrs--7, tuv--8 wxyz--9, 0--0
*/
char CoverSec(char ch);
void sec(string &str, string &out);
int main()
{
	string input;
	string out;
	while (getline(cin, input))
	{
		sec(input, out);
		cout << out << endl;
	}
	return 0;
}

void sec(string &str, string &out)
{
	int len = str.length();
	for (int i = 0; i < len; ++i)
	{
		out.push_back(CoverSec(str[i]));
	}
}

char CoverSec(char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch;
	if (ch >= 'a' && ch <= 'z')
	{
		//�����ж��޸�
		if (ch >= 'a' && ch <= 'c')
			return '2';
		if (ch >= 'd' && ch <= 'f')
			return '3';
		if (ch >= 'g' && ch <= 'i')
			return '4';
		if (ch >= 'j' && ch <= 'l')
			return '5';
		if (ch >= 'm' && ch <= 'o')
			return '6';
		if (ch >= 'p' && ch <= 's')
			return '7';
		if (ch >= 't' && ch <= 'v')
			return '8';
		if (ch >= 'w' && ch <= 'z')
			return '9';
	}
	if (ch >= 'A' && ch <= 'Z')
	{
		//ת��
		ch = ch + ('a' - 'A');	//ת��ΪСд
		if (ch != 'z')
		{
			ch++;
			return ch;
		}
		else
		{
			return 'a';
		}
	}
	return -1;
}