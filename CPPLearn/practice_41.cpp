#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
#include <vector>
/*
给出一个名字，该名字有26个字符串组成，定义这个字符串的“漂亮度”是其所有字母“漂亮度”的总和。
每个字母都有一个“漂亮度”，范围在1到26之间。没有任何两个字母拥有相同的“漂亮度”。字母忽略大小写。
给出多个名字，计算每个名字最大可能的“漂亮度”。
思路：实质上需要统计出出现次数最多的字母，其漂亮度为26  然后依次是 25  24  ...  最后和相加
*/
int CalcBeautyNum(string &str);


int main()
{
	int num;
	while (cin >> num)
	{
		string str;
		for (int i = 0; i < num; ++i)
		{
			cin >> str;
			cout << CalcBeautyNum(str) << endl;
			str.clear();
		}
	}


	return 0;
}

int CalcBeautyNum(string &str)
{
	vector<int> flag(26,0);
	for (auto it = str.begin(); it != str.end(); ++it)
	{
		flag[(tolower(*it) - 'a')] ++;
	}
	sort(flag.begin(), flag.end());
	int ret = 0,N=26;
	for (int i = 25; i >= 0; --i)
	{
		if (flag[i] != 0)
		{
			ret = ret + flag[i] * N;
			N--;
		}
	}
	return ret;

}