#include <iostream>
using namespace std;
#include <string>

/*
��дһ�������������ַ����к��еĲ�ͬ�ַ��ĸ������ַ���ACSII�뷶Χ��(0~127)�����б�ʾ���������������ַ�����ڷ�Χ�ڵĲ���ͳ�ơ�
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

