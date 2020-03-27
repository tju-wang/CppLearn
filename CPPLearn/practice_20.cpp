#include <iostream>
using namespace std;
#include <string>
#include <vector>


/*
密码是我们生活中非常重要的东东，我们的那么一点不能说的秘密就全靠它了。哇哈哈. 接下来渊子要在密码之上再加一套密码，虽然简单但也安全。
假设渊子原来一个BBS上的密码为zvbo9441987,为了方便记忆，他通过一种算法把这个密码变换成YUANzhi1987，这个密码是他的名字和出生年份，
怎么忘都忘不了，而且可以明目张胆地放在显眼的地方而不被别人知道真正的密码。
1--1， abc--2, def--3, ghi--4, jkl--5, mno--6, pqrs--7, tuv--8 wxyz--9, 0--0
*/
char CoverSec(char ch);
void sec(string &str, string &out);
int main()
{
	string input;
	string out;
	while (getline(cin, input))
	{
		sec(input, out);
		cout << out << endl;
	}
	return 0;
}

void sec(string &str, string &out)
{
	int len = str.length();
	for (int i = 0; i < len; ++i)
	{
		out.push_back(CoverSec(str[i]));
	}
}

char CoverSec(char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch;
	if (ch >= 'a' && ch <= 'z')
	{
		//具体判断修改
		if (ch >= 'a' && ch <= 'c')
			return '2';
		if (ch >= 'd' && ch <= 'f')
			return '3';
		if (ch >= 'g' && ch <= 'i')
			return '4';
		if (ch >= 'j' && ch <= 'l')
			return '5';
		if (ch >= 'm' && ch <= 'o')
			return '6';
		if (ch >= 'p' && ch <= 's')
			return '7';
		if (ch >= 't' && ch <= 'v')
			return '8';
		if (ch >= 'w' && ch <= 'z')
			return '9';
	}
	if (ch >= 'A' && ch <= 'Z')
	{
		//转化
		ch = ch + ('a' - 'A');	//转化为小写
		if (ch != 'z')
		{
			ch++;
			return ch;
		}
		else
		{
			return 'a';
		}
	}
	return -1;
}