#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <sstream>

/*
����һ��������㹤�ߣ� A��ʾ�����ƶ���D��ʾ�����ƶ���W��ʾ�����ƶ���S��ʾ�����ƶ���
�ӣ�0,0���㿪ʼ�ƶ����������ַ��������ȡһЩ���꣬�����������������������ļ����档

����������֣���  ���غͲ��Կ���ͨ���������ύ��ȴ��0%
�ǲ�������ʱ�����Ƶ����⣿��

������Ŀ����Ҫ֧�ֶ���������ݣ���
*/

int isCmd(string &str, int (*pos)[2]);
int move(string &in);
int main()
{

	string in;
	while (cin >> in)
	{
		move(in);
	}
	return 0;

}
//�ж��ǲ���ָ���ʽ  ���ض�Ӧ�Ĳ�������ȥ����ĸ
int isCmd(string &str, int(*pos)[2])
{  
	int ret = 0;
	int numm = 0;
	if (str.size() < 0 || str.size() > 3)
	{
		return 0;
	}
	char ch = str[0];
	str.erase(str.begin());
	for (auto itt = str.begin(); itt != str.end(); ++itt)
	{
		if ((*itt) < '0' || (*itt) > '9')
			return 0;
	}
	stringstream ss(str);
	ss >> numm;
	if (ch == 'A')
	{
		(*pos)[0] -= numm;

	}
	else if (ch == 'D')
	{
		(*pos)[0] += numm;
	}
	else if (ch == 'W')
	{
		(*pos)[1] += numm;
	}
	else if (ch == 'S')
	{
		(*pos)[1] -= numm;
	}
	//�ж�ʣ�ಿ���Ƿ�����λ����

	return 1;
}

int move(string &in)
{
	//���շֺ�������
	string temp;
	int pos[2] = { 0,0 };
	vector<string> input;
	int cmd = 0;
	int numm = 0;
	for (string::iterator it = in.begin(); it != in.end(); ++it)
	{
		if ((*it) != ';')
		{
			temp.push_back(*it);
		}
		else
		{
			isCmd(temp,&pos);
			temp.clear();
		}
	}
	cout << pos[0] << ',' << pos[1] << endl;
	return 0;
}



/*

int isCmd(string &str);
int move(string &in);
int main()
{
	
	string in;
	while (cin >> in)
	{
		move(in);
		return 0;
	}
		
	

	return 0;

}
//�ж��ǲ���ָ���ʽ  ���ض�Ӧ�Ĳ�������ȥ����ĸ
int isCmd(string &str)
{
	int ret = 0;
	if (str.size() < 0 || str.size() > 3)
	{
		return 0;
	}
	
	if (str[0] == 'A')
	{
		ret = 1;
		str.erase(str.begin());
	}
	else if (str[0] == 'D')
	{
		ret = 2;
		str.erase(str.begin());
	}
	else if (str[0] == 'W')
	{
		ret = 3;
		str.erase(str.begin());
	}
	else if (str[0] == 'S')
	{
		ret = 4;
		str.erase(str.begin());
	}
	//�ж�ʣ�ಿ���Ƿ�����λ����
	for (auto itt = str.begin(); itt != str.end(); ++itt)
	{
		if ((*itt) < '0' || (*itt) > '9')
			return 0;
	}
	return ret;
}

int move(string &in)
{
	//���շֺ�������
	string temp;
	int pos[2] = { 0,0 };
	vector<string> input;
	for (string::iterator it = in.begin(); it != in.end(); ++it)
	{
		if ((*it) != ';' && isalnum((*it)))
		{
			temp.push_back(*it);
		}
		else
		{
			if (temp.size() != 0)
			{
				input.push_back(temp);
			}
			temp.clear();
		}
	}
	for (auto ip = input.begin(); ip != input.end(); ++ip)
	{
		int cmd = 0;
		int numm = 0;
		cmd = isCmd(*ip);
		if (cmd != 0)
		{
			stringstream ss(*ip);
			ss >> numm;
			if (cmd == 1)
			{
				pos[0] -= numm;
			}
			else if (cmd == 2)
			{
				pos[0] += numm;
			}
			else if (cmd == 3)
			{
				pos[1] += numm;
			}
			else if (cmd == 4)
			{
				pos[1] -= numm;
			}

		}

	}
	cout << pos[0] << ',' << pos[1] << endl;
	return 0;
}
*/