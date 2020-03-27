#include <iostream>
using namespace std;
#include <string>
#include <vector>
//2020��-��Ϊ����  @MrWang_tju 2020.03.09  ����ͨ��
//��Ŀ https://www.cnblogs.com/xuyy-isee/p/10568949.html
//Apache Hadoop YARN��һ���µ�Hadoop��Դ����������Ҫ����Ϊresource manager��node manager��resource managerʹ������״̬��ά����״̬������������ڡ�
//�����ṹ��
struct ObjectRMAppAttempt
{
	string name;
	int stat;	//0-5  6��״̬
};
//����stste ����
string RMState[6] = {"submitted","scheduled","allocated","running","finished","killed" };	
string SourceName[4] = { "RmApp","ResourceScheduler","ApplicationMasterLauncher","RmContainer" };
string Event[6] = { "start","app_accepted","container_allocated","launched","finished","kill" };

vector<ObjectRMAppAttempt> obj;


int isHere(string name, vector<ObjectRMAppAttempt> &arr);
void AnalyseSigSignal(string str);
int FindEvent(string &str);

void test_fun(string testStr)
{
	string input;
	
	input = testStr;
	//while (getline(cin, input))
	while(input.size())
	{
		//��������ָ�� ������
		int kk = 0;
		string sigSignal;
		input.push_back(' ');	//������һ��  �ո�
		while (input[kk] != '\0')
		{
			if (input[kk] != ' ')
			{
				sigSignal.push_back(input[kk]);
			}
			else
			{
				AnalyseSigSignal(sigSignal);
				sigSignal.clear();
			}
			++kk;
		}
		cout << endl;
		input.clear();
	}
}

int main()
{
	string str;
	str = "RmApp|RmAppAttempt_001|start RmApp|RmAppAttempt_002|start ResourceScheduler|RmAppAttempt_001|app_accepted\
 ApplicationMasterLauncher|RmAppAttempt_001|launched RmContainer|RmAppAttempt_001|container_allocated  ResourceScheduler|RmAppAttempt_001|finished RmApp|RmAppAttempt_001|kill";
	test_fun(str);
	return 0;
}

void AnalyseSigSignal(string str)
{
	vector<ObjectRMAppAttempt> objArr;
	//����
	int kk = 0, local = 0;
	string tempSourceName,tempEvent,tempTargetName;
	while (str[kk] != '\0')
	{
		if (str[kk] != '|')
		{
			if (local == 0)	
				tempSourceName.push_back(str[kk]);
			else if (local == 1)
				tempTargetName.push_back(str[kk]);
			else if (local == 2)
				tempEvent.push_back(str[kk]);
		}
		else
		{
			local++;
		}
		++kk;
	}
	//����ָ���  ƥ��Ϊint��������
	int event = FindEvent(tempEvent);
	switch (event)
	{
		case 0:	//�����µ�target
		{
			if (SourceName[0] == tempSourceName)
			{
				ObjectRMAppAttempt tempObj;
				tempObj.name = tempTargetName;
				tempObj.stat = 0;
				obj.push_back(tempObj);
				cout << tempTargetName << '|' << RMState[tempObj.stat] << ';';
			}
		}break;
		case 1:
		{
			//Ѱ��obj�����Ƿ����������
			int numm = isHere(tempTargetName, obj);
			if (numm != -1)
			{
				vector<ObjectRMAppAttempt>::iterator it = obj.begin() + numm;
				if ((*it).stat == 0 && tempSourceName == SourceName[1])	//�ж�״̬
				{
					(*(it)).stat = 1;
					cout << tempTargetName << '|' << RMState[(*(it)).stat] << ';';
				}
			}
		}break;
		case 2:
		{
			//Ѱ��obj�����Ƿ����������
			int numm = isHere(tempTargetName, obj);
			if (numm != -1)
			{
				vector<ObjectRMAppAttempt>::iterator it = obj.begin() + numm;
				if ((*it).stat == 1 && tempSourceName == SourceName[3])	//�ж�״̬
				{
					(*(it)).stat = 2;
					cout << tempTargetName << '|' << RMState[(*(it)).stat] << ';';
				}
			}
		}break;
		case 3:
		{
			//Ѱ��obj�����Ƿ����������
			int numm = isHere(tempTargetName, obj);
			if (numm != -1)
			{
				vector<ObjectRMAppAttempt>::iterator it = obj.begin() + numm;
				if ((*it).stat == 1 && tempSourceName == SourceName[2])	//�ж�״̬
				{
					(*(it)).stat = 3;
					cout << tempTargetName << '|' << RMState[(*(it)).stat] << ';';
				}
			}
		}break;
		case 4:
		{
			//Ѱ��obj�����Ƿ����������
			int numm = isHere(tempTargetName, obj);
			if (numm != -1)
			{
				vector<ObjectRMAppAttempt>::iterator it = obj.begin() + numm;
				if ((*it).stat == 3 && tempSourceName == SourceName[1])	//�ж�״̬
				{
					(*(it)).stat = 4;
					cout << tempTargetName << '|' << RMState[(*(it)).stat] << ';';
				}
			}
		}break;
		case 5:
		{
			//Ѱ��obj�����Ƿ����������
			int numm = isHere(tempTargetName, obj);
			if (numm != -1)
			{
				vector<ObjectRMAppAttempt>::iterator it = obj.begin() + numm;
				if ((*it).stat != 4 && tempSourceName == SourceName[0])	//�ж�״̬
				{
					(*(it)).stat = 5;
					cout << tempTargetName << '|' << RMState[(*(it)).stat] << ';';
				}
			}
		}break;

	}

	
}
int FindEvent(string &str)
{
	for (int i = 0; i < 6; ++i)
	{
		if (str == Event[i])
			return i;
	}
}
//Ѱ��arr���Ƿ���name
int isHere(string name, vector<ObjectRMAppAttempt> &arr)
{
	for (vector<ObjectRMAppAttempt>::iterator it = arr.begin(); it != arr.end(); ++it)
	{
		if ((*it).name == name)
			return (it-arr.begin());
	}
	return -1;
}

