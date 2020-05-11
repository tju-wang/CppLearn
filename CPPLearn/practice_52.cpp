#include <iostream>
using namespace std;

#include <string>

/*
第一题：编码数目 ? ?
题目：输入N,M，求N+N^2+N^3+...+N^M的结果（取余1000000007），1<N<=65536，1<M<=100000 ? ?
输入格式：每行输入N M，直到N M均等于0时跳出 ??
输出格式：每行输出对应的结果

解题思路：快速幂（实质对幂指数进行二进制转换，将累乘拆分），不了解的可以查找一下
————————————————
版权声明：本文为CSDN博主「JingleLiA」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/JingleLiA/article/details/105498829
*/

long mod = 1000000007;
long long kms(long long N, long long M);

int main()
{
	long N = 0, M = 0;
	while (cin >> N >> M)
	{
		cin.ignore();
		//可以使用等比数列通项公式求解
		if (N == 0 && M == 0)
			break;
		long long sum = 0;
		long long a1 = N;
		long long Nm = kms(N, M);
		sum = (a1 * (1 - Nm) / (1 - N))%mod;
		cout << sum << endl;
	}

	return 0;
}

//快速幂算法  在过程中对mod取余
long long kms(long long N, long long M)
{
	long long ret = 1;
	long long n = N;
	while (M != 0)
	{
		if (M & 1)
			ret = (ret * n)%mod;
		n = (n*n)%mod;
		M = M >> 1;
	}
	return ret;
}