#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
/*
��Ŀ����������ĵ�һ����һ������n��n����һ�����������������ĵ�2����n+1�д���һ�������ÿһ�е�Ԫ�أ�
Ԫ��ֻ����0��1����ÿ�г�����ͬ��������þ�����Ԫ��ȫΪ1������������Ӿ�������������ľ�������ǵ��о���͵��о���
˼·��dfs

*/

void string2vec(string str, vector<int> &vec);
bool judge(int row, int col, int offset, vector<vector<int>> &matrix);
void calc(int row, int col, vector<int> &vec, vector<vector<int>> &matrix);
int rows;
int cols;
int main()
{

	int N = 0;
	while (cin >> N)
	{
		cin.ignore();	//����cin��ߵĻ��з�
		vector<vector<int>> matrix;
		vector<int> temp;
		string t;
		for (int i = 0; i < N; ++i)
		{
			getline(cin, t);
			//��tת��Ϊ����
			string2vec(t, temp);
			matrix.push_back(temp);
			temp.clear();
		}
		rows = N;  cols = matrix[0].size();
		vector<int> vec;
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				calc(i, j, vec, matrix);
			}
		}
		cout << *(max_element(vec.begin(), vec.end())) << endl;
		
	}
	return 0;
}
//��˳������  ֻ�����ұߺ��±ߵķ���  ��¼
//�Ż�����  1.�ڼ��������ֻ��¼���ֵ�ͺ�  2.rem�������Դӷ���max��ʼ�ݼ�  ����������жϳ��˴η���ʱ�������ֵ�����
void calc(int row, int col, vector<int> &vec, vector<vector<int>> &matrix)
{
	int res = matrix[row][col];
	int rem = 0;
	while (res)
	{
		rem += 1;
		if (col + rem < cols && row + rem < rows)
			res = judge(row, col, rem, matrix);
		else
			break;
	}

		vec.push_back((rem)*(rem));
}

//ֻ�ж�ƫ�Ʋ���
bool judge(int row, int col, int offset, vector<vector<int>> &matrix)
{
	int res = 1;
	for (int i = 0; i < offset && res==1; ++i)
	{
		res &= matrix[row + offset][col + i];
		res &= matrix[row + i][col + offset];
	}
	res &= matrix[row + offset][col + offset];
	return (bool)res;
}


void string2vec(string str, vector<int> &vec)
{
	string temp;
	vec.clear();
	for (auto it = str.begin(); it != str.end(); ++it)
	{
		vec.push_back((*it) - '0');
	}
}