#include <iostream>
using namespace std;

#include <string>

/*
��һ�ּ��ɿ��Զ����ݽ��м��ܣ���ʹ��һ��������Ϊ�����ܳס����������Ĺ���ԭ�����ȣ�ѡ��һ��������Ϊ�ܳף���TRAILBLAZERS��
��������а������ظ�����ĸ��ֻ������1�������༸�����������ڣ��޸Ĺ����Ǹ�����������ĸ������棬������ʾ��

�ַ�����������
������Կ������   ������ܺ�Ľ��
*/

void ChangeKey(string &key, bool(*chart)[26]);

int main()
{
	string key, secret;
	while (getline(cin, key))
	{
		getline(cin, secret);
		//������Կ  ����Ҫ�滻����ĸ��
		bool chart[26] = { false };
		char secretChart[26] = { 'A' };
		ChangeKey(key, &chart);
		for (auto it = key.begin(); it != key.end() && key.size() <= 26; ++it)
		{
			secretChart[(it)-key.begin()] = (*it);
		}
		int j = 0;
		for (int i = key.size(); i < 26; ++i)
		{
			while (chart[j] == true)
				++j;
			secretChart[i] = 'A' + j;
			++j;
		}
		//��ʼ�滻���Ĳ���
		string ret;
		char temp;
		for (auto it = secret.begin(); it != secret.end(); ++it)
		{
			if (isalpha(*it))
			{
				if (islower((*it)))
				{
					temp = secretChart[(*it) - 'a'];
					ret.push_back(tolower(temp));
				}
				else if (isupper(*it))
				{
					temp = secretChart[(*it) - 'A'];
					ret.push_back(toupper(temp));
				}
			}
			else
			{
				ret.push_back((*it));
			}
		}
		cout << ret << endl;
		
	}

	return 0;
}

void ChangeKey(string &key,bool (*chart)[26])
{
	//��ȥ��
	for (auto it = key.begin(); it != key.end(); ++it)
	{
		if (islower((*it)))
		{
			if ((*chart)[(*it) - 'a'] == false)
				(*chart)[(*it) - 'a'] = true;
			else
			{
				if (it != key.end() - 1)
					it = key.erase(it)-1;
				else
				{
					it = key.erase(it)-1;
					break;
				}
			}

		}
		else if (isupper((*it)))
		{
			if ((*chart)[(*it) - 'A'] == 0)
				(*chart)[(*it) - 'A'] = 1;
			else
			{
				if (it != key.end() - 1)
					it = key.erase(it) - 1;
				else
				{
					it = key.erase(it)-1;
					break;
				}
			}
		}
	}
}