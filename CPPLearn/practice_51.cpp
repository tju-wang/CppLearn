#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
/*
题目描述：输入的第一行是一个数字n，n代表一个矩阵的行数；输入的第2到第n+1行代表一个矩阵的每一行的元素，
元素只能是0或1，且每行长度相同。请输出该矩阵中元素全为1的最大正方形子矩阵的面积。输入的矩阵可能是单行矩阵和单列矩阵。
思路：dfs

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
		cin.ignore();	//丢掉cin后边的换行符
		vector<vector<int>> matrix;
		vector<int> temp;
		string t;
		for (int i = 0; i < N; ++i)
		{
			getline(cin, t);
			//将t转化为数字
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
//按顺序搜索  只搜索右边和下边的方格  记录
//优化方向  1.在计算过程中只记录最大值就好  2.rem变量可以从方格max开始递减  这样会更快判断出此次方格时候会比最大值面积大
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

//只判断偏移部分
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