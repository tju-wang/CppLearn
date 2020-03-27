#include <iostream>
using namespace std;

#include <string>
#include <vector>
//#include <map>

/*
ʵ��ɾ���ַ����г��ִ������ٵ��ַ���������ַ����ִ���һ������ɾ�������ɾ����Щ���ʺ���ַ������ַ����������ַ�����ԭ����˳��
ע��ÿ�������ļ��ж������룬������ַ����ûس�����
*/



void PrintShortestString(string &str);
int main()
{
	string input;
	while (getline(cin, input))
	{
		PrintShortestString(input);
	}

	return 0;

}


void PrintShortestString(string &str)
{
	int cnt[26] = {0};
	for (auto it = str.begin(); it != str.end(); ++it)
	{
		cnt[(*it) - 'a']++;
	}
	int minVal = 0xFF;
	//Ѱ����С��
	vector<int> numm;
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] == 0)
		{
			cnt[i] = 0xFFFF;
			continue;
		}
			
		if (cnt[i] <= minVal)
		{
			if (cnt[i] == minVal)
				numm.push_back(i);
			else
			{
				minVal = cnt[i];
				numm.clear();
				numm.push_back(i);
			}
		}
	}
	//����numm�Ľ��ɾ���ַ�
	if (numm.size() > 0)
	{
		for (auto it = numm.begin(); it != numm.end(); ++it)
		{
			char temp = (*it) + 'a';
			for (auto ip = str.begin(); ip != str.end(); ++ip)
			{
				if (temp == (*ip))
				{
					if (ip == str.end() - 1)
					{
						str.erase(ip);
						break;
					}
					str.erase(ip);
				}
			}
		}
	}
	cout << str << endl;
}

