#include<iostream>
using namespace std;

#include <string>

/*
��һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ��������һֻ���ӣ��������Ӷ���������ÿ���µ���������Ϊ���٣�
*/
int rabbitNum(int month);
int main()
{
	int rabbit = 0;
	while (cin >> rabbit)
	{
		cout << rabbitNum(rabbit) << endl;
	}
		
	return 0;
}
int rabbitNum(int month)
{
	if (month <= 1)
		return month;
	if (month == 2)
		return 1;
	int first = 0;
	int second = 1;
	int ret = 0;
	for (int i = 1; i < month; ++i)
	{
		ret = first + second;
		first = second;
		second = ret;
	}
	return ret;
}