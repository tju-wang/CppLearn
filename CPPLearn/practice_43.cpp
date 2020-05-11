#include <iostream>
using namespace std;

/*
链接：https://www.nowcoder.com/questionTerminal/a30bbc1a0aca4c27b86dd88868de4a4a?f=discussion
来源：牛客网

但是按照上面的做法没有考察到任何知识点，所以先无视string的这个功能。
汉字占两个字节，每个字节的ASCII码最高位均为1，由于char默认为带符号类型，所以汉字的ASCII码小于0，而英文数字等其他字符占一个字节，
ASCII码最高位为0，值在0~127之间。因此，只需要判断该字节是否小于0就能推断出是否为半个汉字。
再向前推算有连续几个半个汉字，若有偶数个，则输出最后半个汉字，否则不输出。

思路：找到汉字的编码规律  将其分成两个unsigned char类型，则 当其值 >127时，就是汉字  而<127为ASCII  
计算截止字节前的汉字的数量，为偶数  则直接输出  为奇数，则去掉最后的汉字
*/

