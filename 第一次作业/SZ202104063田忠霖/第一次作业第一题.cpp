// 2022_1_26work.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
class Person
{
public:
	string name;
	string sex;
	int age;
	Person(void);
	void PersonSet(string name, string sex, int age);
	Person( const Person &obj);
	void PersonPrint(void);
	~Person(void);
	Person* ptr;	
};
Person::Person(void) {
	name = "初始化姓名";
	sex = "初始化性别";
	age = 0;
}
void Person::PersonSet(string name_input, string sex_input, int age_input) {
	name = name_input;
	sex = sex_input;
	age = age_input;
	cout << "Structure Success!" << endl;
}
Person::Person(const Person &obj) {
	name = obj.name;
	sex = obj.sex;
	age = obj.age;
	cout << "Copy Success!"  << endl;
}
void Person::PersonPrint() {
	cout << "姓名:" << name << " 性别:" << sex << " 年龄:" << age << endl;
}
Person::~Person() {
}
int main()
{
	Person p1;
	Person p2;

	p1.PersonSet("一号玩家", "男", 22);
	p1.PersonPrint();

	p2.PersonSet("二号玩家", "女", 20);

	Person p3(p2);
	p3.PersonPrint();
}
