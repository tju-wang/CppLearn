#include <iostream>
using namespace std;

#include <string>


/*
对输入的字符串进行加解密，并输出。
2加密方法为：
当内容是英文字母时则用该英文字母的后一个字母替换，同时字母变换大小写,如字母a时则替换为B；字母Z时则替换为a；
当内容是数字时则把该数字加1，如0替换1，1替换2，9替换0；
其他字符不做变化。
3、解密方法为加密的逆过程。
*/

void Encrypt(string str, string &strOut);
void unEncrypt(string str, string &strOut);
int main()
{
	string str1, str2,output;
	while (getline(cin, str1))
	{
		Encrypt(str1, output);
		cout << output << endl;

		if (getline(cin, str2))
		{
			unEncrypt(str2, output);
			cout << output << endl;
		}
	}


	return 0;
}
//加密函数
void Encrypt(string str,string &strOut)
{
	for (auto it = str.begin(); it != str.end(); ++it)
	{
		if (isalnum((*it)))
		{
			if (isdigit((*it)))
			{
				if (*it == '9')
					(*it) = '0';
				else
				{
					(*it)++;
				}
			}
			else if (islower((*it)))
			{
				if ((*it == 'z'))
					*it = 'a';
				else
				{
					(*it)++;
				}
				*it = toupper(*it);
			}
			else if (isupper((*it)))
			{
				if (*it == 'Z')
					(*it) = 'A';
				else
				{
					(*it)++;
				}
				*it = tolower(*it);
			}
		}
	}
	strOut = str;

}


void unEncrypt(string str, string &strOut)
{
	for (auto it = str.begin(); it != str.end(); ++it)
	{
		if (isalnum((*it)))
		{
			if (isdigit((*it)))
			{
				if (*it == '0')
					(*it) = '9';
				else
				{
					(*it)--;
				}
			}
			else if (islower((*it)))
			{
				if ((*it == 'a'))
					*it = 'z';
				else
				{
					(*it)--;
				}
				*it = toupper(*it);
			}
			else if (isupper((*it)))
			{
				if (*it == 'A')
					(*it) = 'Z';
				else
				{
					(*it)--;
				}
				*it = tolower(*it);
			}
		}
	}

	strOut = str;
}
