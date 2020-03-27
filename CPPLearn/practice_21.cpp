#include <iostream>
using namespace std;
#include <vector>
#include <string>

/*
有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？”答案是5瓶，
方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用3个再换一瓶，
喝掉这瓶满的，这时候剩2个空瓶子。然后你让老板先借给你一瓶汽水，喝掉这瓶满的，
喝完以后用3个空瓶子换一瓶满的还给老板。如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？
*/


void outPutResult(int num);

int main()
{
	int input = 0;
	while (cin >> input)
	{
		outPutResult(input);
	}

	return 0;
}

void outPutResult(int num)
{
	int cnt = 0;
	while (num>1)
	{
		if (num - 3 + 1 >= 0)
		{
			num = num - 3 + 1;
			cnt++;
		}
			
	}
	cout << cnt << endl;

}