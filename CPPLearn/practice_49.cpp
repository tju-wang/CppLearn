#include <iostream>
using namespace std;

#include <string>
#include <algorithm>

/*
�����ַ������һ�����ʵĳ��ȣ������Կո������
����������һ���ַ������ǿգ�����С��5000��
�������������N�����һ�����ʵĳ��ȡ�
ʾ��1
���룺hello world
�����5
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