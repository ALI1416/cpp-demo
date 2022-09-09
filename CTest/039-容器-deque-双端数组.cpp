#include<iostream>
#include<deque>
using namespace std;

// 打印
void print(deque<int> d)
{
    for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << ",";
    }
    cout << endl;
}

/* vector和deque区别 */
// vector对头部插入和删除效率低
// vector访问元素速度快
// deque没有容量限制
/* deque存储结构 */
// 内部有一个`中控器`，用于记录`缓冲区`的地址，`缓冲区`里存放数据
//  中控器                  缓冲区
// |------|
// | 0x01 |  ->  | 元素 | 元素 | 元素 | 元素 |
// | 0x02 |  ->  | 元素 | 元素 | 元素 | 元素 |
// | 0x03 |  ->  | 元素 | 元素 | 元素 | 元素 |
// | .... |
// |------|
void main039()
{
    /* 构造 */
    // 无参(默认)
    // deque<T>();
    deque<int> d1;
    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);
    print(d1);
    // 区间
    // 将d[begin,end)区间内的元素拷贝给自己
    // deque<T>(iterator begin, iterator end);
    deque<int> d2(d1.begin(), d1.end());
    print(d2);
    // n个元素
    // deque<T>(int n, int value);
    deque<int> d3(10, 1);
    print(d3);
    // 拷贝
    // deque<T>(const deque<T>& d);
    deque<int> d4(d3);
    print(d4);
    
    /* 赋值 */
    // deque赋值给当前deque
    // deque& operator=(const deque& d);
    deque<int> d5 = d1;
    print(d5);
    // 将d[begin,end)区间内的元素拷贝给自己
    // void assign(iterator begin, iterator end);
    deque<int> d6;
    d6.assign(d1.begin(), d1.end());
    print(d6);
    // n个元素
    // void assign(int n, int value);
    deque<int> d7;
    d7.assign(10, 1);
    print(d7);

    /* 大小 */
    deque<int> d8;
    // 判断是否为空
    // bool empty() const;
    cout << "empty:" << d8.empty();
    // 大小
    // bool size() const;
    cout << ",size:" << d8.size() << endl;
    for (int i = 0; i < 10; i++)
    {
        d8.push_back(i);
    }
    print(d8);
    cout << "empty:" << d8.empty();
    cout << ",size:" << d8.size() << endl;
    // 重新指定容器大小。变大：填充默认值；变小：尾部删除
    d8.resize(30);
    print(d8);
    d8.resize(5);
    print(d8);
    // 重新指定容器大小。变大：填充指定值；变小：尾部删除
    d8.resize(30, 5);
    print(d8);
    d8.resize(20, 100);
    print(d8);

    /* 插入和删除 */
    deque<int> d9;
    // 尾部插入
    // void push_back(T& value);
    d9.push_back(6);
    d9.push_back(7);
    // 头部插入
    // void push_front(T& value);
    d9.push_front(8);
    d9.push_front(9);
    print(d9);
    // 删除尾部
    // void pop_back();
    d9.pop_back();
    // 删除头部
    // void pop_front();
    d9.pop_front();
    print(d9);
    // 迭代器指向位置前插入元素
    // iterator insert(iterator pos, T& value);
    d9.insert(d9.begin(), 10);
    print(d9);
    // 迭代器指向位置前插入n个元素
    // iterator insert(iterator pos, int count, T& value);
    d9.insert(d9.begin() + 2, 5, 100);
    print(d9);
    // 删除迭代器指向元素
    // iterator erase(iterator pos);
    d9.erase(d9.end() - 1);
    print(d9);
    // 删除迭代器start到end之间的元素
    // iterator erase(iterator start, iterator end);
    d9.erase(d9.begin() + 2, d9.end() - 2);
    print(d9);
    // 清空容器
    // void clear();
    d9.clear();
    print(d9);

    /* 存取 */
    deque<int> d10;
    for (int i = 0; i < 10; i++)
    {
        d10.push_back(i);
    }
    print(d10);
    // 返回索引元素
    // T& at(int index);
    cout << "at:" << d10.at(3);
    // 返回索引元素
    // T& operator[](int index);
    cout << ",operator[]:" << d10[3];
    // 返回第一个元素
    // T& front();
    cout << ",front:" << d10.front();
    // 返回最后一个元素
    // T& back();
    cout << ",back:" << d10.back() << endl;

}
