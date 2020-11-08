// CppPrimer.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;




istream& func8_1(istream &is)
{
	std::string buf;
	while (is >> buf)	//当输入流的 badbit  failbit 或 eofbit被置位时，检测流状态的条件会失败
		std::cout << buf << std::endl;
	is.clear();
	return is;
}
/*将path指定的文件内容读取到vec当中，每一行作为一个独立的元素*/
void func8_4(string path, string pathOut,vector<string> &vec)
{
	ifstream fstr(path);	//打开文件
	ofstream fout(pathOut,ofstream::app);	//设置写入文件模式  app指定每次写操作前都指定到文件末尾，可以保留文件之前的内容
	if (!fstr)
	{
		cout << "open file failed." << endl;
	}
	string s;
	while (getline(fstr,s))
	{
		vec.push_back(s);
		fout << s << endl;
		s.clear();
	}
	fstr.close();	//关闭文件
}
/*使用istringstream读取vector<string>中的内容*/
void func8_10(vector<string> &vec)
{
	istringstream str;
	string s;
	for (auto it : vec)
	{
		str.str(it);
		while (str >> s)
		{
			cout << s << endl;
		}
		str.clear();	//一定要清空  或者在循环内部定义sstream
	}
}



void test_func8_1()
{
	istream& is = func8_1(std::cin);
	std::cout << is.rdstate() << std::endl;
}

void tset_func8_4()
{
	vector<string> str;
	func8_4("D:/CProgram/CppLearn/CppPrimer/file/read_file.txt","D:/CProgram/CppLearn/CppPrimer/file/out_file.txt",str);
	for (auto it = str.begin();it != str.end(); ++it)
	{
		cout << *it << endl;
	}
	func8_10(str);
}

int main()
{

	tset_func8_4();
	return 0;
}

