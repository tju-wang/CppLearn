#include <iostream>
using namespace std;

/*
����һ���������߶��������£�ÿ����غ�����ԭ�߶ȵ�һ��; ������, �����ڵ�5�����ʱ��������������?��5�η�����ߣ�
��������ж���С����3λ
*/

int main()
{
	int high = 0;
	while (cin >> high)
	{
		double h = (double)high;
		double sum = 0;
		for (int i = 0; i < 5; ++i)
		{
			sum += h;
			h /= 2;
			if(i!=4)
				sum += h;
		}
		cout << sum << endl << h << endl;
	}
	return 0;
}