#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

/*
对字符串中的所有单词进行倒排。

说明：

1、每个单词是以26个大写或小写英文字母构成；

2、非构成单词的字符均视为单词间隔符；

3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；

4、每个单词最长20个字母；
*/

bool isLetter(char ch);

int main()
{
	string str, temp;
	vector<string> arr;
	if (getline(cin, str))
	{
		str.push_back(' ');	//在后边放一个空格
		for (int i = 0; i < str.size(); ++i)
		{
			if (isLetter(str[i]))
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
		cout << endl;

	}
	return 0;
}
bool isLetter(char ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return true;
	return false;
}

