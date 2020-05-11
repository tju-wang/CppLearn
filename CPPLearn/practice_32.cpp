#include <iostream>
using namespace std;

#include <string>

/*
有一种技巧可以对数据进行加密，它使用一个单词作为它的密匙。下面是它的工作原理：首先，选择一个单词作为密匙，如TRAILBLAZERS。
如果单词中包含有重复的字母，只保留第1个，其余几个丢弃。现在，修改过的那个单词属于字母表的下面，如下所示：

字符串加密问题
输入秘钥与密文   输出加密后的结果
*/

void ChangeKey(string &key, bool(*chart)[26]);

int main()
{
	string key, secret;
	while (getline(cin, key))
	{
		getline(cin, secret);
		//根据秘钥  创建要替换的字母表
		bool chart[26] = { false };
		char secretChart[26] = { 'A' };
		ChangeKey(key, &chart);
		for (auto it = key.begin(); it != key.end() && key.size() <= 26; ++it)
		{
			secretChart[(it)-key.begin()] = (*it);
		}
		int j = 0;
		for (int i = key.size(); i < 26; ++i)
		{
			while (chart[j] == true)
				++j;
			secretChart[i] = 'A' + j;
			++j;
		}
		//开始替换密文部分
		string ret;
		char temp;
		for (auto it = secret.begin(); it != secret.end(); ++it)
		{
			if (isalpha(*it))
			{
				if (islower((*it)))
				{
					temp = secretChart[(*it) - 'a'];
					ret.push_back(tolower(temp));
				}
				else if (isupper(*it))
				{
					temp = secretChart[(*it) - 'A'];
					ret.push_back(toupper(temp));
				}
			}
			else
			{
				ret.push_back((*it));
			}
		}
		cout << ret << endl;
		
	}

	return 0;
}

void ChangeKey(string &key,bool (*chart)[26])
{
	//先去重
	for (auto it = key.begin(); it != key.end(); ++it)
	{
		if (islower((*it)))
		{
			if ((*chart)[(*it) - 'a'] == false)
				(*chart)[(*it) - 'a'] = true;
			else
			{
				if (it != key.end() - 1)
					it = key.erase(it)-1;
				else
				{
					it = key.erase(it)-1;
					break;
				}
			}

		}
		else if (isupper((*it)))
		{
			if ((*chart)[(*it) - 'A'] == 0)
				(*chart)[(*it) - 'A'] = 1;
			else
			{
				if (it != key.end() - 1)
					it = key.erase(it) - 1;
				else
				{
					it = key.erase(it)-1;
					break;
				}
			}
		}
	}
}