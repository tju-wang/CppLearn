#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
/*
求素数伴侣
1.在找素数伴侣的过程中需要遍历所有可能情况
2.考虑用有记忆的递归解决

*/

void findPrime(vector<int> vec, int cnt, vector<int> &rember);
bool isPrimeNum(int i);
int main()
{
	int Num;
	while (cin >> Num)
	{
		vector<int> input;
		for (int i = 0; i < Num; ++i)
		{
			int temp;
			cin >> temp;
			input.push_back(temp);
		}
		vector<int> rember;
		findPrime(input, 0, rember);
		auto k = *max_element(rember.begin(), rember.end());
		cout << k << endl;
	}

	return 0;
}

void findPrime(vector<int> vec, int cnt, vector<int> &rember)
{
	int len = vec.size();
	if (len == 0)
	{
		rember.push_back(cnt);
		return;
	}
	int temp = vec[0];
	vec.erase(vec.begin());
	len = vec.size();
	vector<int> vecTemp;
	for (int i = 0; i < len; ++i)
	{
		vecTemp = vec;
		int temp1 = vec[i];
		vecTemp.erase(vecTemp.begin() + i);
		if (isPrimeNum(temp + temp1))
			findPrime(vecTemp, cnt+1, rember);
		else
		{
			findPrime(vecTemp, cnt, rember);
		}
	}

}


bool isPrimeNum(int i)	//判断i是不是质数  能不能被2以上  1/2*i以内的数整除
{
	for (int k = 2; k < i / 2; ++k)
	{
		if (i%k == 0)
		{
			return false;
		}
	}
	return true;
}
