#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
/*
��һ��Ӣ������Ե���Ϊ��λ�����ŷš����硰I am a boy���������ŷź�Ϊ��boy a am I��
���е���֮����һ���ո����������г���Ӣ����ĸ�⣬���ٰ��������ַ�
*/

int main()
{
	string str,temp;
	vector<string> arr;
	if (getline(cin, str))
	{
		str.push_back(' ');	//�ں�߷�һ���ո�
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