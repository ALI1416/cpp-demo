// pragma once声明可以防止该文件被重复编译，旧版本可能不支持
// 通常pragma once和#ifndef都写上
#pragma once
// 如果不存在__FUN_H__这个名字，才执行他和#endif之间的语句
#ifndef __FUN_H__
// 定义__FUN_H__这个名字，防止重复编译
#define __FUN_H__

// 声明函数
void print(int num);
void swap01(int num1, int num2);
void swap02(int* num1, int* num2);
void swap03(int& num1, int& num2);

#endif
