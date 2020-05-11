/*
思路：dfs搜索  填入可能的所有数字  依次为每个需要填入的格子测试1-9  不符合再dfs退回
*/

#include<iostream>
using namespace std;

#include <vector>


class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		bool f = false;
		dfs(0, board, f);
	};
	void dfs(int sort, vector<vector<char>>& board, bool &flag)
	{
		int raw = sort / 9;
		int col = sort % 9;
		char ch = '0';
		if (sort == 81)
		{
			flag = true;
			return;
		}
		if (board[raw][col] == '.')
		{
			for (int i = 0; i<9; ++i)
			{
				ch = '1';
				board[raw][col] = (ch + i);
				if (check((ch + i), sort, board))
				{
					dfs(sort + 1, board, flag);
					if (flag)
						return;
					board[raw][col] = '.';
				}
				board[raw][col] = '.';
			}
		}
		else
		{
			dfs(sort + 1, board, flag);
		}

	};
	//判断ch填在sort处  是否符合
	bool check(char ch, int sort, vector<vector<char>>& board)
	{
		int raw = sort / 9;
		int col = sort % 9;
		for (int i = 0; i<9; ++i)
			if (i != col && board[raw][i] == ch)
				return false;
		for (int i = 0; i<9; ++i)
			if (i != raw && board[i][col] == ch)
				return false;
		for (int i = (raw / 3) * 3; i<(raw / 3 + 1) * 3; ++i)
		{
			for (int j = (col / 3) * 3; j<(col / 3 + 1) * 3; ++j)
			{
				if ((i != raw || j != col) && board[i][j] == ch)
					return false;
			}
		}
		return true;
	}
};

int main()
{
	vector<vector<char>> vec;
	vector<char> temp;
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			char ch;
			cin >> ch;
			temp.push_back(ch);
		}
		vec.push_back(temp);
		temp.clear();
	}
	Solution so;
	so.solveSudoku(vec);

	return 0;
}
/*
5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9
*/