#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <sstream>
/*
������

����һ��������������������ַ�������ʽ�������

���򲻿��Ǹ���������������ֺ���0����������ʽҲ����0��������Ϊ100�������Ϊ001
*/

int main()
{
	int num;
	cin >> num;
	string str = to_string(num);
	reverse(str.begin(), str.end());
	cout << str << endl;
	

	return 0;
}