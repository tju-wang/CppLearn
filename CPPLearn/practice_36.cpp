#include <iostream>
using namespace std;

#include <string>

void CalcCharNum(string &str);

int main()
{
	string input;
	while (getline(cin, input))
	{
		CalcCharNum(input);
	}
	return 0;
}

void CalcCharNum(string &str)
{
	int numAlpha = 0 , numNum = 0, numSpace = 0, numOther = 0;
	for (auto it = str.begin(); it != str.end(); ++it)
	{
		if (isalpha((*it)))
		{
			numAlpha++;
		}
		else if(isdigit((*it)))
		{
			numNum++;
		}
		else if((*it) == ' ')
		{
			numSpace++;
		}
		else
		{
			numOther++;
		}
	}
	cout << numAlpha << endl << numSpace << endl << numNum << endl << numOther << endl;
	
}