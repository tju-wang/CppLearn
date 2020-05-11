#include<iostream>
using namespace std;

#include <string>

/*
有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，假如兔子都不死，问每个月的兔子总数为多少？
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