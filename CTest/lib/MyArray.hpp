#pragma once
#ifndef __MY_ARRAY_H__
#define __MY_ARRAY_H__

/// <summary>
/// 自定义数组类
/// </summary>
/// <typeparam name="T">数据类型</typeparam>
template<class T>
class MyArray
{
private:
    // 容量
    int capacity;
    // 大小
    int size;
    // 数据首地址
    T* data;

public:
    /// <summary>
    /// 构造函数
    /// </summary>
    /// <param name="capacity">容量</param>
    MyArray(int capacity)
    {
        cout << this << " 构造函数" << endl;
        this->capacity = capacity;
        this->size = 0;
        this->data = new T[capacity];
    }

    /// <summary>
    /// 拷贝构造
    /// </summary>
    /// <param name="arr">原数组</param>
    MyArray(const MyArray& arr)
    {
        cout << this << " 拷贝构造" << endl;
        this->capacity = arr.capacity;
        this->size = arr.size;
        // 深拷贝，创建堆
        this->data = new T[arr.capacity];
        // 把值复制过来
        for (int i = 0; i < size; i++)
        {
            this->data[i] = arr.data[i];
        }
    }

    /// <summary>
    /// 重载=操作符
    /// </summary>
    /// <param name="arr">原数组</param>
    /// <returns>MyArray</returns>
    MyArray& operator=(const MyArray& arr)
    {
        cout << this << " 重载=操作符" << endl;
        /* 1.析构 */
        // 释放堆区数据
        if (this->data != NULL)
        {
            delete[] this->data;
            this->data = NULL;
        }
        /* 2.拷贝构造 */
        this->capacity = arr.capacity;
        this->size = arr.size;
        // 深拷贝，创建堆
        this->data = new T[arr.capacity];
        // 把值复制过来
        for (int i = 0; i < size; i++)
        {
            this->data[i] = arr.data[i];
        }
        // 3.返回*this
        return *this;
    }

    // 析构函数
    ~MyArray()
    {
        cout << this << " 析构函数" << endl;
        // 释放堆区数据
        if (this->data != NULL)
        {
            delete[] this->data;
            this->data = NULL;
        }
    }

    /// <summary>
    /// 插入到尾部
    /// </summary>
    /// <param name="v">数值</param>
    void push(const T& v)
    {
        // 超出容量
        if (this->size == this->capacity)
        {
            return;
        }
        // 插入到尾部，size++
        this->data[this->size++] = v;
    }

    /// <summary>
    /// 弹出尾部值
    /// </summary>
    /// <returns>尾部值</returns>
    T& pop()
    {
        // 没有值，抛出异常字符串
        if (this->size == 0)
        {
            throw "数组长度为0";
        }
        size--;
        // 返回尾部值
        return data[this->size];
    }

    /// <summary>
    /// 从尾部删除
    /// </summary>
    void del()
    {
        // 没有值，抛出异常字符串
        if (this->size == 0)
        {
            throw "数组长度为0";
        }
        size--;
    }

    /// <summary>
    /// 下标访问和修改
    /// </summary>
    /// <param name="index">下标</param>
    /// <returns>下标对应的值</returns>
    T& operator[](int index)
    {
        return this->data[index];
    }

    /// <summary>
    /// 返回容量
    /// </summary>
    /// <returns></returns>
    int getCapacity()
    {
        return this->capacity;
    }

    /// <summary>
    /// 返回大小
    /// </summary>
    /// <returns></returns>
    int getSize()
    {
        return this->size;
    }

};

#endif
