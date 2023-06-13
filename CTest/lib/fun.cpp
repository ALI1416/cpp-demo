#include<iostream>
using namespace std;

// 定义函数
void print(int num)
{
    cout << "输入的数字为：" << num << endl;
}

// 交换-值传递
void swap01(int num1, int num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
    cout << "swap01：num1：" << num1 << "，num2：" << num2 << endl;
}

// 交换-地址传递
void swap02(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
    cout << "swap02：num1：" << *num1 << "，num2：" << *num2 << endl;
}

// 交换-引用传递
void swap03(int& num1, int& num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
    cout << "swap03：num1：" << num1 << "，num2：" << num2 << endl;
}
