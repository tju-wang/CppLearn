#include <iostream>
#include <forward_list>
#include <string>
#include <algorithm>
#include <vector>

using std::forward_list;
using std::cout;

auto remove_odds(forward_list<int>& flist)
{
	auto is_odd = [](int i) { return i & 0x1; };	//����ɶ   ������lamb���ʽ
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
	//10.13  partition������ʹ��
	auto v = std::vector<std::string>{ "a", "as", "aasss", "aaaaassaa", "aaaaaabba", "aaa" };
	auto pivot = std::partition(v.begin(), v.end(), predicate);	//partition��������������  ���Ź�����predicate()�������壬��string���ȴ���5��Ԫ���ŵ�����ǰ��
	//�亯������ֵΪָ�����һ��ʹ��ν��Ϊtrue��Ԫ��֮���λ��
	for (auto it = v.cbegin(); it != pivot; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	return 0;
}