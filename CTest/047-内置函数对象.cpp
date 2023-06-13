#include<iostream>
// 内置函数对象头文件
#include<functional>
using namespace std;

// 内置函数对象(仿函数)
// 算数、关系、逻辑
void main047()
{
    /* 算数仿函数 */
    // 功能：实现四则运算
    // 原型：plus(加)、minus(减)、multiplies(乘)、divides(除)、modulus(模)、negate(反)
    // 其中negate是一元运算，其他都是二元运算
    // 反
    // T negate<T>(T& t);
    negate<int> n;
    cout << n(123) << endl;
    // 加
    // T plus<T>(T& t1, T& t2);
    plus<int> p;
    cout << p(123, 456) << endl;
    // 减
    // T minus<T>(T& t1, T& t2);
    minus<int> mi;
    cout << mi(123, 456) << endl;
    // 乘
    // T multiplies<T>(T& t1, T& t2);
    multiplies<int> mu;
    cout << mu(123, 456) << endl;
    // 除
    // T divides<T>(T& t1, T& t2);
    divides<int> d;
    cout << d(456, 123) << endl;
    // 模
    // T modulus<T>(T& t1, T& t2);
    modulus<int> mo;
    cout << mo(456, 123) << endl;

    /* 关系仿函数 */
    // 功能：实现大小判断
    // 原型：equal_to(等于)、not_equal_to(不等)、greater(大于)、greater_equal(大于等于)、less(小于)、less_equal(小于等于)
    // 等于
    // bool equal_to<T>(T& t1, T& t2);
    equal_to<int> eq;
    cout << eq(123, 456) << endl;
    // 不等
    // bool not_equal_to<T>(T& t1, T& t2);
    not_equal_to<int> neq;
    cout << neq(123, 456) << endl;
    // 大于
    // bool greater<T>(T& t1, T& t2);
    greater<int> gt;
    cout << gt(123, 456) << endl;
    // 大于等于
    // bool greater_equal<T>(T& t1, T& t2);
    greater_equal<int> gte;
    cout << gte(123, 456) << endl;
    // 小于
    // bool less<T>(T& t1, T& t2);
    less<int> lt;
    cout << lt(123, 456) << endl;
    // 小于等于
    // bool less_equal<T>(T& t1, T& t2);
    less_equal<int> lte;
    cout << lte(123, 456) << endl;

    /* 逻辑仿函数 */
    // 功能：实现逻辑运算
    // 原型：logical_and(逻辑与)、logical_or(逻辑或)、logical_not(逻辑非)
    // 其中logical_not是一元运算，其他都是二元运算
    // 逻辑非
    // bool logical_not<T>(T& t);
    logical_not<bool> logNot;
    cout << logNot(true) << endl;
    // 逻辑与
    // bool logical_and<T>(T& t1, T& t2);
    logical_and<bool> logAnd;
    cout << logAnd(true, false) << endl;
    // 逻辑或
    // bool logical_or<T>(T& t1, T& t2);
    logical_or<bool> logOr;
    cout << logOr(true, false) << endl;

}
