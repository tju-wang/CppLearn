#include <iostream>
using namespace std;

long jump(long n);
int main()
{
	int n = 0;
	
	while (cin >> n)
	{
		int ret = 0;
		ret = jump(n);
		cout << ret << endl;
	}
}

long jump(long n)
{
	if (n == 0 || n==1)
		return n;

	int firstStep = 0;
	int SecondStep = 1;

	int ret = 0;
	for (int i = 0; i < n; ++i)
	{
		ret = firstStep + SecondStep;
		firstStep = SecondStep;	//n-2
		SecondStep = ret;	//n-1
	}
	return ret;

}
