#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

/*
掷骰子
1.处理字符串  定义动作
2.定义每次变化的内容  翻转一次 两个不变 四个变
3.循环
*/

int state[6] = { 1,2,3,4,5,6 };
int newState[6] = { 1,2,3,4,5,6 };
char CharSet[6] = { 'L','R','F','B','A','C' };


int retSetNum(char ch);
void Rever(int cmd, int *pState);

int main()
{
	string input;
	if (getline(cin, input))
	{
		int kk = 0,cmd=0;
		while (input[kk] != '\0')
		{
			cmd = retSetNum(input[kk]);
			Rever(cmd, state);
			++kk;
		}
		for (int i = 0; i < 6; ++i)
		{
			cout << state[i];
		}
		cout << endl;
	}

	return 0;
}

int retSetNum(char ch)
{
	for (int i = 0; i < 6; i++)
	{
		if (ch == CharSet[i])
			return i;
	}
	return -1;	//不是指令集内容

}
void Rever(int cmd, int *pState)
{
	int tempState[6];
	for (int i = 0; i < 6; ++i)
	{
		tempState[i] = pState[i];
	}
	switch (cmd)
	{
	case 0:	//L
	{
		pState[0] = tempState[4];
		pState[1] = tempState[5];
		pState[2] = tempState[2];
		pState[3] = tempState[3];
		pState[4] = tempState[1];
		pState[5] = tempState[0];
	}break;
	case 1:	//R
	{
		pState[0] = tempState[5];
		pState[1] = tempState[4];
		pState[2] = tempState[2];
		pState[3] = tempState[3];
		pState[4] = tempState[0];
		pState[5] = tempState[1];
	}break;
	case 2:	//F
	{
		pState[0] = tempState[0];
		pState[1] = tempState[1];
		pState[2] = tempState[4];
		pState[3] = tempState[5];
		pState[4] = tempState[3];
		pState[5] = tempState[2];
	}break;
	case 3:	//B
	{
		pState[0] = tempState[0];
		pState[1] = tempState[1];
		pState[2] = tempState[5];
		pState[3] = tempState[4];
		pState[4] = tempState[2];
		pState[5] = tempState[3];
	}break;
	case 4:	//A
	{
		pState[0] = tempState[3];
		pState[1] = tempState[2];
		pState[2] = tempState[0];
		pState[3] = tempState[1];
		pState[4] = tempState[4];
		pState[5] = tempState[5];
	}break;
	case 5:	//C
	{
		pState[0] = tempState[2];
		pState[1] = tempState[3];
		pState[2] = tempState[1];
		pState[3] = tempState[0];
		pState[4] = tempState[4];
		pState[5] = tempState[5];
	}break;
	default:{

	}break;

	}

}

