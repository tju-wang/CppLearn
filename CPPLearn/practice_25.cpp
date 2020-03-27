#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

/*
编写一个程序，将输入字符串中的字符按如下规则排序。
规则 1 ：英文字母从 A 到 Z 排列，不区分大小写。
如，输入： Type 输出： epTy
规则 2 ：同一个英文字母的大小写同时存在时，按照输入顺序排列。
如，输入： BabA 输出： aABb
规则 3 ：非英文字母的其它字符保持原来的位置。


如，输入： By?e 输出： Be?y
思路：
1.对于字母位置做标记  并提取
2.字母排序
3.排序后插入原数组中
*/

bool cmp(char ch1, char ch2);
void OutputResult(string &str);

int main()
{
	string input;
	while (getline(cin, input))
	{
		OutputResult(input);
	}
	return 0;
}

void OutputResult(string &str)
{
	int strLen = str.length();
	vector<bool> flag;
	string alphaStr;
	for (auto it = str.begin(); it != str.end(); ++it)
	{
		if (isalpha((*it)))
		{
			flag.push_back(true);
			alphaStr.push_back((*it));
		}
		else
		{
			flag.push_back(false);
		}
	}
	stable_sort(alphaStr.begin(), alphaStr.end(), cmp);
	//然后将排序后的结果  放入原来的字符串
	auto ip = alphaStr.begin();
	for (auto it = str.begin(); it != str.end() && ip!=alphaStr.end(); ++it)
	{
		if (isalpha(*it))
		{
			(*it) = (*ip);
			ip++;
		}
	}
	cout << str << endl;

}

bool cmp(char ch1,char ch2)
{
	ch1 = toupper(ch1);
	ch2 = toupper(ch2);
	
	return ch1<ch2 ? true:false;
}