#include <iostream>
using namespace std;
#include <string>
/*д��һ�����򣬽���һ������ĸ��������ɵ��ַ�������һ���ַ���Ȼ����������ַ����к��и��ַ��ĸ����������ִ�Сд*/

int main()
{
	string str;
	char ch,ch1;

	if (getline(cin, str))
	{
		cin >> ch;
		int i = 0,count = 0;
		if (ch <= 'Z')
			ch1 = ch + ('a' - 'A');
		else    {
			ch1 = ch - ('a' - 'A');
		}
		while (str[i] != '\0')
		{
			if (str[i] == ch || str[i] == ch1)
				++count;
			++i;

		}
		cout << count << endl;

	}
	return 0;
}
//˼·���ȶ�ȡ�ַ������ַ�  Ȼ��ͳ��