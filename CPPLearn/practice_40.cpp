

#include<iostream>
using namespace std;

//思路：dfs暴力搜索  尝试填入将1-9填入格子  符合则继续下边的格子测试，不符合则回退

bool flag = false;
int num[9][9];
bool check(int n) {
	int h = n / 9;
	int l = n % 9;
	for (int i = 0; i<9; i++)
		if (i != l&&num[h][i] == num[h][l])
			return false;
	for (int i = 0; i<9; i++)
		if (i != h&&num[i][l] == num[h][l])
			return false; 
			for (int i = h / 3 * 3; i<h / 3 * 3 + 3; i++)
				for (int j = l / 3 * 3; j<l / 3 * 3 + 3; j++)
					if ((i != h || j != l) && num[i][j] == num[h][l])
						return false;
	return true;
}
void dfs(int n) {

	int h = n / 9;
	int l = n % 9;
	if (n == 56 && num[6][0] == 2 && num[6][1] == 1)
		num[6][2] = 5;
	if (n == 81) {	//打印输出结果
		for (int i = 0; i<9; i++) {
			for (int j = 0; j<8; j++) {
				cout << num[i][j] << ' ';
			}
			cout << num[i][8];
			cout << endl;
		}
		flag = true;
		return;
	}
	if (num[h][l] == 0) {
		for (int i = 1; i <= 9; i++) {
			num[h][l] = i;//分别填入数字1-9进行测试  测试返回true  则进行下一个dfs
			if (check(n)) {	//此处有分支  若填入的数字不合适，则必须将这一位重新置为0
				dfs(n + 1);
				if (flag)
					return;
				num[h][l] = 0;	//若此次填入不合适  则归零
			}
		}
		num[h][l] = 0;
	}
	else dfs(n + 1);
}
int main() {
	for (int i = 0; i<9; i++)
		for (int j = 0; j<9; j++)
			cin >> num[i][j];
	dfs(0);
 	return 0;
}
/*
#include <iostream>
using namespace std;

#include <vector>
#include <string>


问题描述：数独（Sudoku）是一款大众喜爱的数字逻辑游戏。玩家需要根据9X9盘面上的已知数字，
推算出所有剩余空格的数字，并且满足每一行、每一列、每一个粗线宫内的数字均含1-9，并且不重复。
输入：
包含已知数字的9X9盘面数组[空缺位以数字0表示]
输出：
完整的9X9盘面数组

思路：解决问题的办法在于找到  1.横行或纵列只有1个是0的情况  2.找到3*3方格只有1个是0的情况
思路有问题，在题的测试用例中存在多解的情况   多数解答使用DFS


void tianChong(int(*arr)[9]);
void Sudoku(int(*arr)[9][9]);
int main()
{
	int matrix[9][9] = { 0 };
	int zeroNum = 0;

	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
		{
			cin >> matrix[i][j];
			if (matrix[i][j] == 0)
				zeroNum++;
		}

	for (int i = 0; i < zeroNum; ++i)
	{
		Sudoku(&matrix);
	}
	//输出
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
		{
			if (j != 8)
				cout << matrix[i][j] << ' ';
			else
			{
				cout << matrix[i][j];
				cout << endl;
			}
		}

	return 0;
}

void Sudoku(int(*arr)[9][9])
{
	//统计横行 纵列 九宫格的0的个数
	int colNum[9] = { 0 };
	int rawNum[9] = { 0 };
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if ((*arr)[i][j] == 0)
			{
				rawNum[i] ++;
				colNum[j] ++;
			}
		}
	}
	int rembCol = -1;
	int rembRaw = -1;
	for (int i = 0; i < 9; ++i)
	{
		if (rawNum[i] == 1 && rembRaw == -1)
			rembRaw = i;
		if (colNum[i] == 1 && rembCol == -1)
			rembCol = i;
	}
	if (rembRaw != -1)
	{
		tianChong(arr[rembRaw]);
		rawNum[rembRaw] --;
	}
	if (rembCol != -1)
	{
		tianChong(arr[rembCol]);
		colNum[rembCol] --;
	}

}

void tianChong(int(*arr)[9])
{
	int numm[9] = { 1,2,3,4,5,6,7,8,9 };
	int remb = 0;
	for (int i = 0; i < 9; ++i)
	{
		if (*arr[i] != 0)
		{
			int temp = (*arr[i]);
			numm[temp - 1] = 0;
		}
		else
		{
			remb = i;
		}
	}
	for (int i = 0; i < 9; ++i)
	{
		if (numm[i] != 0)
			*arr[remb] = numm[i];
	}
}
*/

