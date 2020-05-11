#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <stack>


/*
СQ��Ҫ���������ѷ���һ�������ַ����������������ַ����Ĺ��ڳ��ˣ�����СQ������һ��ѹ���㷨���ַ������ظ��Ĳ��ֽ�����ѹ����
�����ַ�����������m����ͬ�ַ���S����ѹ��Ϊ[m|S](mΪһ��������1<=m<=100)�������ַ���ABCABCABC���ᱻѹ��Ϊ[3|ABC]��
����СQ��ͬѧ�յ���СQ���͹������ַ��������ܰ��������н�ѹ��ô��

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
			//����flag
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
					st1.pop();	// '['��ջ  st2��ջ��Ԫ��������
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