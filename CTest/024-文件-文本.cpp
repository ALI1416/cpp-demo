#include<iostream>
// 文件操作头文件fstream包含读写
// ifstream读文件
// ofstream写文件
#include<fstream>
#include<string>
using namespace std;

void main024()
{
    /* 写文件 */
    // 创建文件输出流对象
    ofstream ofs;
    // 打开文件
    // 参数(输出文件路径,写入模式)
    // 读写模式，多个模式，使用|隔开
    // ios::out     写文件(覆盖)
    // ios::app     写文件(追加)
    // ios::in      读文件
    // ios::binary  二进制方式
    // ios::trunc   写文件(覆盖)
    // ios::ate     文件尾
    ofs.open("/1.txt", ios::out);
    // 写入数据
    ofs << "Hello, World !" << endl;
    ofs << "Hello, C++ !" << endl;
    // 关闭
    ofs.close();

    /* 读文件 */
    ifstream ifs;
    ifs.open("/1.txt", ios::in);
    // 如果文件打开成功
    if (ifs.is_open())
    {
        // 读文件
        // 1.根据分隔符来读取(空格、换行)
        //char buf1[1024] = {0};
        //while (ifs >> buf1)
        //{
        //    cout << buf1 << endl;
        //}
        // 2.一次读取一行
        //char buf2[1024] = {0};
        //while (ifs.getline(buf2, sizeof(buf2)))
        //{
        //    cout << buf2 << endl;
        //}
        // 3.使用string库，一次读取一行(需要引入string库)
        string buf3;
        while (getline(ifs, buf3))
        {
            cout << buf3 << endl;
        }
        // 4.一次读取一个字节(不推荐)
        //char buf4;
        //while ((buf4 = ifs.get()) != EOF)
        //{
        //     cout << buf4;
        //}
    }
    ifs.close();
}
