#include <iostream>
using namespace std;
#include <string>
#include<vector>
#include <algorithm>

/*
给定n个字符串，请对n个字符串按照字典序排列，输入只包含大小写字母
思路：将输入的单词存入vector中 对string进行比大小

*/

bool cmp(string s1, string s2);

int main()
{
	int inputNum = 0;
	vector<string> input;
	string temp;
	cin >> inputNum;
	for (int i = 0; i < inputNum; ++i)
	{
		cin >> temp;		
		input.push_back(temp);
	}
	//处理字符串  对字符串进行排序
	sort(input.begin(), input.end(), cmp);
	for (auto i = input.begin(); i != input.end(); ++i)
	{
		cout << (*i) << endl;
	}
	return 0;
}

bool cmp(string s1, string s2)
{
	return s1 > s2 ? false : true;
}
