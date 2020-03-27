#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <sstream>

/*
����һ���򵥴����¼����Сģ�飬�ܹ���¼����Ĵ������ڵ��ļ����ƺ��кš�
����
1�� ��¼���8�������¼��ѭ����¼������˵���ֻ��������ֵİ��������¼����
����ͬ�Ĵ����¼�����ļ����ƺ��к���ȫƥ�䣩ֻ��¼һ��������������ӣ�
2�� ����16���ַ����ļ����ƣ�ֻ��¼�ļ��������Ч16���ַ���
3�� ������ļ����ܴ�·������¼�ļ����Ʋ��ܴ�·����

*/
struct ErrData {
	int cnt = 0;
	string name;
	int pos = 0;
};
void SaveErrData(ErrData &tempErr, vector<ErrData> &errData, int &VecPos);
void errPrint(string &str,int &pos, vector<ErrData> &errData, int &vecPos);
void errPrint(string &str);
int main()
{
	string input;
	vector<ErrData> errData;
	int vecPos = 0;
	int pos = 0;
	while (cin>> input >> pos)
	{
		//if (input.size() > 3)
			errPrint(input,pos,errData,vecPos);
	}
	auto it = errData.end();
	if (errData.size() > 8)
		it = errData.end() - 8;
	else
	{
		it = errData.begin();
	}
	for (; it != errData.end(); ++it)
	{
		cout << (*it).name << ' ' << (*it).pos << ' ' << (*it).cnt << endl;
	}
	return 0;
}

void errPrint(string &str,int &pos,vector<ErrData> &errData,int &vecPos)
{
	int analyzeF = 0;
	
	ErrData tempData;
	string num;
	
	tempData.name = str;
	tempData.pos = pos;
	//���ṹ�����
	char ch = '\\';
	for (int kk = 0; kk < 16; ++kk)
	{
		if (tempData.name.size() - 1 - kk >= 0)
		{
			if (tempData.name[tempData.name.size() - 1 - kk] == ch)
			{
				tempData.name = tempData.name.substr(tempData.name.size() - kk);
				break;
			}
		}

	}
	if (tempData.name.size() > 16)
	{
		tempData.name = tempData.name.substr(tempData.name.size() - 16);
	}
	SaveErrData(tempData, errData, vecPos);
}

void SaveErrData(ErrData &tempErr,vector<ErrData> &errData,int &VecPos)
{
	//1.�ȼ��ṹ�����Ƿ������ͬ����  2.����Ƿ����8��  �������滻  δ����������
	if (errData.size() == 0)
	{
		tempErr.cnt = 1;
		errData.push_back(tempErr);
		VecPos = errData.end() - errData.begin();
		return;
	}
	for (vector<ErrData>::iterator it = errData.begin(); it != errData.end(); ++it)
	{
		if ((*it).name == tempErr.name && (*it).pos == tempErr.pos)
		{
			tempErr.cnt =  ((*it).cnt)++;
	/*		errData.erase(it);
			errData.push_back(tempErr);*/
			return;
		}	
	}
	tempErr.cnt = 1;
	errData.push_back(tempErr);

}
