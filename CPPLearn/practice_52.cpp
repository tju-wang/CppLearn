#include <iostream>
using namespace std;

#include <string>

/*
��һ�⣺������Ŀ ? ?
��Ŀ������N,M����N+N^2+N^3+...+N^M�Ľ����ȡ��1000000007����1<N<=65536��1<M<=100000 ? ?
�����ʽ��ÿ������N M��ֱ��N M������0ʱ���� ??
�����ʽ��ÿ�������Ӧ�Ľ��

����˼·�������ݣ�ʵ�ʶ���ָ�����ж�����ת�������۳˲�֣������˽�Ŀ��Բ���һ��
��������������������������������
��Ȩ����������ΪCSDN������JingleLiA����ԭ�����£���ѭ CC 4.0 BY-SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/JingleLiA/article/details/105498829
*/

long mod = 1000000007;
long long kms(long long N, long long M);

int main()
{
	long N = 0, M = 0;
	while (cin >> N >> M)
	{
		cin.ignore();
		//����ʹ�õȱ�����ͨ�ʽ���
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

//�������㷨  �ڹ����ж�modȡ��
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