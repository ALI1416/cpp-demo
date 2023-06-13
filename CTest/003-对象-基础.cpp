#include<iostream>
using namespace std;
#define PI 3.14

// 定义一个类
class Circle
{
    /* 访问权限 */
    // 访问权限有3种
    // public       公共  类内外都可访问
    // protected    保护  类内可访问，类外不可访问
    // private      私有  类内可访问，类外不可访问，子类不可访问
    // 不加修饰符，默认private
public:
    /* 属性 */
    // 圆的半径
    int r;

    /* 方法 */
    // 获取圆的周长
    double getCircumference()
    {
        return 2 * PI * r;
    }

    /* 一般使用get / set方法去取值 / 赋值，属性使用private修饰 */
    // 获取圆的半径
    int getR()
    {
        return r;
    }

    // 设置圆的半径
    void setR(int r)
    {
        // this是指针，代表当前对象
        this->r = r;
    }

    // 判断是否是同一个圆
    // 使用&引用，避免复制，节省内存
    bool isSame(Circle& c)
    {
        return r == c.r;
    }

};

// 判断是否是同一个圆
// 使用&引用，避免复制，节省内存
bool isSame(Circle& c1, Circle& c2)
{
    return c1.r == c2.r;
}

void main003()
{
    Circle c1;
    // public属性直接赋值
    c1.r = 10;
    cout << "圆1的周长为：" << c1.getCircumference() << endl;
    Circle c2;
    // 使用set方法给属性赋值
    c2.setR(20);
    cout << "圆2的半径为：" << c2.getR() << endl;
    cout << "是否为同一个圆：" << isSame(c1, c2) << endl;
    cout << "是否为同一个圆：" << c1.isSame( c2) << endl;
}
