#include <iostream>
using namespace std;
#include <string>
#include<vector>
#include <algorithm>

/*
����n���ַ��������n���ַ��������ֵ������У�����ֻ������Сд��ĸ
˼·��������ĵ��ʴ���vector�� ��string���бȴ�С

*/

bool cmp(string s1, string s2);

int main()
{
	int inputNum = 0;
	vector<string> input;
	string temp;
	cin >> inputNum;
	for (int i = 0; i < inputNum; ++i)
	{
		cin >> temp;		
		input.push_back(temp);
	}
	//�����ַ���  ���ַ�����������
	sort(input.begin(), input.end(), cmp);
	for (auto i = input.begin(); i != input.end(); ++i)
	{
		cout << (*i) << endl;
	}
	return 0;
}

bool cmp(string s1, string s2)
{
	return s1 > s2 ? false : true;
}
