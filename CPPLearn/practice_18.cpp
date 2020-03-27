#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <sstream>

/*
开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。
处理：
1、 记录最多8条错误记录，循环记录（或者说最后只输出最后出现的八条错误记录），
对相同的错误记录（净文件名称和行号完全匹配）只记录一条，错误计数增加；
2、 超过16个字符的文件名称，只记录文件的最后有效16个字符；
3、 输入的文件可能带路径，记录文件名称不能带路径。

*/
struct ErrData {
	int cnt = 0;
	string name;
	int pos = 0;
};
void SaveErrData(ErrData &tempErr, vector<ErrData> &errData, int &VecPos);
void errPrint(string &str,int &pos, vector<ErrData> &errData, int &vecPos);
void errPrint(string &str);
int main()
{
	string input;
	vector<ErrData> errData;
	int vecPos = 0;
	int pos = 0;
	while (cin>> input >> pos)
	{
		//if (input.size() > 3)
			errPrint(input,pos,errData,vecPos);
	}
	auto it = errData.end();
	if (errData.size() > 8)
		it = errData.end() - 8;
	else
	{
		it = errData.begin();
	}
	for (; it != errData.end(); ++it)
	{
		cout << (*it).name << ' ' << (*it).pos << ' ' << (*it).cnt << endl;
	}
	return 0;
}

void errPrint(string &str,int &pos,vector<ErrData> &errData,int &vecPos)
{
	int analyzeF = 0;
	
	ErrData tempData;
	string num;
	
	tempData.name = str;
	tempData.pos = pos;
	//将结构体存入
	char ch = '\\';
	for (int kk = 0; kk < 16; ++kk)
	{
		if (tempData.name.size() - 1 - kk >= 0)
		{
			if (tempData.name[tempData.name.size() - 1 - kk] == ch)
			{
				tempData.name = tempData.name.substr(tempData.name.size() - kk);
				break;
			}
		}

	}
	if (tempData.name.size() > 16)
	{
		tempData.name = tempData.name.substr(tempData.name.size() - 16);
	}
	SaveErrData(tempData, errData, vecPos);
}

void SaveErrData(ErrData &tempErr,vector<ErrData> &errData,int &VecPos)
{
	//1.先检查结构体中是否存在相同错误  2.检查是否存满8个  存满，替换  未存满，存入
	if (errData.size() == 0)
	{
		tempErr.cnt = 1;
		errData.push_back(tempErr);
		VecPos = errData.end() - errData.begin();
		return;
	}
	for (vector<ErrData>::iterator it = errData.begin(); it != errData.end(); ++it)
	{
		if ((*it).name == tempErr.name && (*it).pos == tempErr.pos)
		{
			tempErr.cnt =  ((*it).cnt)++;
	/*		errData.erase(it);
			errData.push_back(tempErr);*/
			return;
		}	
	}
	tempErr.cnt = 1;
	errData.push_back(tempErr);

}
