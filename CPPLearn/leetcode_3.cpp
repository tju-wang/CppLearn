#include <iostream>
using namespace std;

#include <string>


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ret = 0;
		int s_size = s.size();
		if (s_size <= 1)
			return s_size;
		bool flag = false;
		for (int i = 0; i<s_size && flag == false; ++i)
		{
			for (int j = i+1; j<s_size; ++j)
			{
				char ch = s[j];
				string sub = s.substr(i, j-i);
				flag = false;
				if (sub.find(ch) != sub.npos)
				{
					if (sub.size() > ret)
						ret = sub.size();
					//flag = true;
					break;
				}
				if (j == s_size - 1)
				{
					flag = true;
					if(ret < sub.size() + 1)
						ret = sub.size() + 1;
				}
					
			}

		}
		return ret;
	}
};



//思路：滑动指针法，查看子字符串中  是否含有下一个字符

int main()
{
	Solution su;
	while (1)
	{
		string input;
		cin >> input;

		cout << su.lengthOfLongestSubstring(input) << endl;
	}
	
	return 0;
}

