#include <iostream>
using namespace std;

#include <string>
/*
?���������ַ������밴����Ϊ8���ÿ���ַ�����������µ��ַ������飻
?���Ȳ���8���������ַ������ں��油����0�����ַ���������
*/

int main()
{
	string str1;
	for (int i = 0; i < 2; ++i)
	{
		if (getline(cin, str1))
		{
			int numS = (int)(str1.size() / 8);
			int numY = (int)(str1.size() % 8);
			if (numY != 0)	//��ȫ0
			{
				for (int i = 0; i < 8 - numY; ++i)
				{
					str1.push_back('0');
				}
				numS += 1;
			}
			for (int i = 0; i < numS; ++i)
			{
				for (int j = i * 8; j < (i * 8) + 8; j++)
				{
					cout << str1[j];
				}
				cout << endl;
			}
		
		}
	}
	return 0;
}
