#include <iostream>
using namespace std;
#include <vector>
#include <string>


/*
密码要求:
1.长度超过8位
2.包括大小写字母.数字.其它符号,以上四种至少三种
3.不能有相同长度超2的子串重复

*/

bool isPass(string &str);
bool isContinueStr(string &str);
bool check(string &str);
int main()
{
	string input;
	bool ret = false;
	while (getline(cin, input))
	{
		 ret = check(input);
		 if (ret == true)
			 cout << "OK" << endl;
		 else
			 cout << "NG" << endl;
	}
	return 0;
}

bool check(string &str)
{
	if (str.length() <= 8)
	{
		return false;
	}
	return isPass(str) && isContinueStr(str);
}

bool isPass(string &str)
{
	bool cnt[4] = {false};
	int len = str.size();

	for (int i = 0; i < len; ++i)
	{
		if ( (str[i] >= 'a' && str[i] <= 'z'))
		{
			cnt[0] = true;
		}
		else if ( (str[i] >= 'A' && str[i] <= 'Z'))
		{
			cnt[1] = true;
		}
		else if ( (str[i] >= '0' && str[i] <= '9'))
		{
			cnt[2] = true;
		}
		else
		{
			cnt[3] = true;
		}
	}
	int temp = 0;
	for (int k = 0; k < 4; k++)
	{
		temp += (int)cnt[k];
	}
	if (temp > 2)
		return true;
	else
		return false;
}
bool isContinueStr(string &str)
{
	vector<string> vec;
	string temp;
	for (unsigned i = 0; i < str.size()-3; ++i)
	{
		temp = str.substr(i, 3);
		vec.push_back(temp);
		temp.clear();
	}
	for (unsigned i = 0; i < vec.size(); ++i)
	{
		temp = vec[i];
		int cnt = 0;
		for (unsigned k = 0; k < vec.size() && cnt<2; ++k)
		{
			if (vec[i] == vec[k])
				cnt++;
		}
		if (cnt == 2)
			return false;
	}
	return true;
}