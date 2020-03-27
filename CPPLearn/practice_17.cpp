#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <sstream>

/*
�����IP��ַ�Ͷ�Ӧ�����룬���з���ʶ��Ҫ����A/B/C/D/E���ַ���࣬���Ϸ��ĵ�ַ�����뵥�����ࡣ

���е�IP��ַ����Ϊ A,B,C,D,E����

A���ַ1.0.0.0~126.255.255.255;

B���ַ128.0.0.0~191.255.255.255;

C���ַ192.0.0.0~223.255.255.255;

D���ַ224.0.0.0~239.255.255.255��

E���ַ240.0.0.0~255.255.255.255
...

˼·�����鷳��һ����  ��Ҫע�ⲻ��ϸ��
1.mask�Ƿ�Ƿ����ж�
2.���������������   �������ݿո�����  ��������������ÿ�ж����е�
3.ע��ϸ��  ʹ�����ã�ͬһ�ַ������ִ��ĳһ����  �ں����иı��ַ���ʱ�����������
*/


void judgeAddr(string &str, int(*out)[7]);
int partNum(string str, int(*num)[4]);	//����4��ֵ
int isZeroAddr(string &str);	//�ж��ǲ���0��ͷ��
int isClassAddr(string &str, int(*cnt)[7]);
int isMastErr(string &str);
int isPrivateAddr(string &str, int(*cnt)[7]);
int  main()
{

	string input;
	int out[7] = { 0 };
	while (cin >> input)
	{
		//���������
		if(input.size()>3)
			judgeAddr(input,&out);
	}
	for (int k = 0; k < 7; ++k)
	{
		if(k!=6)
		cout << out[k] << ' ';
		else
		{
			cout << out[k] << endl;
		}
	}
	return 0;
}
void judgeAddr(string &str,int (*cnt)[7])
{
	//��Ϊ�����ַ���
	string addr;
	string mask;
	int flag = 1, flag_mask = 0;
	//��������
	for (auto it = str.begin(); it != str.end(); ++it)
	{
		if ((*it) == '~')
		{
			flag = 2;
			continue;
		}
		if(flag==1)
		{
			addr.push_back((*it));
		}
		else
		{
			mask.push_back((*it));
		}
	}
	//�ж�mask�Ƿ񲻺ϸ�
	if (isMastErr(mask) == -1)
	{
		flag_mask = 1;
		++((*cnt)[5]);
		return;
	}
	if (isZeroAddr(addr)==1)
	{
		return;
	}
	if (isClassAddr(addr,cnt)==-1)
	{
		if (flag_mask == 0)
			++((*cnt)[5]);
		return;
	}
	//�ж�˽��
	if (isPrivateAddr(addr, cnt) == -1)
	{
		if (flag_mask == 0)
			++((*cnt)[5]);
		return;
	}

}
int isZeroAddr(string &str)	//�ж��ǲ���0��ͷ��
{
	int arr[4] = { 0 };
	if (partNum(str, &arr)==0)
	{
		return -1;	//�Ƿ���ַ
	}
	if (arr[0] == 0)	//���Ǽ����൱�е�
	{
		return 1;
	}
	return 0;
	
}
int isMastErr(string &str)
{
	int arr[4] = { 0 };
	int flag = 0;
	if (partNum(str, &arr) == 0)
	{
		return -1;	//�Ƿ���ַ
	}
	if (arr[0] == 0)
		return -1;
	//�����ж�  �Ƿ��ǷǷ�������
	for (int k = 0; k < 4; ++k)
	{
		int i = 7;
		while (i>=0)
		{
			if ((arr[k] & (1 << i)) == 0 && flag == 0)
			{
				flag = 1;
				continue;
			}
				
			if ((arr[k] & (1 << i)) != 0 && flag == 1)
				return -1;	//�Ƿ�
			arr[k] &= ~(1 << i);
			--i;
		}
	}
	if (flag == 0)
		return -1;
	return 0;
}
int isClassAddr(string &str,int (*cnt)[7])
{
	int arr[4] = { 0 };
	if (partNum(str, &arr) == 0)
	{
		return -1;	//�Ƿ���ַ
	}
	if (arr[0] >= 1 && arr[0] <= 126)
		(*cnt)[0]++;		
	else if (arr[0] >= 128 && arr[0] <= 191)
		(*cnt)[1]++;
	else if (arr[0] >= 192 && arr[0] <= 223)
		(*cnt)[2]++;
	else if (arr[0] >= 224 && arr[0] <= 239)
		(*cnt)[3]++;
	else if (arr[0] >= 240 && arr[0] <= 255)
		(*cnt)[4]++;
	else
	{
		return 0;	//������˽�е�ַ
	}
	return 1;
}
int isPrivateAddr(string &str, int(*cnt)[7])
{
	int arr[4] = { 0 };
	if (partNum(str, &arr) == 0)
	{
		return -1;	//�Ƿ���ַ
	}
	if ((arr[0] == 10) || (arr[0] == 172 && arr[1] >= 16 && arr[1] <= 31) || (arr[0] == 192 && arr[1] == 168))
	{
		(*cnt)[6]++;
		return 1;
	}
	else
	{
		return 0;
	}
}

int partNum(string str,int (*num)[4])	//����4��ֵ
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
			else if(flag<4)
			{
				return 0;	//ʧ��
			}
			if (flag < 5)
			{
				if(tempNum>=0 && tempNum <=255)
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

