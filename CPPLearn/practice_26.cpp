#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
/*
����������
1.�����������µĹ�������Ҫ�������п������
2.�������м���ĵݹ���

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


bool isPrimeNum(int i)	//�ж�i�ǲ�������  �ܲ��ܱ�2����  1/2*i���ڵ�������
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
