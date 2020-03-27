#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <sstream>

/*
开发一个坐标计算工具， A表示向左移动，D表示向右移动，W表示向上移动，S表示向下移动。
从（0,0）点开始移动，从输入字符串里面读取一些坐标，并将最终输入结果输出到输出文件里面。

！！！很奇怪！！  本地和测试可以通过，但是提交后却是0%
是不是运行时间限制的问题？？

按照题目，需要支持多组测试数据！！
*/

int isCmd(string &str, int (*pos)[2]);
int move(string &in);
int main()
{

	string in;
	while (cin >> in)
	{
		move(in);
	}
	return 0;

}
//判断是不是指令格式  返回对应的操作，并去掉字母
int isCmd(string &str, int(*pos)[2])
{  
	int ret = 0;
	int numm = 0;
	if (str.size() < 0 || str.size() > 3)
	{
		return 0;
	}
	char ch = str[0];
	str.erase(str.begin());
	for (auto itt = str.begin(); itt != str.end(); ++itt)
	{
		if ((*itt) < '0' || (*itt) > '9')
			return 0;
	}
	stringstream ss(str);
	ss >> numm;
	if (ch == 'A')
	{
		(*pos)[0] -= numm;

	}
	else if (ch == 'D')
	{
		(*pos)[0] += numm;
	}
	else if (ch == 'W')
	{
		(*pos)[1] += numm;
	}
	else if (ch == 'S')
	{
		(*pos)[1] -= numm;
	}
	//判断剩余部分是否是两位数字

	return 1;
}

int move(string &in)
{
	//按照分号来区分
	string temp;
	int pos[2] = { 0,0 };
	vector<string> input;
	int cmd = 0;
	int numm = 0;
	for (string::iterator it = in.begin(); it != in.end(); ++it)
	{
		if ((*it) != ';')
		{
			temp.push_back(*it);
		}
		else
		{
			isCmd(temp,&pos);
			temp.clear();
		}
	}
	cout << pos[0] << ',' << pos[1] << endl;
	return 0;
}



/*

int isCmd(string &str);
int move(string &in);
int main()
{
	
	string in;
	while (cin >> in)
	{
		move(in);
		return 0;
	}
		
	

	return 0;

}
//判断是不是指令格式  返回对应的操作，并去掉字母
int isCmd(string &str)
{
	int ret = 0;
	if (str.size() < 0 || str.size() > 3)
	{
		return 0;
	}
	
	if (str[0] == 'A')
	{
		ret = 1;
		str.erase(str.begin());
	}
	else if (str[0] == 'D')
	{
		ret = 2;
		str.erase(str.begin());
	}
	else if (str[0] == 'W')
	{
		ret = 3;
		str.erase(str.begin());
	}
	else if (str[0] == 'S')
	{
		ret = 4;
		str.erase(str.begin());
	}
	//判断剩余部分是否是两位数字
	for (auto itt = str.begin(); itt != str.end(); ++itt)
	{
		if ((*itt) < '0' || (*itt) > '9')
			return 0;
	}
	return ret;
}

int move(string &in)
{
	//按照分号来区分
	string temp;
	int pos[2] = { 0,0 };
	vector<string> input;
	for (string::iterator it = in.begin(); it != in.end(); ++it)
	{
		if ((*it) != ';' && isalnum((*it)))
		{
			temp.push_back(*it);
		}
		else
		{
			if (temp.size() != 0)
			{
				input.push_back(temp);
			}
			temp.clear();
		}
	}
	for (auto ip = input.begin(); ip != input.end(); ++ip)
	{
		int cmd = 0;
		int numm = 0;
		cmd = isCmd(*ip);
		if (cmd != 0)
		{
			stringstream ss(*ip);
			ss >> numm;
			if (cmd == 1)
			{
				pos[0] -= numm;
			}
			else if (cmd == 2)
			{
				pos[0] += numm;
			}
			else if (cmd == 3)
			{
				pos[1] += numm;
			}
			else if (cmd == 4)
			{
				pos[1] -= numm;
			}

		}

	}
	cout << pos[0] << ',' << pos[1] << endl;
	return 0;
}
*/