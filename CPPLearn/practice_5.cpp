
/*
д��һ�����򣬽���һ��ʮ�����Ƶ������������ֵ��ʮ���Ʊ�ʾ��������ͬʱ���� ��
*/

#include <iostream>
using namespace std;

#include <string>
int char2int(char ch);
int main()
{
	string str;
	int ret = 0;
	while (getline(cin, str))
	{
		//����ʽ
		if (str.size() < 3 || str[0] != '0')
			return 0;
		//�Ӻ����ǰ��ȡֵ
		ret = 0; int numm = 0; int temp;
		for (int i = str.size() - 1; i > 1; --i)
		{
			temp = char2int(str[i]);
			if (temp != -1)
			{
				ret += temp * pow(16, numm);
			}
			else
			{
				return 0;
			}
			numm++;
		}
		string rets = to_string(ret);
		cout << rets << endl;

	}
	return 0;
}

int char2int(char ch)
{
	int ret;
	if (ch >= '0' && ch <= '9')
		ret = ch - '0';
	else if (ch >= 'a' && ch <= 'f')
		ret = ch - 'a' + 10;
	else if (ch >= 'A' && ch <= 'F')
		ret = ch - 'A' + 10;
	else
	{
		return -1;
	}
	return ret;
}
