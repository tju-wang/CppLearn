#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
���ݱ��¼��������������ֵ��int��Χ������������Ա�������ͬ�ļ�¼���кϲ���
������ͬ��������ֵ����������㣬�������keyֵ������������
*/

struct Data {
	int index;
	int val;
};

bool isHere(int index, vector<Data> &ret);
void msort(vector<Data> &arr);
int main()
{
	int arrNum = 0;
	int tempIndex, tempVal;
	Data tempData;
	cin >> arrNum;
	vector<Data> arr;
	vector<Data> ret;
	for (int i = 0; i < arrNum; ++i)
	{
		cin >> tempIndex >> tempVal;
		tempData.index = tempIndex;
		tempData.val = tempVal;
		arr.push_back(tempData);
	}
	for (vector<Data>::iterator it = arr.begin(); it != arr.end(); ++it)
	{
		if (!isHere((*it).index, ret))
		{
			for (vector<Data>::iterator ip = it + 1; ip != arr.end(); ++ip)
			{
				if ((*it).index == (*ip).index)
					(*it).val += (*ip).val;
			}
			ret.push_back((*it));
		}
	}
	//���
	int len = ret.size();
	msort(ret);
	for (int i = 0; i < len; ++i)
	{
		cout << ret[i].index << ' ' << ret[i].val << endl;
	}

	return 0;
}
//����ret���Ƿ��У�*it��.index

bool isHere(int index, vector<Data> &ret)
{
	int len = ret.size();
	if (len == 0)
		return false;
	for (int i = 0; i < len; ++i)
	{
		if (index == ret[i].index)
			return true;
	}
	return false;
}
void msort(vector<Data> &arr)	//�����㷨
{
	Data temp;
	for (vector<Data>::iterator it = arr.begin(); it != arr.end(); ++it)
	{
		for (vector< Data>::iterator ip = it+1; ip != arr.end(); ++ip)
		{
			if ((*it).index > (*(ip)).index)
			{
				temp.index = (*ip).index;
				temp.val = (*ip).val;
				(*ip).index = (*it).index;
				(*ip).val = (*it).val;
				(*it).index = temp.index;
				(*it).val = temp.val;
			}	
		}
	}

}
