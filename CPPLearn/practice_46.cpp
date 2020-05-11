#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <algorithm>

/*
2020 3.4 ��Ϊ����  ��һ��
����ת��
����������
(1) �����һ��һ��������N (0<N<10)
(2) ������N��ÿ��N�������ÿո�ֿ���Ϊ���������
(3) ������һ��һ��������M (0<=M<=10000)
˵�������ÿ����쳣���룬�������붼�������ģ��ϸ����ȡֵ��Χ
���������
(1) N�У�ÿ��N���������ÿո�ֿ���Ϊ��ת�������
��������������������������������
��Ȩ����������ΪCSDN���������ĳ�007����ԭ�����£���ѭ CC 4.0 BY-SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/xiecheng1995/article/details/104773534/

*/

void reverseMatrix(vector<vector<int>> vec, vector<vector<int>> &ret);
int main()
{
	int N = 0,M = 0;
	while (cin >> N)
	{
		vector<vector<int> > vec;
		vector<int> temp;
		
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				int input;
				cin >> input;
				temp.push_back(input);
			}
			vec.push_back(temp);
			temp.clear();
		}
		cin >> M;
		int tim = M % 4;
		vector<vector<int> > ret;
		for (int i = 0; i < tim; ++i)
		{
			reverseMatrix(vec, ret);
			vec.clear();
			vec = ret;
		}
		ret.clear();
		ret = vec;
		for (int i = 0; i < (int)ret.size(); ++i)
		{
			for (int j = 0; j < (int)ret[0].size(); ++j)
			{
				if(j!= (int)ret[0].size()-1)
					cout << ret[i][j] << ' ';
				else
				{
					cout << ret[i][j] << endl;
				}
			}
		}
		
		
	}
	return 0;
}
void reverseMatrix(vector<vector<int>> vec, vector<vector<int>> &ret)
{
	int len = vec.size();	//����
	vector<int> temp(len,0);
	ret.clear();

	for (int i = 0; i < len; ++i)
	{
		ret.push_back(temp);
	}
	for (int i = len - 1; i >= 0; --i)
	{
		//ȡ����i��
		for (int j = 0; j < len; ++j)
		{
			ret[j][len - i - 1] = vec[i][j];
		}
	}
}
