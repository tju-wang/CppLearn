#include <iostream>
using namespace std;

#include <string>
/*
?连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
?长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
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
			if (numY != 0)	//补全0
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
