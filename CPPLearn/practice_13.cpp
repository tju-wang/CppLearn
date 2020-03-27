#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
/*
将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am I”
所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符
*/

int main()
{
	string str,temp;
	vector<string> arr;
	if (getline(cin, str))
	{
		str.push_back(' ');	//在后边放一个空格
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] != ' ')
			{
				temp.push_back(str[i]);
			}
			else
			{
				arr.push_back(temp);
				temp.clear();
			}
		}
		reverse(arr.begin(), arr.end());
		for (int i = 0; i < arr.size(); ++i)
		{
			cout << arr[i];
			if (i != arr.size() - 1)
				cout << ' ';
		}

	}
	return 0;
}