#include <iostream>
using namespace std;

/*
������ԣ�����
����һ��������N�ͳ���L���ҳ�һ�γ��ȴ��ڵ���L�������Ǹ����������ǵĺ�ǡ��ΪN���𰸿����ж������������Ҫ�ҳ�������С���Ǹ���
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

