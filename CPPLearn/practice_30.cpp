#include <iostream>
using namespace std;
#include <algorithm>
#include <string>

/*
Lilyʹ�õ�ͼƬ����"A"��"Z"��"a"��"z"��"0"��"9"��������ĸ�����ָ���������1024��
*/

int  main()
{
	string input;
	while (getline(cin, input))
	{
		sort(input.begin(), input.end());
		cout << input << endl;
	}
	return 0;
}

