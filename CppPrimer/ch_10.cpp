#include <iostream>
#include <forward_list>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void func10_14()
{
	//10.14 lambda表达式求两个int的和
	auto f = [](int a, int b) -> int { return (a + b); };
	cout << f(1, 2) << endl;

	int num = 100;
	auto summ = [num](int a) -> int { return (a + num);  };
	cout << summ(2) << endl;

}

int main()
{
	func10_14();

	return 0;
}
