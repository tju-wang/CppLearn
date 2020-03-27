#include <iostream>
using namespace std;
#include <string>
#include <sstream>
#include <algorithm>
/*
输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数
*/

int main()
{
	int num = 0;
	cin >> num;
	string str = to_string(num);
	for (string::iterator it = str.end(); it != str.begin();)
	{
		--it;
		for (string::iterator ip = it; ip != str.begin();)
		{
			ip--;
			if ((*ip) == (*it))	//删除ip
			{
				if (ip == str.begin())
				{
					ip = str.erase(ip);
					break;
				}
				else
				{
					ip = str.erase(ip) - 1;
				}
			}
		}
	}
	//倒置
	reverse(str.begin(), str.end());
	//将string转化为int
	int ret;
	stringstream ss(str);//构造字符串流对象，初始化为s
	ss >> ret;//输出流的内容到ans
	cout << ret << endl;
	return 0;

}
