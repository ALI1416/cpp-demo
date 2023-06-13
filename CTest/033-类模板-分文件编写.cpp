#include<iostream>
using namespace std;
// 如果类模板分文件编写，只能包含cpp文件，h文件无效
#include"lib/person33.cpp"
// 把声明和实现，放到同一个文件里，命名为hpp文件
#include"lib/person34.hpp"

void main033()
{
    Person33<string, int> p("ck", 1998);
    p.print();
    Person34<string, int> p2("cc", 2222);
    p2.print();
}
