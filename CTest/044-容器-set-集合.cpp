#include<iostream>
#include<set>
using namespace std;

// 自定义类型
class Person044
{
    friend ostream& operator<<(ostream& cout, Person044& p);
public:
    string name;
    int year;
    Person044(string name, int year) :name(name), year(year) {};
};

// Person044输出
ostream& operator<<(ostream& cout, const Person044& p)
{
    cout << "姓名：" << p.name << "，出生年：" << p.year;
    return cout;
}

// 自定义类型排序
class Person044Sort
{
public:
    // year升序仿函数
    bool operator()(const Person044& v1, const Person044& v2) const
    {
        return v1.year < v2.year;
    }
};

// 自定义排序
class Desc
{
public:
    // 降序仿函数
    bool operator()(const int& v1, const int& v2) const
    {
        return v1 > v2;
    }
};

// 打印
void print(set<int> s)
{
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << ",";
    }
    cout << endl;
}

void print2(set<int, Desc> s)
{
    for (set<int, Desc>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << ",";
    }
    cout << endl;
}

void print3(set<Person044, Person044Sort> s)
{
    for (set<Person044, Person044Sort>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << endl;
    }
}

void print4(multiset<int> s)
{
    for (multiset<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << ",";
    }
    cout << endl;
}

// set是关联式容器，底层采用二叉树存储，元素是有序的
// set不允许有重复值，multiset允许有重复值
void main044()
{
    /* 构造 */
    // 无参(默认)
    // set<T>();
    set<int> s1;
    s1.insert(3);
    s1.insert(1);
    s1.insert(5);
    s1.insert(2);
    s1.insert(4);
    print(s1);
    // 拷贝
    // set<T>(const set<T>& s);
    set<int> s2(s1);
    print(s1);

    /* 赋值 */
    // set赋值给当前set
    // set& operator=(const set& s);
    set<int> s3 = s2;
    print(s1);

    /* 大小操作 */
    set<int> s4;
    // 判断栈是否为空
    // bool empty();
    // 返回栈的长度
    // int size();
    cout << "empty:" << s4.empty() << ",size:" << s4.size() << endl;
    s4.insert(1);
    s4.insert(4);
    s4.insert(7);
    cout << "empty:" << s4.empty() << ",size:" << s4.size() << endl;

    /* 存取 */
    set<int> s5;
    // 插入
    // pair<set<T>::iterator, bool> insert(T& value);
    s5.insert(3);
    s5.insert(1);
    s5.insert(5);
    s5.insert(2);
    s5.insert(4);
    print(s5);
    // 删除迭代器指向元素
    // iterator erase(iterator pos);
    s5.erase(--s5.end());
    print(s5);
    // 删除迭代器start到end之间的元素
    // iterator erase(iterator start, iterator end);
    s5.erase(++s5.begin(), --s5.end());
    print(s5);
    // 删除指定key的元素
    // ? erase(T);
    s5.erase(4);
    // 清空容器
    // void clear();
    s5.clear();
    print(s5);

    /* 查找和统计 */
    set<int> s6;
    s6.insert(3);
    s6.insert(1);
    s6.insert(5);
    s6.insert(2);
    s6.insert(4);
    // 查找是否存在该值，存在返回迭代器，不存在返回s.end();
    // iterator find(T value);
    cout << "查找到的值:" << *s6.find(2) << endl;
    cout << "是否查找到:" << (s6.find(0) != s6.end()) << endl;
    // 统计个数
    // int count(T value);
    cout << "个数:" << s6.count(2) << endl;
    cout << "个数:" << s6.count(0) << endl;

    /* 自定义排序 */
    set<int, Desc> s7;
    s7.insert(3);
    s7.insert(1);
    s7.insert(5);
    s7.insert(2);
    s7.insert(4);
    print2(s7);

    /* 自定义类型排序 */
    set<Person044, Person044Sort> s8;
    s8.insert(Person044("ck", 1998));
    s8.insert(Person044("kk", 1990));
    s8.insert(Person044("ck", 2008));
    print3(s8);

    /* set和multiset */
    set<int> s9;
    pair<set<int>::iterator, bool> r1 = s9.insert(1);
    pair<set<int>::iterator, bool> r2 = s9.insert(1);
    print(s9);
    cout << "第一次插入是否成功:" << r1.second << ",第二次插入是否成功:" << r2.second << endl;
    multiset<int> s10;
    // 插入
    // iterator insert(T& value);
    s10.insert(1);
    s10.insert(1);
    print4(s10);

}
