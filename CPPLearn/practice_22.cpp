#include <iostream>
using namespace std;

#include <string>
#include <vector>
//#include <map>

/*
实现删除字符串中出现次数最少的字符，若多个字符出现次数一样，则都删除。输出删除这些单词后的字符串，字符串中其它字符保持原来的顺序。
注意每个输入文件有多组输入，即多个字符串用回车隔开
*/



void PrintShortestString(string &str);
int main()
{
	string input;
	while (getline(cin, input))
	{
		PrintShortestString(input);
	}

	return 0;

}


void PrintShortestString(string &str)
{
	int cnt[26] = {0};
	for (auto it = str.begin(); it != str.end(); ++it)
	{
		cnt[(*it) - 'a']++;
	}
	int minVal = 0xFF;
	//寻找最小的
	vector<int> numm;
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] == 0)
		{
			cnt[i] = 0xFFFF;
			continue;
		}
			
		if (cnt[i] <= minVal)
		{
			if (cnt[i] == minVal)
				numm.push_back(i);
			else
			{
				minVal = cnt[i];
				numm.clear();
				numm.push_back(i);
			}
		}
	}
	//按照numm的结果删除字符
	if (numm.size() > 0)
	{
		for (auto it = numm.begin(); it != numm.end(); ++it)
		{
			char temp = (*it) + 'a';
			for (auto ip = str.begin(); ip != str.end(); ++ip)
			{
				if (temp == (*ip))
				{
					if (ip == str.end() - 1)
					{
						str.erase(ip);
						break;
					}
					str.erase(ip);
				}
			}
		}
	}
	cout << str << endl;
}

