#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
/*
原理：ip地址的每段可以看成是一个0-255的整数，把每段拆分成一个二进制形式组合起来，然后把这个二进制数转变成
一个长整数。
*/

unsigned ipTodec(string &str);
void decToIp(unsigned num, string &str);
int main()
{
	string ip;
	string decStr;
	unsigned dec = 0;
	while (getline(cin,ip))
	{
		getline(cin, decStr);
		stringstream sss(decStr);
		sss >> dec;
		unsigned ret = 0;
		string retIp;
		
		ret = ipTodec(ip);
	
		decToIp(dec, retIp);
		cout << ret << endl;
		cout << retIp << endl;
		ip.clear();
		retIp.clear();
	}
	return 0;
}

unsigned ipTodec(string &str)
{
	unsigned ret = 0;
	if (str.length() == 0)
		return 0;
	str.push_back('.');	//末尾加一个.  之后拆分
	vector<unsigned> num;
	unsigned numTemp;
	string temp;
	for (auto it = str.begin(); it != str.end(); ++it)
	{
		if ((*it) == '.')
		{
			stringstream ss(temp);
			ss >> numTemp;
			num.push_back(numTemp);
			temp.clear();
		}
		else
		{
			temp.push_back((*it));
		}
	}
	if (num.size() == 4)
	{
		return (num[0] * 256*256*256 + num[1] * 256*256 + num[2] * 256 + num[3]);
	}
	return 0;
}

void decToIp(unsigned num,string &str)
{
	unsigned temp;
	vector<string> arr;
	for (int i = 0; i < 4; ++i)
	{
		temp = num % 256;
		arr.push_back(to_string(temp));
		if(i!=3)
			arr.push_back(".");
		num /= 256;
	}
	reverse(arr.begin(), arr.end());
	str.clear();
	for (auto it = arr.begin(); it != arr.end(); ++it)
	{
		str += (*it);
	}
}