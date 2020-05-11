#include <iostream>
using namespace std;

#include <vector>
#include <stack>
/*
题目描述
圣诞节到了，城堡里有k个小朋友，圣诞老人口袋里带了n件无差别的小礼物，请帮圣诞老人处理：将n个无差别的礼物分给k个小朋友的分法问题
给定n和k，数出分法种数，并枚举所有的分法
输出描述
仅一行，包含两个整数n(0 <= n <= 10)和k（0<= k<= 10), n 表示礼物的数量，k表示小朋友的数量
测试案例
输入：3 2

输出：
4
***|
**|*
*|**
|***
————————————————
版权声明：本文为CSDN博主「酷酷的橙007」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/xiecheng1995/article/details/104773534/

使用dfs遍历  暴力搜索
*/
void dfs(int n, int &m, stack<int> &ret, vector<stack<int>> &res);

int main()
{
	int n = 0, m = 0;
	while (cin >> n >> m)
	{
		stack<int> st;
		vector<stack<int>> res;
		dfs(m, n, st, res);
		//结果输出
		cout << res.size() << endl;
		for (auto it = res.begin(); it != res.end(); ++it)
		{
			while ((*it).size() != 0)
			{
				for (int k = 0; k < (*it).top(); ++k)
				{
					cout << '*';
				}
				(*it).pop();
				if((*it).size() != 0)
					cout << '|';
				else
					cout << endl;
			}
				
		}
	}

	return 0;
}

void dfs(int n, int &m, stack<int> &ret,vector<stack<int>> &res)
{
	//依次为第0个人分配 0-m个礼物
	if (n == 1)
	{
		ret.push(m);
		res.push_back(ret);
		ret.pop();
		return;
	}
	for (int i = 0; i <= m; ++i)
	{
		ret.push(i);
		int k = m - i;
		dfs(n-1, k, ret,res);
		ret.pop();
	}
}

