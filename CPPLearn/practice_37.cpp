#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <algorithm>
#include <set>
/*
����һ�����룬����������ȣ��ֱ�Ϊm1,m2,m3��mn��

ע������е�ȥ�غ�����ʹ�ã���ʹ��sort��������Ȼ��unique����ȥ���ظ�
Ҳ����ʹ���Լ�д��ȥ�غ���  ������Ч�����⣬ֻͨ����50%
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
			//ȥ��
//			uniqVector(ret);
//			sort(ret.begin(), ret.end());
//			ret.erase(unique(ret.begin(), ret.end()), ret.end());
			set <int> sett(ret.begin(), ret.end());		//��vector����ת��Ϊset����  ����set������һ����ֵֻ�ܳ���һ�ε��ص� �ﵽȥ�ص�Ч��
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

//ȥ��  ����Ч�ʱȽϵ�  unique�����ǽ��ظ���Ԫ�طŵ�vectorĩβ  �����ص�����ָ���һ���ظ���Ԫ��
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


