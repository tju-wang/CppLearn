// CPPLearn.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*�����ַ������һ�����ʵĳ��ȣ������Կո����*/
//#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
#include <string>

int main()
{
	string str;
	int count = 0, i = 0;
	if (getline(cin, str))
	{
		while (str[i] != '\0')
		{
			if (str[i] == ' ')
				count = 0;
			else
				++count;
			i++;
		}
	}
	cout << count << endl;

	return 0;
}
