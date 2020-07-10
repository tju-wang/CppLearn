#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

/*

//5.

bool isXiangsi(int i, int j);
int main()
{
	int n = 0;
	while (cin >> n)
	{
		cin.ignore();
		vector<int> seq;
		vector<bool> ret;
		for (int i = 0; i < n; ++i)
		{
			int temp = 0;
			cin >> temp;
			seq.push_back(temp);
			ret.push_back(false);
		}
		cin.ignore();
		for (int i = 0; i < n; ++i)
		{
			if(ret[i] == false)
				for (int j = i; j < n; ++j)
				{
					//如果找到  把j也置1
					if (isXiangsi(seq[i], seq[j]) == true)
					{
						ret[i] = true;
						ret[j] = true;
					}
				}
		}
		for (int i = 0; i < n; ++i)
		{
			if (ret[i] == true)
				cout << 1 << ' ';
			else
			{
				cout << -1 << ' ';
			}
		}
		cout << endl;
		
	}

	return 0;
}

bool isXiangsi(int i,int j)
{
	if ((i&j) != 0)
		return false;
	else
	{
		return true;
	}
}

*/


//3.避难所

int findBinansuo(int pos, vector<bool> &binansuo, int n);

int main()
{
	int n = 0,m=0;
	while (cin >> n >> m)
	{
		cin.ignore();
		//创建避难所
		vector<bool> binansuo;
		if (m == 0)
			continue;
		for (int i = 0; i < n; ++i)
		{
			binansuo.push_back(true);
		}
		for (int i = 0; i < m; ++i)
		{
			int op, pos;
			cin >> op >> pos;
			
			if (op == 1) //摧毁避难所
			{
				if (pos > 0 && pos <= n)
				{
					binansuo[pos - 1] = false;
				}
				
			}
			else if (op == 2)
			{
				if (pos > 0 && pos <= n)
				{
					cout << findBinansuo(pos, binansuo, n) << endl;
				}
			}
			cin.ignore();
		}
	}
	return 0;
}
int findBinansuo(int pos, vector<bool> &binansuo,int n)
{
	//只能从i到i+1
	int loca = pos;
	while (loca <= n)
	{
		if (binansuo[loca - 1] == true)
		{
			return loca;
		}
		else
			loca++;
	}
	return -1;
}


/*
//2.汉明距离
int CalcHanMinDistence(int i, int j);

int main()
{
	int n = 0;
	while (cin >> n)
	{
		cin.ignore();
		if (n <= 1)
		{
			cout << 0 << endl;
			continue;
		}
		vector<int> input;
		vector<int> ret;
		for (int i = 0; i < n; ++i)
		{
			int temp = 0;
			cin >> temp;
			input.push_back(temp);
		}
		//两两组合
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				int dis = 0;
				dis = CalcHanMinDistence(input[i], input[j]);
				ret.push_back(dis);
			}
		}
		int rett = *(max_element(ret.begin(), ret.end()));
		cout << rett << endl;
	}
	return 0;
}
int CalcHanMinDistence(int i, int j)
{
	int n = 0;
	n = 1;
	int ret = 0;
	while (i != 0 || j != 0)
	{
		if ((i & n) != (j & n))
			ret++;
		i = i & (~n);
		j = j & (~n);
		n = n << 1;
	}
	return ret;
}

*/

/*
//1.求蛋壳成绩奖的数量

int CalcNum(int n, int m);
void CalcDanke(vector<int> &kemu, vector<int> &ret, int n);
int main()
{
	int n = 0, m = 0;
	while (cin >> n >> m)
	{
		int ret = 0;
		cin.ignore();
		if (n == 0 || m == 0)
			cout << 0 << endl;
		else
		{
			ret = CalcNum(n, m);
			if (ret > n)
				cout << "error";
			else
				cout << ret << endl;
		}
		
	}

	return 0;
}
int CalcNum(int n,int m)
{
	vector<vector<int>> matrix;
	vector<int> temp;
	vector<int> ret;
	for (int i = 0; i < n; ++i)
	{
		ret.push_back(0);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int ch = 0;
			cin >> ch;
			temp.push_back(ch);
		}
		cin.ignore();
		matrix.push_back(temp);
		temp.clear();
	}
	//重组数据 然后求最大值
	vector<vector<int>> kemu;
	temp.clear();
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			temp.push_back(matrix[j][i]);
		}
		kemu.push_back(temp);
		temp.clear();
		//计算单科奖
		CalcDanke(kemu[i], ret, n);
	}
	int num = 0;
	for (int i = 0; i < n; ++i)
	{
		if (ret[i] != 0)
			num++;
	}
	return num;
}

void CalcDanke(vector<int> &kemu,vector<int> &ret,int n)
{
	int r = 0;
	int max = kemu[0];
	vector<int> student;
	for (int i = 0; i < n; ++i)
	{
		if (max < kemu[i])
		{
			max = kemu[i];
			student.clear();
			student.push_back(i);
		}
		else if (max == kemu[i])
		{
			student.push_back(i);
		}
	}
	for (int i = 0; i < (int)student.size(); ++i)
	{
		ret[student[i]] ++;
	}
}

*/