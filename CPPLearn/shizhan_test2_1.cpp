#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
/*
整数反转求和
注：指明int类型数据输入格式时，没有必要将其看做字符输入  可以直接用 cin << a; cin<<b;来处理  或scanf(%d,%d,&a,&b);
反转，可以转换为字符串  或  使用栈来进行反转
*/

bool isNum(char ch);
int reverseAdd(int a, int b);
int main()
{
	string input,num;
	int num1 = 0, num2 = 0, count = 0;
	int ret = 0;
	if (getline(cin, input))	
	{
		int i = 0;
		while (input[i] != '\0'&& count<2)
		{
			input.push_back(' ');	//为字符串末尾添加一个空格
			if (isNum(input[i]))
			{
				num.push_back(input[i]);
			}
			else
			{
				//转化string为int
				reverse(num.begin(), num.end());
				int temp = 0;
				stringstream ss(num);
				ss >> temp;
				if (temp < 1 || temp>70000)
				{
					cout << -1 << endl;
					return 0;
				}
				if (count == 0)
					num1 = temp;
				else
				{
					num2 = temp;
				}
				
				count++;
				num.clear();
			}
			++i;
		}
		cout << reverseAdd(num1, num2) << endl;

	}

	return 0;
}


int reverseAdd(int a, int b)
{
	return (a + b);	
}

bool isNum(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return true;
	}
	return false;
}