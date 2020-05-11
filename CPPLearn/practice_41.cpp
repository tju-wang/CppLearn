#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
#include <vector>
/*
����һ�����֣���������26���ַ�����ɣ���������ַ����ġ�Ư���ȡ�����������ĸ��Ư���ȡ����ܺ͡�
ÿ����ĸ����һ����Ư���ȡ�����Χ��1��26֮�䡣û���κ�������ĸӵ����ͬ�ġ�Ư���ȡ�����ĸ���Դ�Сд��
����������֣�����ÿ�����������ܵġ�Ư���ȡ���
˼·��ʵ������Ҫͳ�Ƴ����ִ���������ĸ����Ư����Ϊ26  Ȼ�������� 25  24  ...  �������
*/
int CalcBeautyNum(string &str);


int main()
{
	int num;
	while (cin >> num)
	{
		string str;
		for (int i = 0; i < num; ++i)
		{
			cin >> str;
			cout << CalcBeautyNum(str) << endl;
			str.clear();
		}
	}


	return 0;
}

int CalcBeautyNum(string &str)
{
	vector<int> flag(26,0);
	for (auto it = str.begin(); it != str.end(); ++it)
	{
		flag[(tolower(*it) - 'a')] ++;
	}
	sort(flag.begin(), flag.end());
	int ret = 0,N=26;
	for (int i = 25; i >= 0; --i)
	{
		if (flag[i] != 0)
		{
			ret = ret + flag[i] * N;
			N--;
		}
	}
	return ret;

}