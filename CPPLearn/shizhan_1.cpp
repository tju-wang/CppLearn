#include <iostream>
using namespace std;

#include <string>
#include <sstream>
/*
输入一个字符串  识别字符串中运算式子的结果  有符号 0-9 和 + - 保证不会出现+ - 位于字符串首或末
*/

int isPlusOrNot(char ch);

int main()
{
	string str;
	string data;
	int ret = 0;
	int fu = 1;
	while (getline(cin, str))
	{
		int i = 0;
		while (str[i] != '\0')
		{
			int style = isPlusOrNot(str[i]);
			if (style == 2)	//是数字
				data.push_back(str[i]);
			else if (style == 1)	//加号
			{
				stringstream ss(data);
				int temp = 0;
				ss>>temp;
				if (fu)
					ret += temp;
				else
				{
					ret -= temp;
				}
				fu = 1;
				data.clear();
			}
			else if (style == 0)
			{
				stringstream ss(data);
				int temp = 0;
				ss >> temp;
				if (fu)
					ret += temp;
				else
				{
					ret -= temp;
				}
				fu = 0;
				data.clear();
			}
			else
			{
				cout << "error" << endl;
				break;
			}
			++i;
		}
		if (data.size() != 0)
		{
			stringstream ss(data);
			int temp = 0;
			ss >> temp;
			if (fu)
				ret += temp;
			else
			{
				ret -= temp;
			}
			fu = 1;
			data.clear();
		}
		cout << ret << endl;
		ret = 0;
	}

	return 0;
}
int isPlusOrNot(char ch)
{
	if (ch >= '0' && ch <= '9')
		return 2;	//不是加减符号
	if (ch == '+')
		return 1;
	if (ch == '-')
		return 0;
	else
	{
		return 3;
	}
}
