#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 打印
void print(vector<int> v)
{
    // 随机访问迭代器 支持所有
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << ",";
    }
    cout << endl;
}

// vector数据结构和普通数组类似，称为单端数组
// 区别：vector数组的静态空间，是可以动态扩展的：找到更大的内存空间，把原数据拷贝进新空间，释放原空间
void main038()
{
    /* 构造 */
    // 无参(默认)
    // vector<T>();
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    print(v1);
    // 区间
    // 将v[begin,end)区间内的元素拷贝给自己
    // vector<T>(iterator begin, iterator end);
    vector<int> v2(v1.begin(), v1.end());
    print(v2);
    // n个元素
    // vector<T>(int n, int value);
    vector<int> v3(10, 1);
    print(v3);
    // 拷贝
    // vector<T>(const vector<T>& v);
    vector<int> v4(v3);
    print(v4);

    /* 赋值 */
    // vector赋值给当前vector
    // vector& operator=(const vector& v);
    vector<int> v5 = v1;
    print(v5);
    // 将v[begin,end)区间内的元素拷贝给自己
    // void assign(iterator begin, iterator end);
    vector<int> v6;
    v6.assign(v1.begin(), v1.end());
    print(v6);
    // n个元素
    // void assign(int n, int value);
    vector<int> v7;
    v7.assign(10, 1);
    print(v7);

    /* 容量和大小 */
    vector<int> v8;
    // 判断是否为空
    // bool empty() const;
    cout << "empty:" << v8.empty();
    // 容量
    // bool capacity() const;
    cout << ",capacity:" << v8.capacity();
    // 大小
    // bool size() const;
    cout << ",size:" << v8.size() << endl;
    for (int i = 0; i < 10; i++)
    {
        v8.push_back(i);
    }
    print(v8);
    cout << "empty:" << v8.empty();
    cout << ",capacity:" << v8.capacity();
    cout << ",size:" << v8.size() << endl;
    // 重新指定容器大小。变大：填充默认值(capacity和size都变为指定大小)；变小：尾部删除(capacity不变，size变为指定大小)
    v8.resize(30);
    print(v8);
    cout << "capacity:" << v8.capacity();
    cout << ",size:" << v8.size() << endl;
    v8.resize(5);
    print(v8);
    cout << "capacity:" << v8.capacity();
    cout << ",size:" << v8.size() << endl;
    // 重新指定容器大小。变大：填充指定值；变小：尾部删除
    v8.resize(30, 5);
    print(v8);
    v8.resize(20, 100);
    print(v8);

    /* 插入和删除 */
    vector<int> v9;
    // 尾部插入
    // void push_back(T& value);
    v9.push_back(6);
    v9.push_back(7);
    v9.push_back(8);
    v9.push_back(9);
    print(v9);
    // 删除尾部
    // void pop_back();
    v9.pop_back();
    print(v9);
    // 迭代器指向位置前插入元素
    // iterator insert(iterator pos, T& value);
    v9.insert(v9.begin(), 10);
    print(v9);
    // 迭代器指向位置前插入n个元素
    // iterator insert(iterator pos, int count, T& value);
    v9.insert(v9.begin() + 2, 5, 100);
    print(v9);
    // 删除迭代器指向元素
    // iterator erase(iterator pos);
    v9.erase(v9.end() - 1);
    print(v9);
    // 删除迭代器start到end之间的元素
    // iterator erase(iterator start, iterator end);
    v9.erase(v9.begin() + 2, v9.end() - 2);
    print(v9);
    // 清空容器(capacity不会变)
    // void clear();
    cout << "capacity:" << v9.capacity();
    cout << ",size:" << v9.size() << endl;
    v9.clear();
    print(v9);
    cout << "capacity:" << v9.capacity();
    cout << ",size:" << v9.size() << endl;

    /* 存取 */
    vector<int> v10;
    for (int i = 0; i < 10; i++)
    {
        v10.push_back(i);
    }
    print(v10);
    // 返回索引元素
    // T& at(int index);
    cout << "at:" << v10.at(3);
    // 返回索引元素
    // T& operator[](int index);
    cout << ",operator[]:" << v10[3];
    // 返回第一个元素
    // T& front();
    cout << ",front:" << v10.front();
    // 返回最后一个元素
    // T& back();
    cout << ",back:" << v10.back() << endl;

    /* 容器互换 */
    vector<int> v11;
    vector<int> v12;
    for (int i = 0; i < 10; i++)
    {
        v11.push_back(i);
    }
    for (int i = 0; i < 50; i++)
    {
        v12.push_back(i + 100);
    }
    print(v11);
    print(v12);
    cout << "v11:capacity:" << v11.capacity();
    cout << ",size:" << v11.size() << endl;
    cout << "v12:capacity:" << v12.capacity();
    cout << ",size:" << v12.size() << endl;
    // 容器互换(容量和大小，也互换)
    // void swap(vector& v);
    v11.swap(v12);
    print(v11);
    print(v12);
    cout << "v11:capacity:" << v11.capacity();
    cout << ",size:" << v11.size() << endl;
    cout << "v12:capacity:" << v12.capacity();
    cout << ",size:" << v12.size() << endl;
    // 特殊用法：收缩内存空间
    vector<int> v13;
    for (int i = 0; i < 10000; i++)
    {
        v13.push_back(i);
    }
    cout << "capacity:" << v13.capacity();
    cout << ",size:" << v13.size() << endl;
    v13.resize(15);
    // 重置大小后，capacity不变
    cout << "capacity:" << v13.capacity();
    cout << ",size:" << v13.size() << endl;
    // 使用该vector创建匿名拷贝对象，并交换空间
    // 匿名对象会被系统系统自动释放
    // capacity大小和size一样大
    vector<int>(v13).swap(v13);
    cout << "capacity:" << v13.capacity();
    cout << ",size:" << v13.size() << endl;

    /* 预留空间 */
    vector<int> v14;
    // 统计内存空间重新开辟的次数
    int n = 0;
    int* p = NULL;
    for (int i = 0; i < 100000; i++)
    {
        v14.push_back(i);
        // 重新开辟内存空间，首地址会改变
        if (p != &v14[0])
        {
            p = &v14[0];
            n++;
            cout << "n:" << n << ",p:" << p << ",size:" << v14.size() << ",capacity:" << v14.capacity() << endl;
        }
    }
    cout << "n:" << n << ",p:" << p << ",size:" << v14.size() << ",capacity:" << v14.capacity() << endl;
    vector<int> v15;
    // 预留len个元素长度，不初始化，不可访问(capacity的值为此)
    v15.reserve(100000);
    cout << "capacity:" << v15.capacity();
    cout << ",size:" << v15.size() << endl;

    /* 排序和反转 */
    vector<int> v16;
    v16.push_back(1);
    v16.push_back(5);
    v16.push_back(2);
    v16.push_back(4);
    v16.push_back(3);
    // 默认升序排列(会改变原数据)
    // void sort(iterator start, iterator end);
    sort(v16.begin(), v16.end());
    print(v16);

}
