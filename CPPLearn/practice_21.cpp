#include <iostream>
using namespace std;
#include <vector>
#include <string>

/*
������һ�������⣺��ĳ�̵�涨����������ˮƿ���Ի�һƿ��ˮ��С��������ʮ������ˮƿ���������Ի�����ƿ��ˮ�ȣ�������5ƿ��
�������£�����9����ƿ�ӻ�3ƿ��ˮ���ȵ�3ƿ���ģ������Ժ�4����ƿ�ӣ���3���ٻ�һƿ��
�ȵ���ƿ���ģ���ʱ��ʣ2����ƿ�ӡ�Ȼ�������ϰ��Ƚ����һƿ��ˮ���ȵ���ƿ���ģ�
�����Ժ���3����ƿ�ӻ�һƿ���Ļ����ϰ塣���С��������n������ˮƿ�������Ի�����ƿ��ˮ�ȣ�
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