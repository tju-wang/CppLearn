#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

/*
Catcher��MCA�����鱨Ա��������ʱ���ֵй�����һЩ�ԳƵ��������ͨ�ţ���������ЩABBA��ABA��A��123321��
����������ʱ���ڿ�ʼ�����ʱ����һЩ�޹ص��ַ��Է�ֹ����ƽ⡣
����������б仯 ABBA->12ABBA,ABA->ABAKK,123321->51233214����
��Ϊ�ػ�Ĵ�̫���ˣ����Ҵ��ڶ��ֿ��ܵ������abaaab�ɿ�����aba,��baaab�ļ�����ʽ����Cathcer�Ĺ�����ʵ����̫���ˣ�
��ֻ������Ը������������ܰ�Catcher�ҳ������Ч���봮��

˼·��ͨ����ٱ��������м�ֵ�İ취����ʵ���Ƿ�������ļ��
���ַ����м俪ʼ������ֱ�������м�ֵ�������ߵľ���С�ڵ�ǰ������볤��Ϊֹ
ע�⣬����Ӧ�����򻯣��ݹ���ÿ��ܵ������г�ʱ����  ��ʹ�õݹ飬����Ҳ���Ǻܸ���  ����Ŀ�ѧ�з��ǻ��ļ��
��ǰ��������û���⣬�����������л����  ֻ��ͨ��0.98�����ӣ�ע�����ݼ�¼�ķ�ʽ��û�б�Ҫʱ������

*/


/*
int main() {
	string s;
	while (cin >> s) {
		const int len = s.size();
		if (len <= 1) return -1;
		int maxLen = 0;
		for (int i = 1; i < len; i++) {
			//Ѱ����i-1,iΪ�е�ż�����ȵĻ���
			int low = i - 1, high = i;
			while (low >= 0 && high < len && s[low] == s[high]) {
				low--; high++;
			}
			if (high - low - 1 > maxLen)
				maxLen = high - low - 1;
			//Ѱ����iΪ���ĵ��������ȵĻ���
			low = i - 1; high = i + 1;
			while (low >= 0 && high < len && s[low] == s[high]) {
				low--; high++;
			}
			if (high - low - 1 > maxLen)
				maxLen = high - low - 1;
		}
		cout << maxLen << endl;
	}
	return 0;
}
*/

int Strlen = 0;
void searchMid(string &data, int &ret, int midPos, int err);
void searchMir(string &data, int &ret, int midPos, int err);
int main()
{
	string input;
	int ret = 0;
	int lenMax = 0;
	if (getline(cin, input))
	{
		Strlen = input.size();
		for (int cnt = (int)(Strlen / 2); cnt < Strlen && ret < (Strlen-cnt)*2; ++cnt)
	{
		searchMid(input, ret, cnt, 0);
		searchMir(input, ret, cnt, 0);
	}
	for (int cnt = (int)(Strlen / 2); cnt > 0 && ret < (cnt) * 2; --cnt)
	{
		searchMid(input, ret, cnt, 0);
		searchMir(input, ret, cnt, 0);
	}
	cout << ret << endl;
}


return 0;
}
//ֻ�������м�Գ�ֵ�����
void searchMid(string &data,int &ret, int midPos, int err)
{
	if (midPos + err < Strlen - 1 && midPos - err > 0 &&(data[midPos - err] == data[midPos + err]))
	{
		err += 1;
		searchMid(data, ret, midPos, err);
	}

	if (ret < (1 + 2 * (err - 1)))
	ret = (1 + 2 * (err - 1));

	
}
//û���м�ֵ�ԳƵ���� midPosΪ�ԳƵ����Ԫ��
void searchMir(string &data, int &ret, int midPos, int err)
{

	if (midPos + 1 + err < Strlen - 1 && midPos - err > 0 && (data[midPos - err] == data[midPos + err + 1]))
	{
		err += 1;
		searchMir(data, ret, midPos, err);
	}

	if (ret < (2 * err))
	ret = 2 * err;

}



