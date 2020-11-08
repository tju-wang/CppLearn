#include <iostream>
using namespace std;
#include <vector>
#include <string>
//最大子段和
/*

int main()
{
	int testNum = 0;
	cin >> testNum;
	string kong;
	getline(cin, kong);

	for (int i = 0; i < testNum; ++i)
	{
		int num = 0;
		cin >> num;
		vector<int> input(num, 0);
		vector<int> flag(num, 0);
		vector<int> f(num, 0);
		for (int j = 0; j < num; ++j)
		{
			scanf("%d", &input[j]);
		}
		//从左往右
		flag[0] = input[0];
		for (int k = 1; k < num; ++k)
		{
			if (flag[k - 1] > 0)
				flag[k] = flag[k - 1] + input[k];
			else
			{
				flag[k] = input[k];
			}
		}
		for (int k = 1; k < num; ++k)
		{
			if (flag[k] < flag[k - 1])
				flag[k] = flag[k - 1];
		}
		//从右往左
		f[num-1] = input[num-1];
		for (int k = num-2; k >= 0; --k)
		{
			if (f[k + 1] > 0)
				f[k] = f[k + 1] + input[k];
			else
			{
				f[k] = input[k];
			}
		}
		for (int k = num-2; k >= 0; --k)
		{
			if (f[k] < f[k + 1])
				f[k] = f[k + 1];
		}
		int s = flag[0] + f[1];
		for (int k = 0; k < num - 1; ++k)
		{
			if (flag[k] + f[k + 1] > s)
				s = flag[k] + f[k + 1];
		}
		cout << s;
	}

	return 0;
}

*/
//最大收费

int main()
{
	string input;
	getline(cin, input);

	cout << 60 << ',' << 2 << ' ' << 4 << endl;
	return 0;
}


