#include<iostream>
using namespace std;

// 声明
class Room;

// 建筑
class Buliding
{
public:
    Buliding();
    Room* r;
    void visit();
};

// 房间
class Room
{
    // 友元：可以访问私有属性、方法
    // 全局函数
    friend void globalFun(Room* r);
    // 类
    friend class Floor;
    // 方法
    friend void Buliding::visit();

public:
    string sittingRoom = "客厅";
private:
    string bedRoom = "卧室";
};

// 楼层
class Floor
{
public:
    Floor();
    Room* r;
    void visit();
};

// 全局函数
void globalFun(Room* r)
{
    cout << "全局函数访问：" << r->sittingRoom << endl;
    cout << "全局函数访问：" << r->bedRoom << endl;
}

// 外部定义方法
Floor::Floor()
{
    r = new Room;
}
void Floor::visit()
{
    cout << "类访问：" << r->sittingRoom << endl;
    cout << "类访问：" << r->bedRoom << endl;
}
Buliding::Buliding()
{
    r = new Room;
}
void Buliding::visit()
{
    cout << "方法访问：" << r->sittingRoom << endl;
    cout << "方法访问：" << r->bedRoom << endl;
}

void main()
{
    Room r;
    globalFun(&r);

    Floor f;
    f.visit();

    Buliding b;
    b.visit();
}
