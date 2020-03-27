#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>

/*
?һ��������������I��һ�������������R��I��R���еĵ�һ������Ϊ���еĸ�����������������һ����������������ΧΪ0~0xFFFFFFFF�����и�������
*/
bool isExist(string &str1, string &str2);

void OutputResult(vector<int> &Ivec, vector<int> &Rvec);

int main()
{

	
	int temp;
	int lenI = 0,lenR = 0;
	while (cin>>lenI)
	{
		vector<int> Ivec, Rvec;
		for (int i = 0; i < lenI; ++i)
		{
			cin >> temp;
			Ivec.push_back(temp);
		}
		cin >> lenR;
		for (int i = 0; i < lenR; ++i)
		{
			cin >> temp;
			Rvec.push_back(temp);
		}
		OutputResult(Ivec, Rvec);
	}

 	return 0;
}

void OutputResult(vector<int> &Ivec, vector<int> &Rvec)
{

	sort(Rvec.begin(), Rvec.end());
	//ȥ��
	for (auto it = Rvec.begin(); it != Rvec.end() - 1; ++it)
	{
		if ((*it) == (*(it + 1)))
			it = Rvec.erase(it) - 1;
	}
	string Istr, Rstr;
	vector<vector<int>> num;
	vector<int> arr;
	for (auto ir = Rvec.begin(); ir != Rvec.end(); ++ir)
	{
		Rstr = to_string(*ir);
		arr.push_back((*ir));
		for (auto it = Ivec.begin(); it != Ivec.end(); ++it)
		{
			Istr = to_string((*it));
			if (isExist(Istr, Rstr))
			{
				//��¼
				arr.push_back((it - Ivec.begin()));		//������
			}
		}
		num.push_back(arr);
		arr.clear();
	}
	//��֯���  �����������
	vector<int> out;
	int sizeNum = num.size();
	for (int i = 0; i <sizeNum; ++i)
	{
		int sizeCol = num[i].size();
		if (sizeCol > 1)
		{
			out.push_back(num[i][0]);
			out.push_back(sizeCol - 1);
		}

		for (int j = 1; j < sizeCol; ++j)
		{
			out.push_back(num[i][j]);
			out.push_back(Ivec[(num[i][j])]);
		}
	}
	cout << out.size() << ' ';
	int outSize = out.size();
	for (int i = 0; i < outSize - 1; ++i)
	{
		cout << out[i] << ' ';
	}
	cout << out[out.size() - 1] << endl;
}

bool isExist(string &str1, string &str2)	//���str2�Ƿ���str1���Ӵ�
{
	if (str1.find(str2) == str1.npos)
	{
		return false;
	}
	else
		return true;
}