#include <iostream>
using namespace std;
#include <string>
/*
����:����һ�������������մ�С�����˳������������������ӣ���180��������Ϊ2 2 3 3 5 ��

���һ��������ҲҪ�пո�
*/
int IsPrime(int n);
string getResult(long ulDataInput);
int main()
{
	long numm;
	cin >> numm;
	cout << getResult(numm);
	return 0;
}
//����  2 3 5 7 11 13 17 19
string getResult(long ulDataInput)
{
	string ret;
	if (ulDataInput <= 1)
	{
		ret.push_back(' ');
		return ret;
	}
	int temp = ulDataInput;
	int k = 2;

	while (k != 1)
	{
		k = IsPrime(temp);
		if (k != 1)
		{
			string tt = to_string(k);
			ret.append(tt);
			ret.push_back(' ');
			temp = temp / k;
		}
		else
		{
			string tt = to_string(temp);
			ret.append(tt);
			ret.push_back(' ');
		}
	}
	return ret;
		
}

int IsPrime(int n) {
	int i;
	if (n % 2 == 0) return 2;
	for (i = 3; i <= sqrt(n); i += 2) {
		if (n%i == 0) return i;
	}
	return 1;
}
