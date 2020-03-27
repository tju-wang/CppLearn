// CPPLearn.cpp : 定义控制台应用程序的入口点。
//

/*计算字符串最后一个单词的长度，单词以空格隔开*/
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
