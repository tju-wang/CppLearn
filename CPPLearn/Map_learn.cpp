//STL 库  map的使用  map的本质是一颗平衡二叉树
#include <map>
#include <string>
#include <iostream>
using namespace std;

/*
https://www.cnblogs.com/fnlingnzb-learner/p/5833051.html
*/

int main()
{

	map<int, string> mapStudent;
	//数据的插入--第一种：用insert函数插入pair数据
	mapStudent.insert(pair<int, string>(1, "student_one"));
	mapStudent.insert(pair<int, string>(2, "student_two"));
	mapStudent.insert(pair<int, string>(3, "student_three"));
	
	//第二种：用insert函数插入value_type数据，下面举例说明
	mapStudent.insert(map<int, string>::value_type(3, "student_one"));
	mapStudent.insert(map<int, string>::value_type(2, "student_sec"));
	mapStudent.insert(map<int, string>::value_type(4, "student_four"));

	pair<map<int, string>::iterator, bool> Insert_Pair;

	Insert_Pair = mapStudent.insert(map<int, string>::value_type(6, "student_o"));	//判断是否插入成功
	cout << Insert_Pair.second << endl;

	//第三种  数组插入方式
	mapStudent[3] = "student_third";
	mapStudent[4] = "student_4th";
	mapStudent[5] = "student_5th";
	map<int, string>::iterator iter;
	for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		cout << iter->first << ' ' << iter->second << endl;

	int nSize = mapStudent.size();
	cout << nSize << endl;

	map<int, string>::reverse_iterator it;
	for (it = mapStudent.rbegin(); it != mapStudent.rend(); it++)
		cout << it->first << "  " << it->second << endl;
}


/*
上述内容：
第一种与第二种都是使用insert插入操作，效果一样  涉及到key的唯一性问题  当key已经存在时，不能覆盖原值
而第三种操作方式，可以创建key与value  当key存在是可以直接进行覆盖
*/


