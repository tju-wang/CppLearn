#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <stack>
#include <sstream>
/*
ʵ����������
"3+2*{1+2*[-4/(8-6)+7]}"  ���ؽ��25

˼·��
1.�Ƚ����ʽ�е� [] �� {} �滻Ϊ����
2.����׺���ʽת��Ϊ��׺���ʽ
3.�����׺���ʽ��ֵ

�Ƚ����ʽ��Ϊ�沨��ʽ   ���ʹ���沨��ʽ�ļ��㷽������
*/

void ConvertStr(string &str);
int retPrio(char ch);
void ConvertMidToPost(string &midStr, vector<string> &postStr);
int evalRPN(vector<string> &tokens);

int main()
{
	string input;

	while (getline(cin, input))
	{
		vector<string> postStr;
		ConvertStr(input);
		ConvertMidToPost(input, postStr);
		//�����沨��ʽ��ֵ ��stringת��Ϊ vector<string>
		cout << evalRPN(postStr) << endl;
	}
	return 0;

}
void ConvertStr(string &str)
{
	for (auto it = str.begin(); it != str.end(); ++it)
	{
		if ((*it) == '[')
			(*it) = '(';
		else if ((*it) == ']')
			(*it) = ')';
		else if ((*it) == '{')
			(*it) = '(';
		else if ((*it) == '}')
			(*it) = ')';
	}
}

void ConvertMidToPost(string &midStr, vector<string> &postStr)
{
	stack<char> s;
	string tempStr;
	string operators = "+-*/()";    // �������еļ������
	for (auto it = midStr.begin(); it != midStr.end(); ++it)
	{
		//��������  ��Ҫ�����Ƿ���  + -��
		if (((midStr[it-midStr.begin()] == '-' || midStr[it - midStr.begin()] == '+') && ((it - midStr.begin()) == 0 || string("+-/*(").find(midStr[it - midStr.begin() - 1]) != string::npos)) || isdigit(midStr[it - midStr.begin()]))
		{   // �Ѳ��������뵽��׺ʽ��
			// ��������žͲ��ü��룬���Ż������ֱ���Ҫ����
			tempStr = midStr[it - midStr.begin()] != '+' ? midStr.substr(it - midStr.begin(), 1) : "";
			while ((it - midStr.begin() + 1) < (int)midStr.size() && operators.find((midStr[it - midStr.begin() + 1])) == string::npos) //operators.find(str[i+1]) == string::npos
			{
				tempStr += midStr[(++it - midStr.begin())];
			}
			postStr.push_back(tempStr);
		}
		else if ((*it) == '(')
		{
			s.push((*it));
		}
		else if ((*it) == ')')
		{
			char temp = s.top();
			while (temp != '(')
			{
				postStr.push_back(string(1, s.top()));
				s.pop();
				temp = s.top();
			}
			if (temp == '(')
				s.pop();
			
		}
		else if ((*it) == '+' || (*it) == '-' || (*it) == '*' || (*it) == '/')
		{
			int tProi = 0;
			if(s.size()!=0)
				tProi = retPrio(s.top());
			int itProi = retPrio(*it);
			if (itProi > tProi)
			{
				s.push((*it));
			}
			else
			{
				postStr.push_back(string(1, s.top()));
				s.pop();
				it--;	//ѭ��
			}

		}
	}
	while (s.size() != 0)
	{
		postStr.push_back(string(1, s.top()));
		s.pop();
	}
}

int retPrio(char ch)
{
	if (ch == '+' || ch == '-')
	{
		return 1;
	}
	else if(ch == '*' || ch == '/')
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

int toInt(string str)
{
	stringstream ss(str);
	int ret;
	ss >> ret;
	return ret;
}
int isfuhao(string &str)
{
	if (str == "+")
		return 1;
	else if (str == "-")
		return 2;
	else if (str == "*")
		return 3;
	else if (str == "/")
		return 4;
	else
		return 0;
}

int evalRPN(vector<string> &tokens) {
	stack<int> st;
	for (auto it = tokens.begin(); it != tokens.end(); ++it)
	{
		int f = isfuhao(*it);
		if (f == 0)
		{
			st.push((toInt((*it))));
		}
		else
		{
			int num1 = 0, num2 = 0, ret = 0;
			num2 = st.top();
			st.pop();
			num1 = st.top();
			st.pop();
			switch (f)
			{
			case 1:
			{
				ret = num1 + num2;
			}break;
			case 2:
			{
				ret = num1 - num2;
			}break;
			case 3:
			{
				ret = num1 * num2;
			}break;
			case 4:
			{
				if (num2 != 0)
					ret = num1 / num2;
				else
					return 0;
			}break;
			}
			st.push(ret);
		}
	}
	return st.top();
}


