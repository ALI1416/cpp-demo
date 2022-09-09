#include<iostream>
#include<stack>
using namespace std;

// 栈(Stack) 先进后出 FILO(First In Last Out)
void main040()
{
    /* 构造 */
    // 无参(默认)
    // stack<T>();
    stack<int> s1;
    s1.push(123);
    cout << s1.top() << endl;
    // 拷贝
    // stack<T>(const stack<T>& s);
    stack<int> s2(s1);
    cout << s2.top() << endl;

    /* 赋值 */
    // stack赋值给当前stack
    // stack& operator=(const stack& s);
    stack<int> s3 = s2;
    cout << s3.top() << endl;

    /* 存取 */
    stack<int> s4;
    // 压入元素
    // void push(T& value);
    s4.push(123);
    s4.push(456);
    s4.push(789);
    // 取出元素
    // T& top();
    cout << s4.top() << endl;
    // 弹出元素
    // void pop();
    s4.pop();
    cout << s4.top() << endl;

    /* 大小操作 */
    stack<int> s5;
    // 判断栈是否为空
    // bool empty();
    // 返回栈的长度
    // int size();
    cout << "empty:" << s5.empty() << ",size:" << s5.size() << endl;
    s5.push(1);
    s5.push(4);
    s5.push(7);
    cout << "empty:" << s5.empty() << ",size:" << s5.size() << endl;

}
