#include <iostream>
using namespace std;
#include <algorithm>
#include <string>

/*
Lily使用的图片包括"A"到"Z"、"a"到"z"、"0"到"9"。输入字母或数字个数不超过1024。
*/

int  main()
{
	string input;
	while (getline(cin, input))
	{
		sort(input.begin(), input.end());
		cout << input << endl;
	}
	return 0;
}

