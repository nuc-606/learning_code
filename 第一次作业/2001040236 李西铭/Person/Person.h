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
	cout << "�������Ա�������Ա����䣺" << endl;
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
	printf("������%s\n�Ա�%s\n���䣺%d\n", name, sex, age);
}