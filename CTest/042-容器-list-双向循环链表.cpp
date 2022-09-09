#include<iostream>
#include<list>
using namespace std;

// 打印
void print(list<int> t)
{
    // 双向迭代器，只支持++、--
    for (list<int>::const_iterator it = t.begin(); it != t.end(); it++)
    {
        cout << *it << ",";
    }
    cout << endl;
}

// 双向循环链表
// 非连续存储
// 链表由节点构成，节点由`数据域`和`指针域`(包括前指针和后指针)构成
// |------| |------| |------| |------|
// | data | | data | | data | | data |
// |------| |------| |------| |------|
// | prev | | prev | | prev | | prev |
// | next | | next | | next | | next |
// |------| |------| |------| |------|
// 其中第一个节点的prev指针指向最后一个节点，最后一个节点的next指针指向第一个节点
void main042()
{
    /* 构造 */
    // 无参(默认)
    // list<T>();
    list<int> t1;
    t1.push_back(1);
    t1.push_back(2);
    t1.push_back(3);
    print(t1);
    // 区间
    // 将t[begin,end)区间内的元素拷贝给自己
    // list<T>(const_iterator begin, const_iterator end);
    list<int> t2(t1.begin(), t1.end());
    print(t2);
    // n个元素
    // list<T>(int n, int value);
    list<int> t3(10, 1);
    print(t3);
    // 拷贝
    // list<T>(const list<T>& d);
    list<int> t4(t3);
    print(t4);

    /* 赋值 */
    // list赋值给当前list
    // list& operator=(const list& d);
    list<int> t5 = t1;
    print(t5);
    // 将t[begin,end)区间内的元素拷贝给自己
    // void assign(const_iterator begin, const_iterator end);
    list<int> t6;
    t6.assign(t1.begin(), t1.end());
    print(t6);
    // n个元素
    // void assign(int n, int value);
    list<int> t7;
    t7.assign(10, 1);
    print(t7);

    /* 大小 */
    list<int> t8;
    // 判断是否为空
    // bool empty() const;
    cout << "empty:" << t8.empty();
    // 大小
    // bool size() const;
    cout << ",size:" << t8.size() << endl;
    for (int i = 0; i < 10; i++)
    {
        t8.push_back(i);
    }
    print(t8);
    cout << "empty:" << t8.empty();
    cout << ",size:" << t8.size() << endl;
    // 重新指定容器大小。变大：填充默认值；变小：尾部删除
    t8.resize(30);
    print(t8);
    t8.resize(5);
    print(t8);
    // 重新指定容器大小。变大：填充指定值；变小：尾部删除
    t8.resize(30, 5);
    print(t8);
    t8.resize(20, 100);
    print(t8);

    /* 插入和删除 */
    list<int> t9;
    // 尾部插入
    // void push_back(T& value);
    t9.push_back(6);
    t9.push_back(7);
    // 头部插入
    // void push_front(T& value);
    t9.push_front(8);
    t9.push_front(9);
    print(t9);
    // 删除尾部
    // void pop_back();
    t9.pop_back();
    // 删除头部
    // void pop_front();
    t9.pop_front();
    print(t9);
    // 迭代器指向位置前插入元素
    // iterator insert(const_iterator pos, T& value);
    t9.insert(t9.begin(), 10);
    print(t9);
    // 迭代器指向位置前插入n个元素
    // iterator insert(const_iterator pos, int count, T& value);
    t9.insert(++++t9.begin(), 5, 100);
    print(t9);
    // 删除迭代器指向元素
    // iterator erase(const_iterator pos);
    t9.erase(--t9.end());
    print(t9);
    // 删除迭代器start到end之间的元素
    // iterator erase(const_iterator start, const_iterator end);
    t9.erase(++++t9.begin(), ----t9.end());
    print(t9);
    // 移除指定值
    // void remove(T& value);
    t9.remove(100);
    print(t9);
    // 清空容器
    // void clear();
    t9.clear();
    print(t9);

}
