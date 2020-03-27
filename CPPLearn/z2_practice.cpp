#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

/*
Catcher是MCA国的情报员，他工作时发现敌国会用一些对称的密码进行通信，比如像这些ABBA，ABA，A，123321，
但是他们有时会在开始或结束时加入一些无关的字符以防止别国破解。
比如进行下列变化 ABBA->12ABBA,ABA->ABAKK,123321->51233214　。
因为截获的串太长了，而且存在多种可能的情况（abaaab可看作是aba,或baaab的加密形式），Cathcer的工作量实在是太大了，
他只能向电脑高手求助，你能帮Catcher找出最长的有效密码串吗？

思路：通过穷举遍历密码中间值的办法，来实现是否是密码的检测
从字符串中间开始搜索，直到密码中间值距离两边的距离小于当前最大密码长度为止
注意，代码应尽量简化，递归调用可能导致运行超时问题  不使用递归，代码也不是很复杂  问题的科学叫法是回文检测
当前本地运行没问题，但是线上运行会出错  只能通过0.98的例子，注意数据记录的方式，没有必要时尽量简化

*/


/*
int main() {
	string s;
	while (cin >> s) {
		const int len = s.size();
		if (len <= 1) return -1;
		int maxLen = 0;
		for (int i = 1; i < len; i++) {
			//寻找以i-1,i为中点偶数长度的回文
			int low = i - 1, high = i;
			while (low >= 0 && high < len && s[low] == s[high]) {
				low--; high++;
			}
			if (high - low - 1 > maxLen)
				maxLen = high - low - 1;
			//寻找以i为中心的奇数长度的回文
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
//只搜索有中间对称值的情况
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
//没有中间值对称的情况 midPos为对称的左边元素
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



