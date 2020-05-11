#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <stack>


/*
小Q想要给他的朋友发送一个神秘字符串，但是他发现字符串的过于长了，于是小Q发明了一种压缩算法对字符串中重复的部分进行了压缩，
对于字符串中连续的m个相同字符串S将会压缩为[m|S](m为一个整数且1<=m<=100)，例如字符串ABCABCABC将会被压缩为[3|ABC]，
现在小Q的同学收到了小Q发送过来的字符串，你能帮助他进行解压缩么？

*/

void Decompression(string &input, string &out);

int main()
{
	string input;
	while (getline(cin, input))
	{
		string out;
		Decompression(input, out);
		cout << out << endl;

	}

	return 0;
}

void Decompression(string &input, string &out)
{
	stack<char> st1, st2,st3;
	vector<char> vec;
	int flag = 0;
	char tmp;
	for (auto it = input.begin(); it != input.end(); ++it)
	{
		if (flag)
		{
			//放入flag
			if ((*it) == ']')
			{
				flag--;
				tmp = (*it);
				while (tmp != '[' && st1.size()!=0)
				{
					st2.push(st1.top());
					st1.pop();
					tmp = st1.top();
				}
				if(st1.size())
					st1.pop();	// '['出栈  st2的栈顶元素是数字
				tmp = st2.top();
				for (int i = 0; i < 2 && st2.size() != 0; ++i)
				{
					st2.pop();
				}
				int num = tmp - '0';
				st3 = st2;
				for (int i = 0; i < num; ++i)
				{
					while (st3.size())
					{
						st1.push(st3.top());
						st3.pop();
					}
					st3 = st2;
				}
				if (flag == 0)
				{
					while (st1.size())
					{
						out.push_back((st1.top()));
						st1.pop();
					}
				}

			}
			else
			{
				st1.push((*it));
			}
		}
		else if ((*it) == '[')
		{
			flag++;
			st1.push(*it);
		}
		else
		{
			out.push_back((*it));
		}
	}
	while (st1.size())
	{
		out.push_back((st1.top()));
		st1.pop();
	}
}