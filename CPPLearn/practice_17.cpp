#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <sstream>

/*
请解析IP地址和对应的掩码，进行分类识别。要求按照A/B/C/D/E类地址归类，不合法的地址和掩码单独归类。

所有的IP地址划分为 A,B,C,D,E五类

A类地址1.0.0.0~126.255.255.255;

B类地址128.0.0.0~191.255.255.255;

C类地址192.0.0.0~223.255.255.255;

D类地址224.0.0.0~239.255.255.255；

E类地址240.0.0.0~255.255.255.255
...

思路：很麻烦的一道题  需要注意不少细节
1.mask是否非法的判断
2.数据输入输出问题   输入数据空格问题  并不是样例输入每行都换行的
3.注意细节  使用引用，同一字符串多次执行某一函数  在函数中改变字符串时，会产生错误
*/


void judgeAddr(string &str, int(*out)[7]);
int partNum(string str, int(*num)[4]);	//返回4个值
int isZeroAddr(string &str);	//判断是不是0打头的
int isClassAddr(string &str, int(*cnt)[7]);
int isMastErr(string &str);
int isPrivateAddr(string &str, int(*cnt)[7]);
int  main()
{

	string input;
	int out[7] = { 0 };
	while (cin >> input)
	{
		//分析并输出
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
	//分为两个字符串
	string addr;
	string mask;
	int flag = 1, flag_mask = 0;
	//计数变量
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
	//判断mask是否不合格
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
	//判断私有
	if (isPrivateAddr(addr, cnt) == -1)
	{
		if (flag_mask == 0)
			++((*cnt)[5]);
		return;
	}

}
int isZeroAddr(string &str)	//判断是不是0打头的
{
	int arr[4] = { 0 };
	if (partNum(str, &arr)==0)
	{
		return -1;	//非法地址
	}
	if (arr[0] == 0)	//不是几个类当中的
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
		return -1;	//非法地址
	}
	if (arr[0] == 0)
		return -1;
	//继续判断  是否是非发的掩码
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
				return -1;	//非法
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
		return -1;	//非法地址
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
		return 0;	//可能是私有地址
	}
	return 1;
}
int isPrivateAddr(string &str, int(*cnt)[7])
{
	int arr[4] = { 0 };
	if (partNum(str, &arr) == 0)
	{
		return -1;	//非法地址
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

int partNum(string str,int (*num)[4])	//返回4个值
{
	int flag = 0, tempNum = 0;
	string temp;
	str.push_back('.');	//再加一个.
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
				return 0;	//失败
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

