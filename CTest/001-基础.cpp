// 引用库，<>是系统库，""是本地库
// 常用功能，都在iostream库里面
#include<iostream>
#include"lib/fun.h"
// 使用#define定义常量
#define PI 3.1415926

// 声明命名空间
using namespace std;

// 声明结构体
struct Student
{
    // 姓名
    string name;
    // 性别
    bool gender;
    // 出生年
    int year;
};

// 使用指针传递值，可以节省内存
// 使用const修饰参数，可以防止误操作
void printStudent(const struct Student* s)
{
    // 使用`->`来访问指针结构体中的属性
    cout << "姓名：" << s->name << "，性别：" << s->gender << "，出生年：" << s->year << endl;
}

// 栈
// 返回函数内局部变量的地址
int* stack()
{
    int a = 10;
    return &a;
}

// 堆
int* heap()
{
    // 使用new关键字，创建到堆，返回一个地址，用指针接收
    int* p = new int(20);
    return p;
}

void main001()
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
    cout << "指针p3的值(b)：" << *p3 << endl;
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

    /* 指针和数组 */
    int arr[] = { 1,2,3,4,5 };
    // 指针指向数组，不用加&
    int* p6 = arr;
    // 访问的是第一个元素
    cout << "arr[0]：" << *p6 << endl;
    cout << "arr[]：";
    for (int i = 0; i < 5; i++)
    {
        cout << *p6 << ",";
        // 指针+1，访问下一个元素
        p6++;
    }
    cout << endl;

    /* 指针和函数 */
    int num1 = 1111, num2 = 22222;
    // 值传递，不改变原数据
    swap01(num1, num2);
    cout << "num1：" << num1 << "，num2：" << num2 << endl;
    // 指针传递，会改变原数据
    swap02(&num1, &num2);
    cout << "num1：" << num1 << "，num2：" << num2 << endl;

    /* 指针和结构体 */
    Student s = { "ck",true,1998 };
    // 使用`.`来访问结构体中的属性
    cout << "姓名：" << s.name << "，性别：" << s.gender << "，出生年：" << s.year << endl;
    printStudent(&s);

    /* 指针和堆栈 */
    // 栈，系统自动释放
    // 函数运行结束后，局部变量会被释放掉
    int* p7 = stack();
    // 第一次获取是正确的数值，被保留住了
    cout << *p7 << endl;
    // 第二次获取是错误的，已被释放(x86)
    cout << *p7 << endl;
    // 堆，手动释放
    int* p8 = heap();
    // 无论运行多少次，都是正常结果
    cout << *p8 << endl;
    cout << *p8 << endl;
    // 使用关键字delete去释放内存
    delete p8;
    // 再次读取，会报错
    // cout << *p8 << endl;
}
