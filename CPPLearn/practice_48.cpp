#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <map>
/*
题目描述：
xxx=lyf/${ttt}/test 表示shell环境下的${yyy}，编译时转换为 xxx
ttt=www,
yyy=seeyou
目标aa=/aaa/${xxx}/bbb/${yyy}/ccc 输出编译以后的结果
*/
bool isNeedReplace(string tar);
void replace(string &tar, vector<pair<string, string>> vec);
int main()
{
	int num = 0;
	while (cin >> num)
	{
		cin.ignore();
		vector<pair<string,string>> vec;
		for (int i = 0; i < num; ++i)
		{
			string temp;
			getline(cin, temp);
			pair<string, string> pa;
			pa.first = temp.substr(0, temp.find('=')); //提取从0到n的字符串  string str = "AABBCC"; str.substr(0,3) == AAB
			pa.second = temp.substr(temp.find('=')+1, temp.size() - temp.find('=') -1);	//find函数返回的是序号，如果没有找到  则返回-1
			vec.push_back(pa);
		}
		string tar = (*(vec.end() - 1)).second;	//设定输出目标
		while (isNeedReplace(tar))
		{
			replace(tar, vec);
		}
		cout << tar << endl;
	}
	return 0;
}

void replace(string &tar, vector<pair<string, string>> vec)
{
	int beg, end;
	beg = tar.find("&{");
	end = tar.find('}');
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		if ((*it).first == tar.substr(beg+2, end - beg-2))	//相当于  去掉了&{  和 }  substr取字符串的区间是左闭右开
		{
			tar.erase(beg, end-beg+1);	//擦除  从beg开始的  因为擦除也是左闭右开  所以需要+1
			tar.insert(beg, (*it).second);	//插入  从beg位置开始插入  序号从0开始，实际上是插到了序号字符的后边一个
		}
	}
}

bool isNeedReplace(string tar)
{
	if (tar.find("&{") != tar.npos && tar.find('}') != tar.npos)
		return 1;
	else
		return 0;
}