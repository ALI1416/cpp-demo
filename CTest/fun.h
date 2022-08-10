// 如果不存在__FUN_H__这个名字，才执行他和#endif之间的语句
#ifndef __FUN_H__
// 定义__FUN_H__这个名字，防止重复编译
#define __FUN_H__

// 声明函数
void print(int num);

#endif
