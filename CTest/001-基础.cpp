// 引用库，<>是系统库，""是本地库
#include<iostream>
#include"fun.h"
// 使用#define定义常量
#define PI 3.1415926

// 声明命名空间
using namespace std;

void main()
{
    /* 基础 */
    // cout输出，<<输出拼接，endl换行
    cout << "Hello," << " World !" << endl;
    // 暂停
    system("pause");
    // 定义长整形变量
    long a = 111;
    cout << "int占用空间为：" << sizeof(int) << "字节" << "，变量a占用空间为：" << sizeof(a) << "字节" << endl;
    // 定义字符串变量
    string str;
    // 捕获键盘输入到变量str，换行符结束输入
    cout << "请输入字符串：";
    cin >> str;
    cout << "输入的字符串为：\"" << str << "\"" << endl;
    // 调用函数
    print(222);
    // 使用const定义常量
    const double e = 2.718281828;
    cout << "π：" << PI << "，e：" << e << endl;

    /* 指针 */
    int b = 333;
    // 使用`原变量类型 * 指针变量名`来定义指针
    // 使用`&变量`来获取该变量的地址
    int* p = &b;
    // 使用`*指针变量名`来获取原变量的值
    cout << "变量b的地址为：" << p << "，值为：" << *p << endl;
    // 无论指针是什么类型，32位占用4字节，64位占用8字节
    cout << "指针p占用" << sizeof(p) << "字节" << endl;
    // 空指针，指向地址0(NULL)，一般是在初始化的时候赋值
    // 地址0-255是系统内存，不可访问
    int* p1 = NULL;
    cout << "变量p1的地址为：" << p1 << endl;
    // 野指针，指向非自己程序的地址，不可访问
    int* p2 = (int*)0x1234;
    // 强制访问会报错
    // cout << "变量p2的地址为：" << *p2 << endl;

    /* const修饰指针 */
    // `常量指针`，指针可修改，值不可修改，相当于(const int)*
    const int* p3 = &b;
    cout << "指针p3的值(b)："<< *p3 << endl;
    // *p3不可以修改，编译器会报错
    // *p3 = 444;
    // 但是可以修改变量b的值
    b = 444;
    cout << "指针p3的值(b)：" << *p3 << endl;
    // 修改指针
    int c = 555;
    p3 = &c;
    cout << "指针p3的值(c)：" << *p3 << endl;
    // `指针常量`，值可以修改，指针不可修改，相当于(int)* const
    int* const p4 = &c;
    cout << "指针p4的值(c)：" << *p4 << endl;
    // 修改值
    *p4 = 666;
    cout << "指针p4的值：" << *p4 << endl;
    // 不可修改指针，编译器会报错
    // p4 = &b;
    // const修饰指针和常量，值和指针都不可修改，(const int)* const
    const int* const p5 = &c;
    cout << "指针p5的值(c)：" << *p5 << endl;

}
