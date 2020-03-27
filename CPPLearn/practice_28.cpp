#include <iostream>
using namespace std;

#include <string>
#include <algorithm>
/*
将输入的两个字符串合并。
对合并后的字符串进行排序，要求为：下标为奇数的字符和下标为偶数的字符分别从小到大排序。
这里的下标意思是字符在字符串中的位置。
*/
int returnkey(char &ch);
int main()
{
	string str1, str2;
	while (cin>>str1 && cin >> str2)
	{
		string sum = str1;
		sum += str2;	//合并
		str1.clear();
		str2.clear();
		int len = sum.length();
		for (int i = 0; i < len; ++i)
		{
			if (i % 2 == 0)
			{
				str1.push_back(sum[i]);
			}
			else
			{
				str2.push_back(sum[i]);
			}
		}
		sort(str1.begin(), str1.end());
		sort(str2.begin(), str2.end());
		for (int i = 0; i < len; ++i)	//对字符串排序后进行更新
		{
			if (i % 2 == 0)
			{
				sum[i] = str1[i / 2];
			}
			else
			{
				sum[i] = str2[i / 2];
			}
		}
		//对sum中的每一个字符进行处理
		for (auto it = sum.begin(); it != sum.end(); ++it)
		{
			char ch = (*it);
			char num = 0;
			bool temp[4];
			if (returnkey(ch)!=0)
			{
				ch = ch & 0xF;
				//ch = (~ch) & 0xF;
				for (int k = 0; k < 4; ++k)
				{
					temp[3 - k] = (ch & (1 << k));	//实现倒序
				}
				num = (1 << 3)*temp[3] + (1 << 2)*temp[2] + (1 << 1)*temp[1] + (1 << 0)*temp[0];				
				if ((int)num > 9)
				{
					ch = num - 10 + 'A';
				}
				else
				{
					ch = num + '0';
				}
				(*it) = (char)ch;
			}
		}
		cout << sum << endl;
	}
	return 0;
}

int returnkey(char &ch)
{
	if (ch >= '0' && ch <= '9')
	{
		ch = ch - '0';
		return 1;
	}
	else if (ch >= 'a' && ch <= 'f')
	{
		ch = ch - 'a' + 10;
		return 2;
	}
	else if (ch >= 'A' && ch <= 'F')
	{
		ch =ch - 'A' + 10;
		return 3;
	}
	else
	{
		return 0;
	}
}