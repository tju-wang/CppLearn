#include <iostream>
using namespace std;

#include <vector>
#include <stack>
/*
��Ŀ����
ʥ���ڵ��ˣ��Ǳ�����k��С���ѣ�ʥ�����˿ڴ������n���޲���С������ʥ�����˴�����n���޲�������ָ�k��С���ѵķַ�����
����n��k�������ַ���������ö�����еķַ�
�������
��һ�У�������������n(0 <= n <= 10)��k��0<= k<= 10), n ��ʾ�����������k��ʾС���ѵ�����
���԰���
���룺3 2

�����
4
***|
**|*
*|**
|***
��������������������������������
��Ȩ����������ΪCSDN���������ĳ�007����ԭ�����£���ѭ CC 4.0 BY-SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/xiecheng1995/article/details/104773534/

ʹ��dfs����  ��������
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
		//������
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
	//����Ϊ��0���˷��� 0-m������
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

