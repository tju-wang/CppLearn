#include <iostream>
using namespace std;
#include <string>

/*
编写一个函数，计算字符串中含有的不同字符的个数。字符在ACSII码范围内(0~127)，换行表示结束符，不算在字符里。不在范围内的不作统计。
*/

bool isHere(string &str, char ch);
int main()
{
	string str;
	string ret;
	if (getline(cin, str))
	{
		if (str.size() == 0)
		{
			cout << 0 << endl;
			return 0;
		}

		for (int i = 0; i < str.size(); ++i)
		{
			if (!isHere(ret, str[i]))
				ret.push_back(str[i]);
		}
		cout << ret.size() << endl;
		
		
	}
	return 0;
}

bool isHere(string &str, char ch)
{
	if (str.size() == 0)
		return false;
	for (string::iterator it = str.begin(); it != str.end(); ++it)
	{
		if (ch == (*it))
			return true;
	}
	return false;
}

