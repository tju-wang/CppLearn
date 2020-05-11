#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <algorithm>

/*
����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С�
���������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��

˼·��ʹ�õݹ�ʵ�ֱ���
���Ǵ������dfs

*/


//����string  ���������ϵ�vector

class Solution {
public:
	vector<string> Permutation(string str) {
		if (str.empty())
			return ans;
		chang(str, 0, str.size());
		//ȥ�ز���  1.������  2.unique�������ظ���Ԫ�طŵ�vectorĩβ  3.erase�ظ�����
		sort(ans.begin(), ans.end());
		auto it = unique(ans.begin(), ans.end());
		ans.erase(it, ans.end());
		return ans;

	}
	void chang(string &str, int start, int len) {
		if (start == len)	//���������
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

