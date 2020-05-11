#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <algorithm>
#include <set>
/*
现有一组砝码，重量互不相等，分别为m1,m2,m3…mn；

注意代码中的去重函数的使用，先使用sort函数排序，然后unique可以去掉重复
也可以使用自己写的去重函数  可能是效率问题，只通过了50%
*/

void uniqVector(vector<int> &vec);

int main()
{
	int num;

	while (cin >> num)
	{
		vector<int> fama;
		vector<int> famaNum;
		vector<int> famaAll;
		vector<int> ret;
		vector<int> retTemp;
		for (int i = 0; i < num; ++i)
		{
			int tempFama;
			cin >> tempFama;
			fama.push_back(tempFama);
		}
		for (int i = 0; i < num; ++i)
		{
			int numFama;
			cin >> numFama;
			famaNum.push_back(numFama);
		}
		for (int i = 0; i < num; ++i)
		{
			for (int j = 0; j < famaNum[i]; ++j)
			{
				famaAll.push_back(fama[i]);
			}
		}
		ret.push_back(0);
		for (auto it = famaAll.begin(); it != famaAll.end(); ++it)
		{
			for (auto ip = ret.begin(); ip != ret.end(); ++ip)
			{
				retTemp.push_back((*ip)+(*it));
			}
			for (auto ik = retTemp.begin(); ik != retTemp.end(); ++ik)
			{
				ret.push_back(*ik);
			}
			//去重
//			uniqVector(ret);
//			sort(ret.begin(), ret.end());
//			ret.erase(unique(ret.begin(), ret.end()), ret.end());
			set <int> sett(ret.begin(), ret.end());		//将vector容器转化为set容器  利用set容器，一个键值只能出现一次的特点 达到去重的效果
			ret.assign(sett.begin(), sett.end());
		}
		//sort(ret.begin(), ret.end());
		//ret.erase(unique(ret.begin(), ret.end()), ret.end());
		set <int> sett(ret.begin(), ret.end());
		ret.assign(sett.begin(), sett.end());
		uniqVector(ret);
		cout << ret.size() << endl;
	}

	return 0;
}

//去重  但是效率比较低  unique函数是将重复的元素放到vector末尾  并返回迭代器指向第一个重复的元素
void uniqVector(vector<int> &vec)
{
	sort(vec.begin(), vec.end());
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		if (it != vec.end() - 1)
		{
			if ((*it) == (*(it + 1)))
				it = vec.erase(it) - 1;
		}
	}
}


