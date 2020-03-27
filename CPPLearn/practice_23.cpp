#include <iostream>
using namespace std;

/*
阿里笔试，例题
给出一个正整数N和长度L，找出一段长度大于等于L的连续非负整数，他们的和恰好为N。答案可能有多个，我我们需要找出长度最小的那个。
*/

int main()
{
	int N, L;
	cin >> N >> L;
	int len;
	int start;
	if (L <= 100 && N <= 1000000000)
	{
		for (len = L; len <= 100; ++len)
		{
			if ((2 * N - len*len + len) % (2 * len)==0)
			{
				start = (2 * N - len*len + len) / (2 * len);
				if (start < 0) continue;
				for (int j = 0; j < len; ++j)
				{
					if (j != len - 1)
						cout  << start + j << ' ';
					else
					{
						cout << start + j;
					}
				}
				//cout << fixed << setprecision(0) << 10 << endl;
				cout << endl;
				return 0;
			}	
		}
	}
	cout << "No" << endl;
	return 0;
}

