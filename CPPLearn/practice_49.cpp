#include <iostream>
using namespace std;

#include <string>
#include <algorithm>

/*
计算字符串最后一个单词的长度，单词以空格隔开。
输入描述：一行字符串，非空，长度小于5000。
输出描述：整数N，最后一个单词的长度。
示例1
输入：hello world
输出：5
*/

int main()
{
	string input;
	while (getline(cin, input))
	{
		reverse(input.begin(), input.end());
		int cnt = 0;
		for (auto it = input.begin(); it != input.end(); ++it)
		{
			if ((*it) != ' ')
				cnt++;
			else
			{
				break;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}