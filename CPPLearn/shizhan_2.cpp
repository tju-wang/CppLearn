#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
/*
蛇形字符串问题 寻找字符串中的蛇形字符串
思路：
1.设置26个字母的标识 bool
2.寻找连续的最长的蛇形字符串  将字符串中的这些字符找出并删除
3.再次统计字母标识
*/
bool isHere(int num, string &str);
void StrState(bool *flag, string &str);
void findLongStr(bool *flag, int *pos, int *len);
void StrDelte(char ch, string &str);
void StrPrint(int pos, int len, string &str);

int main()
{
	string input;
	bool flag[26];
	int pos = 0, len = 0;
	for (int i = 0; i < 26; i++)
		flag[i] = false;
	bool stop = true;
	bool firstFlag = true;
	if (getline(cin, input))
	{
		StrState(flag, input);
		stop = false;
		for (int i = 0; i < 26; i++)
			stop |= flag[i];
		while (stop)
		{
			findLongStr(flag, &pos, &len);
			firstFlag = false;
			//输出  生成输出字符串
			StrPrint(pos, len, input);
			StrState(flag, input);
			stop = false;
			for (int i = 0; i < 26; i++)
				stop |= flag[i];
		}
		if (firstFlag) {
			cout << "Not Found" << endl;
			return 0;
		}
	}

	return 0;
}
//输入位置和长度  输出对应的字符串  并从字符串中删除对应的字符
void StrPrint(int pos,int len,string &str)
{
	//生成
	string pri;
	for (int i = 0; i < len; ++i)
	{
		char tempD = (char)(pos + 'A');
		char tempX = (tempD + ('a' - 'A'));
		pri.push_back(tempD);
		pri.push_back(tempX);
		StrDelte(tempD, str);
		StrDelte(tempX, str);
		pos++;
	}
	cout << pri << endl;
}
//删除字符串函数
void StrDelte(char ch, string &str)
{
	int pos = str.find_first_of(ch);
	if (pos != str.npos)	//删除操作
	{
		str.erase(str.begin() + pos);
	}
}


//寻找最长的连续蛇形字符串  返回位置和长度
void findLongStr(bool *flag,int *pos,int *len)
{
	vector<int> cntArr,posArr;
	int cnt = 0, tempPos = 0;
	for (int i = 0; i < 26; i++)
	{
		if (flag[i] == 1)
		{
			if (cnt == 0)
				tempPos = i;
			cnt++;
		}
		else
		{
			if (cnt)
			{
				cntArr.push_back(cnt);
				posArr.push_back(tempPos);
				cnt = 0; tempPos = 0;
			}
		}

	}
	//找出最大的cnt
	vector<int>::iterator it = max_element(cntArr.begin(),cntArr.end());
	*len = (*it);
	*pos = *(posArr.begin() + (it - cntArr.begin()));

}

void StrState(bool *flag, string &str)	//统计字符情况
{
	for (int i = 0; i < 26; ++i)
	{
		flag[i] = 0;
		if (isHere(i, str))
			flag[i] = 1;
	}
}
//查找字符串中字母的大写和小写是否存在  输入num = 0-25 (A-Z)
bool isHere(int num, string &str)
{
	char temp = (char)(num  + 'A');
	
	int ret = 1;
	ret = str.find_first_of(temp, 0);
	if (ret != str.npos)
	{
		ret = str.find_first_of((char)(temp+('a'-'A')), 0);
	}
	if (ret == str.npos)
		return false;
	else
	{
		return true;
	}
}
