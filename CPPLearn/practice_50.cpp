#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <sstream>
/*
��Ŀ���������ݸ���������IP��ַ��һ���������룬����������IP��ַ�����ء�
��������IP��ַ��������ͬ�������1�͵�һ��IP��ַ�����أ���������IP��ַ�����ز���ͬ�������0�͵�һ��IP��ַ�����ء�

��������������IP��ַ��һ���������룺
192.168.1.1 192.168.1.2 255.255.255.0
���������Ӧ�����Ϊ��
1 192.168.1.0

*/
void string2vec(string str, vector<int> &vec);

int main()
{
	string input;
	while (getline(cin, input))
	{
		//���
		string ip1, ip2, mask,temp;
		int f = 0;
		input.push_back(' ');
		for (auto it = input.begin(); it != input.end(); ++it)
		{
			if ((*it) == ' ')
			{
				switch (f)
				{
				case 0:
				{
					ip1 = temp;
				}break;
				case 1:
				{
					ip2 = temp;
				}break;
				case 2:
				{
					mask = temp;
				}break;
				}
				temp.clear();
				f++;
			}
			else
			{
				temp.push_back((*it));
			}
		}
		vector<int> vec1,vec2,mask1,rem;
		string2vec(ip1, vec1);
		string2vec(ip2, vec2);
		string2vec(mask, mask1);
		int ret = 1;
		if (vec1.size() == 4 && vec1.size() == vec2.size() && mask1.size() == vec1.size())
		{
			for (int i = 0; i < 4; i++)
			{
				rem.push_back(vec1[i] & mask1[i]);
				if ((vec1[i] & mask1[i]) != (vec2[i] & mask1[i]))
				{
					ret = 0;
				}
			}
		}
		cout << ret << ' ';
		for (auto it=rem.begin();it!=rem.end(); ++it)
		{
			if (it != rem.end() - 1)
				cout << (*it) << '.';
			else
			{
				cout << (*it) << endl;
			}
		}

	}

	return 0;
}


//��ip��ַת��Ϊ4������
void string2vec(string str, vector<int> &vec)
{
	string temp;
	str.push_back('.');
	vec.clear();
	for (auto it = str.begin(); it != str.end(); ++it)
	{
		if ((*it) == '.')
		{
			stringstream ss(temp);
			int t = 0;
			ss >> t;
			vec.push_back(t);
			temp.clear();
		}
		else
		{
			temp.push_back((*it));
		}
	}
}