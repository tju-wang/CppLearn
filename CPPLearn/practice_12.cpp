#include <iostream>
using namespace std;

#include <string>
#include <algorithm>

int main()
{
	string str;
	if (getline(cin, str))
	{
		reverse(str.begin(), str.end());
		cout << str << endl;
	}

	return 0;
}