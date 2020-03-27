#include <iostream>
using namespace std;

#include <vector>

/*
输入一个int型的正整数，计算出该int型数据在内存中存储时1的个数
思路：

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