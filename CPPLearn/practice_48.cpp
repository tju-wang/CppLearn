#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <map>
/*
��Ŀ������
xxx=lyf/${ttt}/test ��ʾshell�����µ�${yyy}������ʱת��Ϊ xxx
ttt=www,
yyy=seeyou
Ŀ��aa=/aaa/${xxx}/bbb/${yyy}/ccc ��������Ժ�Ľ��
*/
bool isNeedReplace(string tar);
void replace(string &tar, vector<pair<string, string>> vec);
int main()
{
	int num = 0;
	while (cin >> num)
	{
		cin.ignore();
		vector<pair<string,string>> vec;
		for (int i = 0; i < num; ++i)
		{
			string temp;
			getline(cin, temp);
			pair<string, string> pa;
			pa.first = temp.substr(0, temp.find('=')); //��ȡ��0��n���ַ���  string str = "AABBCC"; str.substr(0,3) == AAB
			pa.second = temp.substr(temp.find('=')+1, temp.size() - temp.find('=') -1);	//find�������ص�����ţ����û���ҵ�  �򷵻�-1
			vec.push_back(pa);
		}
		string tar = (*(vec.end() - 1)).second;	//�趨���Ŀ��
		while (isNeedReplace(tar))
		{
			replace(tar, vec);
		}
		cout << tar << endl;
	}
	return 0;
}

void replace(string &tar, vector<pair<string, string>> vec)
{
	int beg, end;
	beg = tar.find("&{");
	end = tar.find('}');
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		if ((*it).first == tar.substr(beg+2, end - beg-2))	//�൱��  ȥ����&{  �� }  substrȡ�ַ���������������ҿ�
		{
			tar.erase(beg, end-beg+1);	//����  ��beg��ʼ��  ��Ϊ����Ҳ������ҿ�  ������Ҫ+1
			tar.insert(beg, (*it).second);	//����  ��begλ�ÿ�ʼ����  ��Ŵ�0��ʼ��ʵ�����ǲ嵽������ַ��ĺ��һ��
		}
	}
}

bool isNeedReplace(string tar)
{
	if (tar.find("&{") != tar.npos && tar.find('}') != tar.npos)
		return 1;
	else
		return 0;
}