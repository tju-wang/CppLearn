#include <iostream>
using namespace std;
#include <vector>
/*
��Ŀ˵��

���ξ�������1��ʼ����Ȼ���������гɵ�һ�������������Ρ�
*/
void outputResult(int n);
int main()
{
	int num = 0;
	while (cin >> num)
	{
		outputResult(num);
	}
	return 0;
}

void outputResult(int n)
{
	int arr[100][100] = {0};
	int cnt = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			arr[i-j][j] = cnt++;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n-i; ++j)
		{
			cout << arr[i][j];
			if(j!=n-1-i)
				 cout<< ' ';
		}
		cout << endl;
	}

}