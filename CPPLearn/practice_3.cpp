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
		//Ҫ���ݴ���������ݣ���
		sort(arr.begin(), arr.end());
		//ɾ���ظ�����
		vector<int>::iterator it = arr.begin();
		while (it != arr.end() - 1)
		{
			if ((*it) == (*(it + 1)))	//ɾ��it+1
			{
				it = arr.erase(it);	//ָ��ԭ����it+1
			}
			else
			{
				++it;
			}
		}
		if (arr.size()>1)
			if (*(arr.end() - 1) == *(arr.end() - 2))
				arr.erase(arr.end());
		//���
		for (int i = 0; i < arr.size(); ++i)
		{
			cout << arr[i] << endl;
		}
		arr.clear();
	}
	

	return 0;
}

//˼·��ʹ��vector����  sort��������  ���ѭ�����