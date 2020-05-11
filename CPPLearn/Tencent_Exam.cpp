#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <stack>

//实现队列的5种操作
//计算两个集合中的最短距离

//用两个栈实现队列
//无限深度二叉树  计算编号为x的节点的  深度为k的祖先节点的编号

long long calc(long long &x, int k, int first, vector<long long> &vec, int flag);
void listt(vector<long long> &vec);
int retCen(long long x, vector<long long> &vec);

int main()
{
	int Q = 0;
	cin >> Q;
	cin.ignore();
	vector<long long> vec;
	listt(vec);
	long long x;
	int k;
	long long ret = 0;
	for (int i = 0; i < Q; ++i)
	{
		cin >> x >> k;
		cin.ignore();
		cout << calc(x, k, k, vec,0) << endl;
	}
	
	return 0;
}

void listt(vector<long long> &vec)
{
	long long num = 1;
	while (num <= 10e17)
	{
		vec.push_back(num);
		num = num * 2;
	}
	vec.push_back(num);
}

long long calc(long long &x, int k,int first, vector<long long> &vec,int flag)
{
	if (flag)
		return x;
	int xCen = retCen(x, vec);
	if (first >= xCen)
	{
		return -1;
	}
	first = 0;
	if (k == 1)
		return 1;
	if (xCen == k)
	{
		return x;
	}
	else if (xCen > k)
	{
		auto it = vec.begin();
		long long temp = 0;
		temp = x - *(it + xCen - 1);
		x = *(it + xCen - 2) + temp - 1;
		return calc(x, k, first, vec,flag);
	}
}

int retCen(long long x,vector<long long> &vec)
{
	for (auto i = vec.begin(); i != vec.end(); ++i)
	{
		if (x < (*i))
			return (i - vec.begin());
	}
	return 0;
}

/*
void stack_decode(stack<int> &st1, stack<int> &st2, string &input);
int main()
{
	int N = 0;
	cin >> N;
	string input;
	cin.ignore();
	stack<int> st1, st2;
	for (int j = 0; j < N; ++j)
	{
		getline(cin, input);
		stack_decode(st1,st2,input);


	}

	return 0;
}
void stack_decode(stack<int> &st1, stack<int> &st2, string &input)
{
	//分析动作
	if (input == "poll")
	{
		while (st1.size())
		{
			st2.push(st1.top());
			st1.pop();
		}
		st2.pop();
	}
	else if (input == "peek")
	{
		while (st1.size())
		{
			st2.push(st1.top());
			st1.pop();
		}
		
		cout << st2.top() << endl;
	}
	else	//add
	{
		string tmp;
		int flag = 0;
		for (auto it = input.begin(); it != input.end(); ++it)
		{
			if (flag)
				tmp.push_back((*it));
			if ((*it) == ' ')
				flag = 1;

		}
		stringstream ss(tmp);
		int itmp = 0;
		ss >> itmp;
		while (st2.size())
		{
			st1.push(st2.top());
			st2.pop();
		}

		st2.push(itmp);
	}

}
*/


/*
int main()
{
int N=0,num = 0;
cin >> N;
for (int i = 0; i < N; ++i)
{
cin >> num;
cin.ignore();
vector<pair<int,int>> vec1, vec2;
for (int j = 0; j < num; ++j)
{
int num1, num2;
cin >> num1 >> num2;
cin.ignore();
pair<int, int> pa;
pa.first = num1; pa.second = num2;
vec1.push_back(pa);
}
for (int j = 0; j < num; ++j)
{
int num1, num2;
cin >> num1 >> num2;
cin.ignore();
pair<int, int> pa;
pa.first = num1; pa.second = num2;
vec2.push_back(pa);
}
//存入两个集合  现在求集合的最短距离
}
return 0;
}

*/




/*
void decode(vector<int> &vec, string &input);

int main()
{
int T = 0, Q = 0;
cin >> T;
for (int i = 0; i < T; ++i)
{
cin >> Q;
vector<int> vec;
string input;
cin.ignore();
for (int j = 0; j < Q; ++j)
{
getline(cin, input);
decode(vec, input);
}
input.clear();
vec.clear();
}

return 0;
}

//有三个操作需要输出  其余的不需要
void decode(vector<int> &vec, string &input)
{
if (input == "TOP")
{
if (vec.size())
{
cout << (*(vec.begin())) << endl;
}
else
{
cout << -1 << endl;
}
}
else if (input == "POP")
{
if (vec.size())
{
vec.erase(vec.begin());
}
else
{
cout << -1 << endl;
}
}
else if (input == "SIZE")
{
cout << vec.size() << endl;
}
else if (input == "CLEAR")
{
vec.clear();
}
else //是PUSH
{
string tmp;
int flag = 0;
for (auto it = input.begin(); it != input.end(); ++it)
{
if (flag)
tmp.push_back((*it));
if ((*it) == ' ')
flag = 1;

}
stringstream ss(tmp);
int itmp = 0;
ss >> itmp;
vec.push_back(itmp);
}
}

*/
