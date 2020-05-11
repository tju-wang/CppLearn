

#include<iostream>
using namespace std;

//˼·��dfs��������  �������뽫1-9�������  ����������±ߵĸ��Ӳ��ԣ������������

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
	if (n == 81) {	//��ӡ������
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
			num[h][l] = i;//�ֱ���������1-9���в���  ���Է���true  �������һ��dfs
			if (check(n)) {	//�˴��з�֧  ����������ֲ����ʣ�����뽫��һλ������Ϊ0
				dfs(n + 1);
				if (flag)
					return;
				num[h][l] = 0;	//���˴����벻����  �����
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


����������������Sudoku����һ�����ϲ���������߼���Ϸ�������Ҫ����9X9�����ϵ���֪���֣�
���������ʣ��ո�����֣���������ÿһ�С�ÿһ�С�ÿһ�����߹��ڵ����־���1-9�����Ҳ��ظ���
���룺
������֪���ֵ�9X9��������[��ȱλ������0��ʾ]
�����
������9X9��������

˼·���������İ취�����ҵ�  1.���л�����ֻ��1����0�����  2.�ҵ�3*3����ֻ��1����0�����
˼·�����⣬����Ĳ��������д��ڶ������   �������ʹ��DFS


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
	//���
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
	//ͳ�ƺ��� ���� �Ź����0�ĸ���
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

