#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
/*
�����ַ������� Ѱ���ַ����е������ַ���
˼·��
1.����26����ĸ�ı�ʶ bool
2.Ѱ����������������ַ���  ���ַ����е���Щ�ַ��ҳ���ɾ��
3.�ٴ�ͳ����ĸ��ʶ
*/
bool isHere(int num, string &str);
void StrState(bool *flag, string &str);
void findLongStr(bool *flag, int *pos, int *len);
void StrDelte(char ch, string &str);
void StrPrint(int pos, int len, string &str);

int main()
{
	string input;
	bool flag[26];
	int pos = 0, len = 0;
	for (int i = 0; i < 26; i++)
		flag[i] = false;
	bool stop = true;
	bool firstFlag = true;
	if (getline(cin, input))
	{
		StrState(flag, input);
		stop = false;
		for (int i = 0; i < 26; i++)
			stop |= flag[i];
		while (stop)
		{
			findLongStr(flag, &pos, &len);
			firstFlag = false;
			//���  ��������ַ���
			StrPrint(pos, len, input);
			StrState(flag, input);
			stop = false;
			for (int i = 0; i < 26; i++)
				stop |= flag[i];
		}
		if (firstFlag) {
			cout << "Not Found" << endl;
			return 0;
		}
	}

	return 0;
}
//����λ�úͳ���  �����Ӧ���ַ���  �����ַ�����ɾ����Ӧ���ַ�
void StrPrint(int pos,int len,string &str)
{
	//����
	string pri;
	for (int i = 0; i < len; ++i)
	{
		char tempD = (char)(pos + 'A');
		char tempX = (tempD + ('a' - 'A'));
		pri.push_back(tempD);
		pri.push_back(tempX);
		StrDelte(tempD, str);
		StrDelte(tempX, str);
		pos++;
	}
	cout << pri << endl;
}
//ɾ���ַ�������
void StrDelte(char ch, string &str)
{
	int pos = str.find_first_of(ch);
	if (pos != str.npos)	//ɾ������
	{
		str.erase(str.begin() + pos);
	}
}


//Ѱ��������������ַ���  ����λ�úͳ���
void findLongStr(bool *flag,int *pos,int *len)
{
	vector<int> cntArr,posArr;
	int cnt = 0, tempPos = 0;
	for (int i = 0; i < 26; i++)
	{
		if (flag[i] == 1)
		{
			if (cnt == 0)
				tempPos = i;
			cnt++;
		}
		else
		{
			if (cnt)
			{
				cntArr.push_back(cnt);
				posArr.push_back(tempPos);
				cnt = 0; tempPos = 0;
			}
		}

	}
	//�ҳ�����cnt
	vector<int>::iterator it = max_element(cntArr.begin(),cntArr.end());
	*len = (*it);
	*pos = *(posArr.begin() + (it - cntArr.begin()));

}

void StrState(bool *flag, string &str)	//ͳ���ַ����
{
	for (int i = 0; i < 26; ++i)
	{
		flag[i] = 0;
		if (isHere(i, str))
			flag[i] = 1;
	}
}
//�����ַ�������ĸ�Ĵ�д��Сд�Ƿ����  ����num = 0-25 (A-Z)
bool isHere(int num, string &str)
{
	char temp = (char)(num  + 'A');
	
	int ret = 1;
	ret = str.find_first_of(temp, 0);
	if (ret != str.npos)
	{
		ret = str.find_first_of((char)(temp+('a'-'A')), 0);
	}
	if (ret == str.npos)
		return false;
	else
	{
		return true;
	}
}
