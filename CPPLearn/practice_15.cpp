#include <iostream>
using namespace std;

#include <vector>

/*
����һ��int�͵����������������int���������ڴ��д洢ʱ1�ĸ���
˼·��

*/

int main()
{
	int num = 0;
	cin >> num;
	int cnt = 0,i=0;
	while (num)
	{
		if (num & (1 << i))
		{
			cnt++;
			num &= ~(1 << i);
		}
			
		++i;

	}
	cout << cnt << endl;

	return 0;
}