#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

int main()
{
	int num = 0,temp = 0;
	vector<int> arr;
	while (cin >> num)
	{
		for (int i = 0; i < num; ++i)
		{
			cin >> temp;
			arr.push_back(temp);
		}
		//要兼容处理多组数据？？
		sort(arr.begin(), arr.end());
		//删掉重复数据
		vector<int>::iterator it = arr.begin();
		while (it != arr.end() - 1)
		{
			if ((*it) == (*(it + 1)))	//删除it+1
			{
				it = arr.erase(it);	//指向原来的it+1
			}
			else
			{
				++it;
			}
		}
		if (arr.size()>1)
			if (*(arr.end() - 1) == *(arr.end() - 2))
				arr.erase(arr.end());
		//输出
		for (int i = 0; i < arr.size(); ++i)
		{
			cout << arr[i] << endl;
		}
		arr.clear();
	}
	

	return 0;
}

//思路：使用vector处理  sort进行排序  最后循环输出