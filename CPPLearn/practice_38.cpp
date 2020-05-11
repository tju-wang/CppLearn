#include <iostream>
using namespace std;

#include <vector>
#include <string>

/*
Jessi初学英语，为了快速读出一串数字，编写程序将数字转换成英文：
如22：twenty two，123：one hundred and twenty three。
*/
string buff[5] = { "and", "billion", "million", "thousand", "hundred" };
string numm[] = { "one" , "two", "three", "four", "five", "six", "seven" ,"eight","nine","ten","eleven","twelve ","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };
string numDayuTwenty[] = { "twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety" };

void ConvertThreeNum(long num, string &str);
void Convert(long num);

int main()
{
	long input;
	while (cin >> input)
	{
		if(input<10000000000)
		Convert(input);
		else if(input==0)
		{
			cout << "zero" << endl;
		}
		else
		{
			cout << "error" << endl;
		}
	}
	return 0;
}

void Convert(long num)
{

	string ret;
	long temp = num / 1000000000;
	if (temp > 0)
	{
		ConvertThreeNum(temp,ret);
		ret.push_back(' ');
		ret.append(buff[1]);
		num = num % 1000000000;
		if (num != 0)
			ret.push_back(' ');
	}
		
	temp = num / 1000000;
	if (temp > 0)
	{
		ConvertThreeNum(temp, ret);
		ret.push_back(' ');
		ret.append(buff[2]);
		num = num % 1000000;
		if (num != 0)
			ret.push_back(' ');

	}
	temp = num / 1000;
	if (temp > 0)
	{
		ConvertThreeNum(temp, ret);
		ret.push_back(' ');
		ret.append(buff[3]);
		num = num % 1000;
		if (num != 0)
			ret.push_back(' ');
	}
	if (num > 0)
	{
		ConvertThreeNum(num, ret);
	}
	//最后整理空格  1.最后不能有空格 2.不允许出现连续的多个空格
	for (auto it = ret.begin(); it != ret.end(); ++it)
	{
		if ((*it) == ' ' && it == ret.end() - 1)
		{
			ret.erase(it);
			break;
		}
		if ((*it) == ' ' && (*(it + 1) == (*it)))
		{
			it = ret.erase(it);
		}
	}
	cout << ret << endl;

}
void ConvertThreeNum(long num, string &str)
{
	string tempStr;
	if (num == 0)
		return;
	if (num / 100 != 0)
	{
		int temp = num / 100;
		if(temp>0)
			tempStr = numm[temp - 1];
		str.append(tempStr);
		str.push_back(' ');
		str.append(buff[4]);
		str.push_back(' ');
		str.append(buff[0]);
		str.push_back(' ');
		num = num % 100;
		if (num == 0)	//将and和空格删掉
		{
			str.erase(str.end() - 5, str.end());
		}
	}
	num = num % 100;
	if (num>0 && num <= 19)
	{
		tempStr = numm[num - 1];
		str.append(tempStr);
		str.push_back(' ');
	}
	else
	{
		int ten = num / 10;	//取10位  此处ten一定大于等于2
		if(ten>1)
			str.append(numDayuTwenty[ten-2]);
		str.push_back(' ');
		int ge = num % 10;
		if(ge!=0)
			str.append(numm[ge - 1]);
	}

}