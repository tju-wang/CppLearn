#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <algorithm>

/*
2020 3.4 华为机试  第一道
矩阵翻转：
输入描述：
(1) 输入第一行一个正整数N (0<N<10)
(2) 接下来N行每行N个整数用空格分开，为方阵的数据
(3) 接下来一行一个正整数M (0<=M<=10000)
说明：不用考虑异常输入，所有输入都是正常的，严格遵从取值范围
输出描述：
(1) N行，每行N个整数，用空格分开，为旋转后的数据
————————————————
版权声明：本文为CSDN博主「酷酷的橙007」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/xiecheng1995/article/details/104773534/

*/

void reverseMatrix(vector<vector<int>> vec, vector<vector<int>> &ret);
int main()
{
	int N = 0,M = 0;
	while (cin >> N)
	{
		vector<vector<int> > vec;
		vector<int> temp;
		
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				int input;
				cin >> input;
				temp.push_back(input);
			}
			vec.push_back(temp);
			temp.clear();
		}
		cin >> M;
		int tim = M % 4;
		vector<vector<int> > ret;
		for (int i = 0; i < tim; ++i)
		{
			reverseMatrix(vec, ret);
			vec.clear();
			vec = ret;
		}
		ret.clear();
		ret = vec;
		for (int i = 0; i < (int)ret.size(); ++i)
		{
			for (int j = 0; j < (int)ret[0].size(); ++j)
			{
				if(j!= (int)ret[0].size()-1)
					cout << ret[i][j] << ' ';
				else
				{
					cout << ret[i][j] << endl;
				}
			}
		}
		
		
	}
	return 0;
}
void reverseMatrix(vector<vector<int>> vec, vector<vector<int>> &ret)
{
	int len = vec.size();	//行数
	vector<int> temp(len,0);
	ret.clear();

	for (int i = 0; i < len; ++i)
	{
		ret.push_back(temp);
	}
	for (int i = len - 1; i >= 0; --i)
	{
		//取出第i行
		for (int j = 0; j < len; ++j)
		{
			ret[j][len - i - 1] = vec[i][j];
		}
	}
}
