#include <iostream>

using namespace std;

class Person
{
public:
	char name[200] = "\0";
	char sex[100] = "\0";
	int age;
	Person();
	Person(const char* p, int m, const char* q);
	Person( const Person &t);
	~Person();
};

Person::Person()
{
	cout << "请输入成员姓名、性别、年龄：" << endl;
	cin >> name >> sex >> age;
}

Person::Person(const char* p, int m, const char* q)
{
	strcpy_s(name, p);
	age = m;
	strcpy_s(sex, q);
}

Person::Person(const Person& t)
{
	name[20] = *t.name;
	sex[10] = *t.sex;
	age = t.age;
}

Person::~Person()
{
	printf("姓名：%s\n性别：%s\n年龄：%d\n", name, sex, age);
}