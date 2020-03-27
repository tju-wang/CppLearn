#include <iostream>
using namespace std;

#include <string>


/*
��������ַ������мӽ��ܣ��������
2���ܷ���Ϊ��
��������Ӣ����ĸʱ���ø�Ӣ����ĸ�ĺ�һ����ĸ�滻��ͬʱ��ĸ�任��Сд,����ĸaʱ���滻ΪB����ĸZʱ���滻Ϊa��
������������ʱ��Ѹ����ּ�1����0�滻1��1�滻2��9�滻0��
�����ַ������仯��
3�����ܷ���Ϊ���ܵ�����̡�
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
//���ܺ���
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
