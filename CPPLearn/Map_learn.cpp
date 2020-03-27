//STL ��  map��ʹ��  map�ı�����һ��ƽ�������
#include <map>
#include <string>
#include <iostream>
using namespace std;

/*
https://www.cnblogs.com/fnlingnzb-learner/p/5833051.html
*/

int main()
{

	map<int, string> mapStudent;
	//���ݵĲ���--��һ�֣���insert��������pair����
	mapStudent.insert(pair<int, string>(1, "student_one"));
	mapStudent.insert(pair<int, string>(2, "student_two"));
	mapStudent.insert(pair<int, string>(3, "student_three"));
	
	//�ڶ��֣���insert��������value_type���ݣ��������˵��
	mapStudent.insert(map<int, string>::value_type(3, "student_one"));
	mapStudent.insert(map<int, string>::value_type(2, "student_sec"));
	mapStudent.insert(map<int, string>::value_type(4, "student_four"));

	pair<map<int, string>::iterator, bool> Insert_Pair;

	Insert_Pair = mapStudent.insert(map<int, string>::value_type(6, "student_o"));	//�ж��Ƿ����ɹ�
	cout << Insert_Pair.second << endl;

	//������  ������뷽ʽ
	mapStudent[3] = "student_third";
	mapStudent[4] = "student_4th";
	mapStudent[5] = "student_5th";
	map<int, string>::iterator iter;
	for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		cout << iter->first << ' ' << iter->second << endl;

	int nSize = mapStudent.size();
	cout << nSize << endl;

	map<int, string>::reverse_iterator it;
	for (it = mapStudent.rbegin(); it != mapStudent.rend(); it++)
		cout << it->first << "  " << it->second << endl;
}


/*
�������ݣ�
��һ����ڶ��ֶ���ʹ��insert���������Ч��һ��  �漰��key��Ψһ������  ��key�Ѿ�����ʱ�����ܸ���ԭֵ
�������ֲ�����ʽ�����Դ���key��value  ��key�����ǿ���ֱ�ӽ��и���
*/


