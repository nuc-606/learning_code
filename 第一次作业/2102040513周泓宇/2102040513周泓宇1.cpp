#include<iostream>
using namespace std;
class Person
{
private:
    int age;
    char name[10];
    int sex;
public:
    Person()
    {
        cout << "请输入年龄姓名性别：";
        cin >> age >> name >> sex;
        cout << "p1的";
    };//无参构造函数声明
    Person(int, char[], int);//有参构造函数声明
    Person(Person&);//拷贝构造函数声明
    ~Person() {};//析构函数声明
    int GetX() { return age; }
    char* GetY() { return name; }
    int GetZ() { return sex; }
    void print()
    {
        cout << "年龄为:" << age << " 姓名为:" << name << " 性别为:";
        if (sex == 1)
        {
            cout << "男" << endl;
        }
        else
        {
            cout << "女" << endl;
        }
    }
};
Person::Person(int x, char y[], int z)//类外定义有参构造函数
{
    age = x;
    strcpy(name, y);
    sex = z;
}
Person::Person(Person& p)//类外定义拷贝构造函数
{
    age = p.age;
    strcpy(name, p.name);
    sex = p.sex;
}

int main()
{
    char p2name[10] = "丽丽：";
    Person p1;//使用print函数，调用无参构造函数创建p1
    p1.print();
    Person p2(12, "丽丽", 1);//调用有参构造函数初始化
    cout << "p2的";
    p2.print();
    Person p3(p2);//用对象p2初始化
    cout << "p3的";
    p3.print();
}