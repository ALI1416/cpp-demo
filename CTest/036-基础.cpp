#include<iostream>
// 导入vector数组库
#include<vector>
// 导入标准算法库
#include<algorithm>
using namespace std;

/* 基本概念 */
// STL (Standard Template Library) 标准模板库
// 广义分为3种：容器(container)、算法(algorithm)、迭代器(iterator)
// `容器`和`算法`之间，通过`迭代器`进行无缝连接
// STL几乎所有的代码都采用了模板类或者模板函数
/* 六大组件 */
// 1、容器：数据结构。如string[字符串]、vector[单端数组]、deque[双端数组]、stack[栈]、queue[队列]、list[双向循环链表]、pari[对组]、(multi)set[(可重复)集合]、(multi)map[(可重复)映射]等
// 2、算法：常用算法。如for_each[遍历]、transform[转移]、find(_if)[(条件)查找]、adjacent_find[相邻元素查找]、binary_search[存在]、count(_if)[(条件)计数]、sort[排序]、merge[合并]、reverse[反转]、random_shuffle[洗牌]、copy[拷贝]、replace(_if)[(条件)替换]、swap[交换]、accumulate[累计]、fill[填充]、set_intersection[交集]、set_union[并集]、set_difference[差集]等
// 3、迭代器：扮演了`容器`和`算法`之间的胶合剂
// 4、仿函数：行为类似`函数`，可作为算法的某种策略
// 5、适配器：一种用来修饰`容器`或者`仿函数`或者`迭代器接口`的东西
// 6、空间配置器：负责空间配置和管理
/* 容器 */
// - 序列式容器：有序
// - 关联式容器：无序，二叉树存储
/* 算法 */
// - 质变算法：会改变元素内容
// - 非质变算法：不会改变元素内容
/* 迭代器 */
// 1、输入迭代器  只读  ++、==、!=
// 2、输出迭代器  只写  ++
// 3、前向迭代器  读写、前推   ++、==、!=
// 4、双向迭代器  读写、前后推  ++、--
// 5、随机访问迭代器    读写、跳跃推进     ++、--、[n]、-n、<、<=、>、>=
// 容器中常用`双向迭代器`和`随机访问迭代器`

// 打印
void myPrint(int v)
{
    cout << v << endl;
}

void main036()
{
    // 创建vector`容器`
    vector<int> v;

    // 向容器中插入数据
    v.push_back(11);
    v.push_back(12);
    v.push_back(13);
    v.push_back(14);

    // 通过`迭代器`访问`容器`中的数据
    // 起始迭代器，指向容器中的第一个元素(返回指针)
    vector<int>::iterator itBegin = v.begin();
    // 结束迭代器，指向容器中的最后一个元素的下一个位置
    vector<int>::iterator itEnd = v.end();

    // 第一种遍历方式,while
    cout << "while" << endl;
    while (itBegin != itEnd)
    {
        cout << *itBegin << endl;
        itBegin++;
    }

    // 第二种遍历方式,for
    cout << "for" << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }

    // 第三种遍历方式,for_each(algorithm库提供的算法)
    cout << "for_each" << endl;
    // 起始，结束+1，遍历方法
    for_each(v.begin(), v.end(), myPrint);

}
