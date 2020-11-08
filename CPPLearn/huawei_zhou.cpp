#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <map>
#include <algorithm>

/*相同颜色的糖果，找三个拿糖果最多的*/
/*
void output(int color, int sum, vector<int> &arr);
int main()
{
	int Num = 0;
	cin >> Num; cin.ignore();
	vector<pair<int,int>> arr1;
	vector<pair<int, int>> arr2;
	for (int i = 0; i < Num; ++i)
	{
		int n = 0; int color = 0;
		cin >> n >> color;
		if (color == 1)
		{
			arr1.push_back(make_pair( n, i+1));
		}
		else
		{
			arr2.push_back(make_pair(n, i+1));
		}
	}
	if (arr1.size() < 3 && arr2.size() < 3)
	{
		cout << "null" << endl;
		return 0;
	}
	sort(arr1.rbegin(), arr1.rend());
	sort(arr2.rbegin(), arr2.rend());
	vector<int> locat;  vector<int> locat2;
	int res = 0; 	int res2 = 0;
	if (arr1.size() < 3)
	{
		for (int i = 0; i < 3; ++i)
		{
			res += arr2[i].first;
			locat.push_back(arr2[i].second);
		}
		sort(locat.begin(), locat.end());
		output(2, res, locat);
		return 0;
	}
	if (arr2.size() < 3)
	{
		for (int i = 0; i < 3; ++i)
		{
			res += arr1[i].first;
			locat.push_back(arr1[i].second);
		}
		sort(locat.begin(), locat.end());
		output(1, res, locat);
		return 0;
	}

	for (int i = 0; i < 3; ++i)
	{
		res += arr1[i].first;
		locat.push_back(arr1[i].second);
	}
	for (int i = 0; i < 3; ++i)
	{
		res2 += arr2[i].first;
		locat2.push_back(arr2[i].second);
	}

	sort(locat.begin(), locat.end());
	sort(locat2.begin(), locat2.end());
	if (res > res2)	
	{
		output(1, res, locat);
	}
	else if(res < res2)
	{
		output(2, res2, locat2);
	}
	else //比较坐标
	{
		if (locat[0] > locat2[0])
		{
			output(2, res2, locat2);
		}
		else
		{
			output(1, res, locat);
		}
	}
	return 0;
}

void output(int color, int sum, vector<int> &arr)
{
	cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
	cout << color << endl;
	cout << sum << endl;
}
*/

//2.
class Solution {
private:
	void dfs(vector<vector<char>>& grid, int r, int c) {
		int nr = grid.size();
		int nc = grid[0].size();

		grid[r][c] = 'H';	//只要是被连起来的地方，都改成H  之后上下左右遍历
		if (r - 1 >= 0 && grid[r - 1][c] == 'S') dfs(grid, r - 1, c);
		if (r + 1 < nr && grid[r + 1][c] == 'S') dfs(grid, r + 1, c);
		if (c - 1 >= 0 && grid[r][c - 1] == 'S') dfs(grid, r, c - 1);
		if (c + 1 < nc && grid[r][c + 1] == 'S') dfs(grid, r, c + 1);
	}

public:
	int numIslands(vector<vector<char>>& grid) {
		int nr = grid.size();
		if (!nr) return 0;
		int nc = grid[0].size();

		int num_islands = 0;
		for (int r = 0; r < nr; ++r) {
			for (int c = 0; c < nc; ++c) {
				if (grid[r][c] == 'S') {	//找剩余的S
					++num_islands;
					dfs(grid, r, c);
				}
			}
		}

		return num_islands;
	}
};



int main()
{
	int m = 0, n = 0;
	scanf("%d,%d", &m, &n);
	/*cin >> m >> n;*/ cin.ignore();
	string str;
	vector<vector<char>> matrix;
	for (int i = 0; i < m; ++i)
	{
		vector<char> tmp;
		for (int j = 0; j < n; ++j)
		{
			char ch;
			cin >> ch;
			tmp.push_back(ch);
		}
		matrix.push_back(tmp);
	}
	Solution su;
	cout << su.numIslands(matrix) << endl;


	return 0;
}


//作者：LeetCode
//链接：https ://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-shu-liang-by-leetcode/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。