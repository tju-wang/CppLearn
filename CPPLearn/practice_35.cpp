#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <sstream>
/*
���������������ж�������̨�������IP��ַ�Ƿ�����ͬһ������ĸ��ݡ�
����������IP��ַ�ṹ��ͬ����32λ������������������Ų���ȫΪ��1���������Ų���ȫΪ��0��������������������ж���̨�����Ƿ���ͬһ�����С�
����̨������IP��ַ�ֱ������ǵ����������ࡰ�롱��Ľ����ͬ����˵������̨������ͬһ�����С�
IP��ַ��ʽΪ0-255 . 0-255 . 0-255 .0-255   ��������  
������������������

*/


bool isIP(string &IP, vector<int> &addr);
int partNum(string str, int(*num)[4]);	//����4��ֵ
int isMastErr(string &str);

int main()
{
	string IP1, IP2, Mask;
	while (cin >> Mask)
	{
		cin >> IP1;
		cin >> IP2;

		int ret = 0;
		vector<int> addrIP1, addrIP2, addrMask;
		
		if (isIP(IP1,addrIP1) && isIP(IP2,addrIP2) && isMastErr(Mask) && isIP(Mask,addrMask))
		{
			for (int i = 0; i < 4; ++i)
			{
				int addr1 = (addrIP1[i] & addrMask[i]);
				int addr2 = (addrIP2[i] & addrMask[i]);
				if (addr1 != addr2)
				{
					ret = 2;
					break;
				}
			}
		}
		else
		{
			ret = 1;
		}
		cout << ret << endl;
	}
	return 0;
}

bool isIP(string &IP,vector<int> &addr)
{
	IP.push_back('.');
	string temp;
	int num;
	for (auto it = IP.begin(); it != IP.end(); ++it)
	{
		if ((*it) == '.')
		{
			stringstream ss(temp);
			ss >> num;
			temp.clear();
			if (num < 0 || num > 255)
				return false;
			addr.push_back(num);
		}
		else
		{
			temp.push_back((*it));
		}
	}
	if (addr.size() == 4)
		return true;
	else
		return false;
}

int isMastErr(string &str)
{
	int arr[4] = { 0 };
	int flag = 0;
	if (partNum(str, &arr) == 0)
	{
		return 0;	//�Ƿ���ַ
	}
	if (arr[0] == 0)
		return 0;
	//�����ж�  �Ƿ��ǷǷ�������
	for (int k = 0; k < 4; ++k)
	{
		int i = 7;
		while (i >= 0)
		{
			if ((arr[k] & (1 << i)) == 0 && flag == 0)
			{
				flag = 1;
				continue;
			}

			if ((arr[k] & (1 << i)) != 0 && flag == 1)
				return 0;	//�Ƿ�
			arr[k] &= ~(1 << i);
			--i;
		}
	}
	if (flag == 0)
		return 0;
	return 1;
}

int partNum(string str, int(*num)[4])	//����4��ֵ
{
	int flag = 0, tempNum = 0;
	string temp;
	str.push_back('.');	//�ټ�һ��.
	for (auto it = str.begin(); it != str.end(); ++it)
	{
		if ((*it) == '.')
		{
			flag++;
			if (temp.size() > 0)
			{
				stringstream ss(temp);
				ss >> tempNum;
			}
			else if (flag<4)
			{
				return 0;	//ʧ��
			}
			if (flag < 5)
			{
				if (tempNum >= 0 && tempNum <= 255)
					(*num)[flag - 1] = tempNum;
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
			temp.clear();
		}
		else
		{
			temp.push_back((*it));
		}
	}
	return 1;
}