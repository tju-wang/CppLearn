#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>
#include <string>

//01交替子串
//int main()
//{
//	int k, pre, back;
//	string vec;
//	int len = 0;
//	cin >> len;
//	cin.ignore();
//	getline(cin, vec);
//	pre = 0;
//	back = 0;
//	for (int j = 1; j < len; ++j)
//	{
//		if (vec[j] != vec[j - 1]) pre++;
//		else back++;
//	}
//	back = back > 2 ? 2 : back;
//	cout << back+pre+1;
//
//	return 0;
//}


//寻找最大升序子序列
int main()
{
	int n = 0;
	cin >> n;
	cin.ignore();
	vector<int> vec;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	int res = 0;
	vector<int> len(n, 1);
	for (int i = 1; i < n; ++i)
	{
		int max_len = 0;
		for (int j = 0; j < i; ++j)
		{
			if (vec[j] < vec[i] && len[j]>max_len)
				max_len = len[j];	//更新max
			if (max_len == len[i - 1])
				break;
		}
		len[i] = max_len + 1;
		if (res < len[i])
			res = len[i];
	}
	cout << (n - res);

	return 0;
}