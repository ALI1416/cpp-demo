#include<iostream>
using namespace std;
#include"lib/MyArray.hpp"

void main035()
{
    MyArray<int> a1(5);
    MyArray<int> a2(a1);
    MyArray<int> a3(10);
    a3 = a2 = a1;

    a1.push(1);
    a1.push(2);
    a1.push(3);
    a1.push(4);
    a1.push(5);
    // 插入失败
    a1.push(6);
    try {
        cout << a1.pop() << endl;
        cout << a1.pop() << endl;
        a1.del();
        a1.del();
        cout << a1.pop() << endl;
        // 弹出异常
        cout << a1.pop() << endl;
    }
    // 捕获异常字符串
    catch (const char* c)
    {
        cout << "异常：" << c << endl;
    }

    a1.push(1);
    a1.push(2);
    a1.push(3);
    cout << a1[1] << endl;
    // 修改下标对应的值
    a1[1] = 100;
    cout << a1[1] << endl;

    cout << "容量：" << a1.getCapacity() << endl;
    cout << "长度：" << a1.getSize() << endl;

}
