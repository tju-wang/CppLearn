#include <iostream>
using namespace std;
#include <map>
#include <vector>
#include <string>

/*����һ��map���ؼ����Ǽ�ͥ���գ�ֵ��һ��vector��������к��ӣ��ǣ���������д���룬ʵ������µļ�ͥ�Լ������м�ͥ������µĺ���*/


void test_11_7()
{
	map<string, vector<string>> family;
	string str;
	while (cout << "input family name: " && getline(cin , str))
		for(string ch; (cout << "input child name: " && getline(cin , ch)) && (ch != "Q" && ch != "q"); ch.clear())
			family[str].push_back(ch);
}

int main()
{
	test_11_7();
	return 0;
}

