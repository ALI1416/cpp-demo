#include<iostream>
#include<queue>
using namespace std;

// 队列(Queue) 先进先出 FIFO(First In First Out)
void main041()
{
    /* 构造 */
    // 无参(默认)
    // queue<T>();
    queue<int> q1;
    q1.push(123);
    cout << q1.front() << endl;
    // 拷贝
    // queue<T>(const queue<T>& q);
    queue<int> q2(q1);
    cout << q2.front() << endl;

    /* 赋值 */
    // queue赋值给当前queue
    // queue& operator=(const queue& q);
    queue<int> q3 = q2;
    cout << q3.front() << endl;

    /* 存取 */
    queue<int> q4;
    // 压入元素
    // void push(T& value);
    q4.push(123);
    q4.push(456);
    q4.push(789);
    // 取出头部元素
    // T& front();
    cout << q4.front() << endl;
    // 取出尾部元素
    // T& back();
    cout << q4.back() << endl;
    // 弹出头部元素
    // void pop();
    q4.pop();
    cout << q4.front() << endl;

    /* 大小操作 */
    queue<int> q5;
    // 判断队列是否为空
    // bool empty();
    // 返回队列的长度
    // int size();
    cout << "empty:" << q5.empty() << ",size:" << q5.size() << endl;
    q5.push(1);
    q5.push(4);
    q5.push(7);
    cout << "empty:" << q5.empty() << ",size:" << q5.size() << endl;

}
