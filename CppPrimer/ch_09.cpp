#include <iostream>
#include <forward_list>
#include <string>
#include <algorithm>
#include <vector>

using std::forward_list;
using std::cout;

auto remove_odds(forward_list<int>& flist)
{
	auto is_odd = [](int i) { return i & 0x1; };	//？？啥   可能是lamb表达式
	flist.remove_if(is_odd);
}

bool predicate(const std::string &s)
{
	return s.size() >= 5;
}

int main()
{
	/*forward_list<int> data = { 0, 1, 3, 3, 4, 5, 6, 7, 8, 9 };
	remove_odds(data);
	for (auto i : data)
		cout << i << " ";
*/
	//10.13  partition函数的使用
	auto v = std::vector<std::string>{ "a", "as", "aasss", "aaaaassaa", "aaaaaabba", "aaa" };
	auto pivot = std::partition(v.begin(), v.end(), predicate);	//partition函数，重排容器  重排规则由predicate()函数定义，即string长度大于5的元素排到容器前边
	//其函数返回值为指向最后一个使得谓词为true的元素之后的位置
	for (auto it = v.cbegin(); it != pivot; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	return 0;
}