#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>


/*
练习：自主设计的文本查询程序
function:在给定的文件中查找单词，查询结果为单词在文件中出现的次数及其所在行的列表
如果一个单词在一行中多次出现，此行只列出一次，且行会按照升序输出
程序分析：
1.程序读取文件，逐行读取，并将每一行分解为独立的单词
2.程序生成输出，
能够提取每个单词所关联的行号
行号按照升序输出且无重复
打印给定行号中的文本
*/

class QueryResult;
string make_plural(size_t ctr,const string &word, const string &ending)
{
  return (ctr==1) ? word : word+ending;//make_plural(wc, "word ", "s ")当输入中文本中
                                            //word数大于一是在word后加s，为words为word的复数！
}

//设计一个保存输入文件的类
class TextQuery{
public:
    using line_no = std::vector<std::string>::size_type;
    //读取给定文件的构造函数  执行查询的操作
    void runQueries(ifstream &infile);
    //TextQuery();    //默认构造函数
    TextQuery(ifstream &infile); 
    QueryResult query(const string &word) const;
private:    
    shared_ptr<vector<string>> file;
    map<string,shared_ptr<set<line_no>>> m;
};

//表达查询结果的类
class QueryResult{
    friend std::ostream& print(ostream&,const QueryResult&);
public:
    using line_no = std::vector<std::string>::size_type;
    QueryResult(string s,shared_ptr<set<line_no>> p,shared_ptr<vector<string>> f) : word(s),lines(p),file(f) {}; //默认构造函数
private:
    string word;
    shared_ptr<set<line_no>> lines; //出现的行号
    shared_ptr<vector<string>> file;    //输入文件

};
ostream &print(ostream &os,const QueryResult &qr)
{
    //找到单词 打印出现次数和所有出现的位置
    os << qr.word << " occurs " << qr.lines->size() << " "
    << make_plural(qr.lines->size(),"time","s") << endl;
    //打印单词出现的每一行
    for(auto num : *qr.lines)   //对set中的每个单词
        os << "\t(line " << num+1 << ") "
        << *(qr.file->begin() + num) << endl;
        return os;
}

//保存要处理的文件  并建立查询map
TextQuery::TextQuery(ifstream& infile) : file (new vector<string>)
{
    string str;
    while(getline(infile,str))
    {
        file->push_back(str);
        int n = file->size() - 1;    //当前读取的行号
        std::istringstream line(str);
        string word;
        while(line >> word)
        {
            if(!word.empty())   //去掉段首的空格
            {
                int index = 0;
                while(1)
                {
                    index = word.find(' ');
                    if(index != word.npos)
                        word.erase(index,1);
                    else
                        break;                    
                }
            }
            auto &lines =  m[word]; //??什么意思
            if(!lines)
                lines.reset(new set<line_no>);  //分配一个新的set
            lines->insert(n);
        }
        str.clear();
    }

}

QueryResult TextQuery::query(const string &word) const{
    static shared_ptr<set<line_no>> no_data(new set<line_no>);  //如果找到 返回一个空的set
    //使用find而不是下标运算查找单词 避免将单词添加到wm中
    auto loc = m.find(word);
    if(loc == m.end())
        return QueryResult(word,no_data,file);
    else
        return QueryResult(word,loc->second,file);
}

void TextQuery::runQueries(ifstream &infile)
{
    TextQuery tq(infile);   //保存要处理的文件，并建立查询map
    //引导客户输入要查询的单词
    
    while(1)
    {
        string in;
        cout << "Please input the word you want to find.input 'Q' or 'q' exit:";
        
        if((!(cin >> in)) || in == "Q" || in == "q")
            break;
        QueryResult qR = query(in);
        print(cout,qR);  
    }

}

int main()
{
    
    ifstream infile("./text");
    if(infile)
    {
        TextQuery textQ(infile);
        textQ.runQueries(infile);
    }
    else
    {
        cout << "open file error." << endl;
    }
    
    return 0;
}
