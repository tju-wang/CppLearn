#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <algorithm>
#include <map>

//1.求字符串存在的所有组合
//2.求秘钥  dfs  最后排序
//3.求最短路径  带记忆的dfs

/*

//3.  88.89%
#define MAXVAL (int)(0xFFFF)
void dfs(int now, int k, int end, int path, vector<int> &pathSum, vector<vector<pair<int, int>>> &vecR);
int main()
{
	int K = 0, N = 0, R = 0;
	while (cin >> K >> N >> R)
	{
		vector<vector<pair<int,int>>> vecR;
		vector<pair<int, int>> temp;
		//建立路的matrix
		pair<int, int> pa;
		pa.first = MAXVAL; pa.second = 0;
		for (int i = 0; i < N; ++i)
			temp.push_back(pa);
		for (int i = 0; i < N; ++i)
			vecR.push_back(temp);
		int S, D, L, T;
		for (int i = 0; i < R; ++i)
		{
			cin.ignore();
			cin >> S >> D >> L >> T;
			S -= 1;
			D -= 1;
			vecR[S][D].first = T;
			vecR[S][D].second = L;
		}
		vector<int> pathSum;
		dfs(0, K, N-1, 0, pathSum, vecR);
		if (pathSum.size() == 0)
			cout << -1 << endl;
		else
		{
			sort(pathSum.begin(), pathSum.end());
			cout << pathSum[0] << endl;
		}

	}
	return 0;
}

void dfs(int now,int k,int end,int path, vector<int> &pathSum, vector<vector<pair<int, int>>> &vecR)
{
	if (now == end || k<0)
	{
		if(k>0)
			pathSum.push_back(path);
		return;
	}
	for (int i = 0; i <= end; ++i)
	{
		if (vecR[now][i].first != MAXVAL)
		{
			int val = vecR[now][i].first;
			vecR[now][i].first = MAXVAL;
			dfs(i, k - val, end, path + vecR[now][i].second, pathSum, vecR);
			vecR[now][i].first = val;
		}
	}

}
*/



//2.

void deleteChar(string &str, int k, string &rem);
int main()
{
	string input;
	int k = 0;
	while (getline(cin, input))
	{
		cin >> k;
		cin.ignore();
		string rem;
		deleteChar(input, k, rem);
		if (rem.size())
			cout << rem << endl;
		else
		{
			cout << endl;
		}
	}

	return 0;
}

void deleteChar(string &str, int k,string &rem)
{
	if (k == 0)
	{
		rem = str;
		return;
	}
	int flag = 0;
	for (auto it = str.begin(); it != str.end() - 1; ++it)
	{
		if ((*it) <= (*(it + 1)))
			continue;
		if ((*it) > (*(it + 1)))
		{
			str.erase(it);
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		str.erase(str.end() - 1);
	deleteChar(str, k - 1, rem);
}




/*
//1.
void dfsFind(string &str, int beg, int end, vector<string> &ret, int num, int &cnt);
void delteChong(vector<string> &ret);
//bool isHere(vector<string> vec, string str);
int main()
{
	string input;
	while (getline(cin, input))
	{
		if (input.size() == 0)
			cout << 0 << endl;
		vector<string> ret;
		int num = 1;
		int cnt = 0;
		int len = input.size();
		for (int i = 0; i < len; ++i)
		{
			num *= len;
			len--;
		}
		dfsFind(input, 0, input.size(),ret,num,cnt);
		delteChong(ret);
		cout << ret.size() << endl;
	}

	return 0;
}
//交换  求出所有可能的情况
void dfsFind(string &str, int beg, int end,vector<string> &ret,int num,int &cnt)
{
	if (beg == end)
	{
		//if(isHere(ret,str))
		ret.push_back(str);
		if (cnt == (int)num / 2)
		{
			delteChong(ret);
		}
		
	}
		
	for (int i = beg; i < end; ++i)
	{
		swap(str[beg], str[i]);
		cnt++;
		dfsFind(str, beg + 1, end,ret,num,cnt);
		swap(str[beg], str[i]);
	}
}

//在中间去重
void delteChong(vector<string> &ret)
{
	sort(ret.begin(), ret.end());
	ret.erase(unique(ret.begin(), ret.end()), ret.end());
}

//查找str是不是在vector中
//bool isHere(vector<string> vec, string str)
//{
//	for (auto it = vec.begin(); it != vec.end(); ++it)
//	{
//		if (str == (*it))
//			return false;
//	}
//	return true;
//}

*/

/*
//1.
void dfsFind(string &str, int beg, int end, vector<string> &ret);
void delteChong(vector<string> &ret);
//bool isHere(vector<string> vec, string str);
int main()
{
string input;
while (getline(cin, input))
{
if (input.size() == 0)
cout << 0 << endl;
vector<string> ret;

dfsFind(input, 0, input.size(),ret);
delteChong(ret);
cout << ret.size() << endl;
}

return 0;
}
//交换  求出所有可能的情况
void dfsFind(string &str, int beg, int end,vector<string> &ret)
{
if (beg == end)
{
//if(isHere(ret,str))
ret.push_back(str);
}

for (int i = beg; i < end; ++i)
{
swap(str[beg], str[i]);
dfsFind(str, beg + 1, end,ret);
swap(str[beg], str[i]);
}
}

//在中间去重
void delteChong(vector<string> &ret)
{
sort(ret.begin(), ret.end());
ret.erase(unique(ret.begin(), ret.end()), ret.end());
}

*/
