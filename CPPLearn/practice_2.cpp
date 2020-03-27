#include <iostream>
using namespace std;
#include <string>
/*写出一个程序，接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写*/

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
//思路：先读取字符串与字符  然后统计