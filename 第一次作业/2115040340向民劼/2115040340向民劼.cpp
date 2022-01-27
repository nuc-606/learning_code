// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<string>
#include <iostream>
using namespace std;
class Person
{
private: string* name; string *sex; int *age; string* na;
public:
   
    Person();
    Person(string nam, string se, int ag);
    Person(const Person &d);
    ~Person();
};

    
Person::Person()
{
    name =new string( "老成");
    sex = new string("男");
    age = new int(18);
};

Person::Person(string nam, string se, int ag)
{
    name = new string(nam);
    sex = new string(se);
    age = new int(ag);
}

Person::Person(const Person &d)
{
    name = new string(*d.name);
    sex = new string(*d.sex);
    age = new int(*d.age);
}

Person::~Person()
{
    cout <<"姓名:" << *name << "\t" <<"性别：" << *sex << "\t" <<"年龄：" << *age << endl;
}
int main()
{
    Person p1;
    Person p2("肥宅","男", 18);
    Person p3(p2);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单
