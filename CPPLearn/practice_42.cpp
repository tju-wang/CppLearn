#include <iostream>
using namespace std;

#include <string>
#include <vector>

/*
��дһ����ȡ�ַ����ĺ���������Ϊһ���ַ������ֽ��������Ϊ���ֽڽ�ȡ���ַ���������Ҫ��֤���ֲ����ذ����
��"��ABC"4��Ӧ�ý�Ϊ"��AB"������"��ABC��DEF"6��Ӧ�����Ϊ"��ABC"������"��ABC+���İ��"��
*/


int main()
{
	string input;
	int outNum;


	while (cin >> input >> outNum)
	{
		cout << input.size() << endl << sizeof(input) << endl;
		string res;
		for (int i = 0; i < outNum; ++i)
		{
			res.push_back(input[i]);
		}
		cout << res << endl;
	}
		
	return 0;
}
