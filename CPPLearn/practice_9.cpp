#include <iostream>
using namespace std;
#include <string>
#include <sstream>
#include <algorithm>
/*
����һ��int�����������մ���������Ķ�˳�򣬷���һ�������ظ����ֵ��µ�����
*/

int main()
{
	int num = 0;
	cin >> num;
	string str = to_string(num);
	for (string::iterator it = str.end(); it != str.begin();)
	{
		--it;
		for (string::iterator ip = it; ip != str.begin();)
		{
			ip--;
			if ((*ip) == (*it))	//ɾ��ip
			{
				if (ip == str.begin())
				{
					ip = str.erase(ip);
					break;
				}
				else
				{
					ip = str.erase(ip) - 1;
				}
			}
		}
	}
	//����
	reverse(str.begin(), str.end());
	//��stringת��Ϊint
	int ret;
	stringstream ss(str);//�����ַ��������󣬳�ʼ��Ϊs
	ss >> ret;//����������ݵ�ans
	cout << ret << endl;
	return 0;

}
