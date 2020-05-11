#include <iostream>
using namespace std;

/*
假设一个球从任意高度自由落下，每次落地后反跳回原高度的一半; 再落下, 求它在第5次落地时，共经历多少米?第5次反弹多高？
最后的误差判断是小数点3位
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