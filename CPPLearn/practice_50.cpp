#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <sstream>
/*
题目描述：根据给定的两个IP地址和一个子网掩码，计算这两个IP地址的网关。
若这两个IP地址的网关相同，则输出1和第一个IP地址的网关；若这两个IP地址的网关不相同，则输出0和第一个IP地址的网关。

若输入以下两个IP地址和一个子网掩码：
192.168.1.1 192.168.1.2 255.255.255.0
上述输入对应的输出为：
1 192.168.1.0

*/
void string2vec(string str, vector<int> &vec);

int main()
{
	string input;
	while (getline(cin, input))
	{
		//拆分
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


//将ip地址转化为4个整数
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