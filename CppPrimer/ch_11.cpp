#include <iostream>
using namespace std;
#include <map>
#include <vector>
#include <string>

/*定义一个map，关键字是家庭的姓，值是一个vector，保存家中孩子（们）的名。编写代码，实现添加新的家庭以及向已有家庭中添加新的孩子*/


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

