#include <iostream>
using namespace std;


//const int mod = 1e9 + 7;

const int mod = 1e9 + 7;

long long OutputResult(long long n);
long long selectCnk(long long n, long long k);
long long kms(long long n);

int main()
{
	long long input = 0;
	
	while (cin >> input)
	{
		long long ret = 0;
		if(input>0)
			ret = OutputResult(input);
		else
		{
			ret = 0;
		}
		ret = ret % (mod);
		cout << ret << endl;
	}

	return 0;
}

long long OutputResult(long long n)
{
	long long ret = 0;
	//for (long long i = 1; i <= n; ++i)
	//{
	//	/*ret += i*selectCnk(n, i);*/
	//	ret += selectCnk(n, i);
	//	//ret = ret % (1000000000 + 7);
	//}
	//ret = n*pow(2, n - 1);
	return n*kms(n-1);
}

long long kms(long long n)
{
	long long ret = 1;
	for (int i = 0; i < n; i++)
	{
		ret *= 2;
		ret %= mod;
	}
	return ret;
}


long long selectCnk(long long n, long long k)
{
	if (n == k || k == 0)
		return 1;
	return (selectCnk(n - 1, k - 1) + selectCnk(n - 1, k));

}
long long jiech(long long n)
{
	long long ret = 1;
	if (n == 0)
		return 1;
	for (long long i=0; i < n; ++i)
	{
		ret = ret * (n - i);
	}
	return ret;
}