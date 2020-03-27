#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

/*
��дһ�����򣬽������ַ����е��ַ������¹�������
���� 1 ��Ӣ����ĸ�� A �� Z ���У������ִ�Сд��
�磬���룺 Type ����� epTy
���� 2 ��ͬһ��Ӣ����ĸ�Ĵ�Сдͬʱ����ʱ����������˳�����С�
�磬���룺 BabA ����� aABb
���� 3 ����Ӣ����ĸ�������ַ�����ԭ����λ�á�


�磬���룺 By?e ����� Be?y
˼·��
1.������ĸλ�������  ����ȡ
2.��ĸ����
3.��������ԭ������
*/

bool cmp(char ch1, char ch2);
void OutputResult(string &str);

int main()
{
	string input;
	while (getline(cin, input))
	{
		OutputResult(input);
	}
	return 0;
}

void OutputResult(string &str)
{
	int strLen = str.length();
	vector<bool> flag;
	string alphaStr;
	for (auto it = str.begin(); it != str.end(); ++it)
	{
		if (isalpha((*it)))
		{
			flag.push_back(true);
			alphaStr.push_back((*it));
		}
		else
		{
			flag.push_back(false);
		}
	}
	stable_sort(alphaStr.begin(), alphaStr.end(), cmp);
	//Ȼ�������Ľ��  ����ԭ�����ַ���
	auto ip = alphaStr.begin();
	for (auto it = str.begin(); it != str.end() && ip!=alphaStr.end(); ++it)
	{
		if (isalpha(*it))
		{
			(*it) = (*ip);
			ip++;
		}
	}
	cout << str << endl;

}

bool cmp(char ch1,char ch2)
{
	ch1 = toupper(ch1);
	ch2 = toupper(ch2);
	
	return ch1<ch2 ? true:false;
}