#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

/*
路径规划问题 1-6城市  计算出差的最短时间

*/
int timeTable[6][6] = { 0,2,10,5,3,-1, -1,0,12,-1,-1,10, -1,-1,0,-1,7,-1, 2,-1,-1,0,2,-1, 4,-1,-1,1,0,-1, 3,-1,1,-1,2,0 };
bool isHere(int k, vector<int> &arr);
void SearchPath(int source, int target, vector<int> &path, vector<vector<int> > &ret);
int main()
{
	int target = 0, errCity = 0;
	cin >> target;
	cin >> errCity;
	if (target < 0 || target>6 && (errCity < 0 || errCity >6))
	{
		cout << 1000 << endl;
		cout << '[' << ']' << endl;
	}
	//处理有雾的情况
	target = target - 1;
	if (errCity)
	{
		errCity = errCity - 1;
		for (int i = 0; i < 6; ++i)
		{
			timeTable[errCity][i] = -1;
			timeTable[i][errCity] = -1;
		}
	}
		
	int person = 5-1;	//最初在城市5
	vector<int> path;
	vector<vector<int> > ret;
	SearchPath(person, target, path, ret);
	int pathNum = ret.size();
	if(pathNum)
	{
		int minTime = 1000; int cnt = 0;
		for (int i = 0; i < pathNum; ++i)
		{
			int t = 0;
			int numm = ret[i].size();
			for (int j = 0; j < numm -1; ++j)	{
				//查询时间
				t += timeTable[(ret[i][j])][ret[i][j+1]];
			}
			if (minTime > t)	{
				minTime = t;
				cnt = i;
			}
		}
		//输出
		cout << minTime << endl;
		cout << '[';
		int lenn = ret[cnt].size();
		for (int k = 0; k < (lenn); ++k)
		{
			cout << ret[cnt][k]+1;
			if (k != lenn - 1)
				cout << ',';
		}
		cout << ']'<<endl;
		return 0;
	}
	cout << 1000 << endl;
	cout << '[' << ']' << endl;
	return 0;
}

void SearchPath(int source, int target, vector<int> &path, vector<vector<int> > &ret)
{
	//查找可以到达的地点
	path.push_back(source);
	if (source == target)
	{
		ret.push_back(path);
		if(path.size()!=0)
			path.pop_back();
		return;
	}
		

	for (int i = 0; i < 6 && source!=target; ++i)
	{
		if (timeTable[source][i] != 0 && timeTable[source][i] != -1)
		{
			if(!isHere(i, path))
				SearchPath(i, target, path, ret);
		}
	}
	if(path.size()!=0)
		path.pop_back();
}

bool isHere(int k, vector<int> &arr)
{
	for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
	{
		if ((*it) == k)
			return true;
	}
	return false;
}

