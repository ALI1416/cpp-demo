#include<iostream>
// 导入string字符串库
#include<string>
// 导入标准算法库
#include<algorithm>
using namespace std;

// string是c++风格的字符串，本质是一个类
/* string和char*区别 */
// char*是一个指针
// string是一个类，内部封装了char*，来管理这个字符串，是char*型的容器
void main()
{

    /* 构造 */
    // 空字符串(默认)
    // string();
    string s1;
    // 使用字符串s初始化
    // string(const char* s);
    const char* s = "字符串";
    string s2(s);
    // 等价const char*
    string s3("string");
    // 使用一个string对象初始化另一个string对象(拷贝构造)
    // string(const string& s);
    string s4(s2);
    // 使用n个字符c初始化
    // string(int n, char c);
    string s5(10, 'a');
    cout << "构造:s1:" << s1 << ",s2:" << s2 << ",s3:" << s3 << ",s4:" << s4 << ",s5:" << s5 << endl;

    /* 赋值操作 */
    // char*类型字符串赋值给当前字符串
    // string& operator=(const char* s);
    string s6 = "hello";
    // 字符串赋值给当前字符串
    // string& operator=(const string& s);
    string s7 = s6;
    // 字符赋值给当前字符串
    // string& operator=(const char c);
    string s8;
    s8 = 'a';
    // char*类型字符串赋值给当前字符串
    // string& assign(const char* s);
    string s9;
    s9.assign("world");
    // char*类型字符串的前n个字符赋值给当前字符串
    // string& assign(const char* s, int n);
    string s10;
    s10.assign("string", 3);
    // 字符串赋值给当前字符串
    // string& assign(const string& s);
    string s11;
    s11.assign(s10);
    // 使用n个字符赋值给当前字符串
    // string& assign(int n, char c);
    string s12;
    s12.assign(3, 'b');
    cout << "赋值:s6:" << s6 << ",s7:" << s7 << ",s8:" << s8 << ",s9:" << s9 << ",s10:" << s10 << ",s11:" << s11 << ",s12:" << s12 << endl;

    /* 拼接 */
    // 当前字符串追加char*类型字符串
    // string& operator+=(const char* s);
    string s13 = "he";
    s13 += "llo ";
    cout << "拼接:s13:" << s13;
    // 当前字符串追加字符
    // string& operator+=(const char c);
    s13 += 'w';
    cout << ",s13:" << s13;
    // 当前字符串追加字符串
    // string& operator+=(const string& s);
    string s14 = "orld";
    s13 += s14;
    cout << ",s13:" << s13;
    // 当前字符串追加char*类型字符串
    // string& append(const char* s);
    s13.append(" hi");
    // 当前字符串追加char*类型字符串的前n个字符
    // string& append(const char* s, int n);
    s13.append(" C++++", 4);
    cout << ",s13:" << s13;
    // 当前字符串追加字符串
    // string& append(const string& s);
    string s15 = " 你好，";
    s13.append(s15);
    cout << ",s13:" << s13;
    // 当前字符串追加字符串，从pos开始的前n个字符
    // string& append(const string& s, int pos, int n);
    string s16 = "你好，世界！！";
    // 1个汉字，占2个字符
    s13.append(s16, 6, 6);
    cout << ",s13:" << s13 << endl;

    /* 查找 */
    // 从左向右查找
    // 查找字符串第一次出现的位置，从pos开始
    // int find(const string& s, int pos = 0) const;
    string s17 = "abcdefaabbccddeeffaaaffeeddbbccaafedbca";
    string s18 = "aa";
    cout << "查找第一次:pos:" << s17.find(s18);
    cout << ",pos:" << s17.find(s18, 10);
    // 查找char*类型字符串第一次出现的位置，从pos开始
    // int find(const char* s, int pos = 0) const;
    cout << ",pos:" << s17.find("aa");
    cout << ",pos:" << s17.find("aa", 10);
    // 查找char*类型字符串的前n个字符的第一次出现的位置，从pos开始
    // int find(const char* s, int pos, int n) const;
    cout << ",pos:" << s17.find("aaa", 0, 2);
    // 查找字符第一次出现的位置，从pos开始
    // int find(const char c, int pos = 0) const;
    cout << ",pos:" << s17.find('a');
    cout << ",pos:" << s17.find('a', 10) << endl;
    // 从右向左查找
    // 查找字符串最后一次出现的位置，从npos开始
    // int rfind(const string& s, int npos = 0) const;
    cout << "查找最后一次:pos:" << s17.rfind(s18);
    cout << ",pos:" << s17.rfind(s18, 10);
    // 查找char*类型字符串最后一次出现的位置，从npos开始
    // int rfind(const char* s, int npos = 0) const;
    cout << ",pos:" << s17.rfind("aa");
    cout << ",pos:" << s17.rfind("aa", 10);
    // 查找char*类型字符串的前n个字符的最后一次出现的位置，从npos开始
    // int rfind(const char* s, int npos, int n) const;
    cout << ",pos:" << s17.rfind("aaa", 100, 2);
    // 查找字符最后一次出现的位置，从npos开始
    // int rfind(const char c, int npos = 0) const;
    cout << ",pos:" << s17.rfind('a');
    cout << ",pos:" << s17.rfind('a', 10) << endl;

    /* 替换 */
    // 替换为指定字符串，从pos开始的n个字符
    // string& replace(int pos, int n, const string& s);
    string s19 = "12345";
    s17.replace(0, 3, s19);
    cout << "替换:s17:" << s17 << endl;
    // 替换为指定char*类型字符串，从pos开始的n个字符
    // string& replace(int pos, int n, const char* s);
    s17.replace(10, 3, "12345");
    cout << "替换:s17:" << s17 << endl;

}
