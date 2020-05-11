#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <algorithm>

/*
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

思路：使用递归实现遍历
或是带记忆的dfs

*/


//输入string  输出所有组合的vector

class Solution {
public:
	vector<string> Permutation(string str) {
		if (str.empty())
			return ans;
		chang(str, 0, str.size());
		//去重操作  1.先排序  2.unique函数将重复的元素放到vector末尾  3.erase重复的数
		sort(ans.begin(), ans.end());
		auto it = unique(ans.begin(), ans.end());
		ans.erase(it, ans.end());
		return ans;

	}
	void chang(string &str, int start, int len) {
		if (start == len)	//交换到最后
			ans.push_back(str);
		//
		for (int i = start; i < len; i++) {
			swap(str[start], str[i]);
			chang(str, start + 1, len);	//start+1
			swap(str[start], str[i]);
		}
	}

	vector<string> ans;
};

int main()
{
	string input;
	while (getline(cin, input))
	{
		string temp;
		vector<string> vec;
		Solution su;
		vec = su.Permutation(input);
	}

	return 0;
}

