#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

/*
���ַ����е����е��ʽ��е��š�

˵����

1��ÿ����������26����д��СдӢ����ĸ���ɣ�

2���ǹ��ɵ��ʵ��ַ�����Ϊ���ʼ������

3��Ҫ���ź�ĵ��ʼ������һ���ո��ʾ�����ԭ�ַ��������ڵ��ʼ��ж�������ʱ������ת����Ҳֻ�������һ���ո�������

4��ÿ�������20����ĸ��
*/

bool isLetter(char ch);

int main()
{
	string str, temp;
	vector<string> arr;
	if (getline(cin, str))
	{
		str.push_back(' ');	//�ں�߷�һ���ո�
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

