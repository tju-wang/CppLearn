#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <algorithm>

//1.检验用户名
bool isac(char ch)
{
	if (ch >= 'a' && ch <= 'z')
	{
		return true;
	}
	else if(ch>='A' && ch<='Z')
	{
		return true;
	}
	else if (ch >= '0' && ch <= '9')
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isAccept(string str)
{
	int len = str.size();
	if (len < 2 || len > 20) return false;
	bool haveAlpha = true;
	bool haveNum = false;
	if (!isalpha(str[0]))
		return false;
	for (int i = 0; i < len; ++i)
	{
		if (isac(str[i]) == false)
			return false;
		if (isdigit(str[i]))
		{
			haveNum = true;
		}
		else if (isalpha(str[i]))
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return haveAlpha&haveNum;

}
int main()
{
	int input = 0;

	cin >> input;
	cin.ignore();
	for (int i = 0; i < input; ++i)
	{
		string str;
		getline(cin, str);
		bool res = isAccept(str);
		if (res)
			cout << "Accept" << endl;
		else
		{
			cout << "Wrong" << endl;
		}	
	}
	return 0;
}

//2.跑腿

//bool cmp(pair<int, int> p1, pair<int, int> p2)
//{
//	if (p1.first == p2.first)
//	{
//		return p1.second > p2.second ? false : true;
//	}
//	return p1.first > p2.first ? true : false;
//}
//int main()
//{
//	int n = 0, m = 0;
//	cin >> n >> m;
//	//输入数据
//	vector<int> tmp(2, 0);
//	vector<pair<int,int>> res(n,make_pair(0,0));
//	vector<int> ret;
//	for (int i = 0; i < n; ++i)
//	{
//		cin.ignore();
//		cin >> tmp[0] >> tmp[1];
//		int v = tmp[0] + tmp[1] * 2;
//		res[i].first = v;
//		res[i].second = i;
//	}
//	sort(res.begin(), res.end(),cmp);	//可以改一下sort函数
//	//reverse(res.begin(), res.end());
//	for (int i = 0; i < m; ++i)
//	{
//		ret.push_back(res[i].second + 1);
//	}
//	sort(ret.begin(), ret.end());
//	for (int i = 0; i < m; ++i)
//	{
//		if(i!=m-1)
//			cout << ret[i]<< ' ';
//		else
//		{
//			cout << ret[i]<< endl;
//		}
//	}
//	return 0;
//}



//取重物
//int main()
//{
//	int n = 0;
//	cin >> n;
//	cin.ignore();
//	vector<int> in(n,0);
//	vector<int> shunxu(n,0);
//	vector<int> weightSum(n, 0);
//	int sum = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> in[i];
//		sum += in[i];
//		weightSum[i] = sum;
//	}
//	cin.ignore();
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> shunxu[i];
//	}
//	cin.ignore();
//	int left = 0, right = 0;
//	vector<int> res(n, 0);
//	for (int i = 0; i < n; ++i)
//	{
//		int num = shunxu[i] - 1;
//		sum = sum - in[num];
//		for (int j = num; j < n; ++j)
//		{
//			weightSum[j] -= in[num];
//		}
//		if (num - 1 >= 0)
//			left = weightSum[num - 1];
//		else
//			left = 0;
//		right = sum - left;
//		res[i] = left > right ? left : right;
//		cout << res[i] << endl;
//	}
//	
//
//	return 0;
//}
