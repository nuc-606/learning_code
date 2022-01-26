#pragma once
#include <iostream>
#include <assert.h>

class Person
{
	public:
		Person();
		Person(std::string *nameth,int ageth,std::string sexth);
		Person(const Person&);
		~Person();
		
	
		 std::string name;
		 int age;
		 std::string sex;
};

Person::Person()
{
	name = "小明";
	age = 18;
	sex = "male";
	
}

Person::Person(std::string *nameth, int ageth, std::string sexth)
{
	name = *nameth;
	age = ageth;
	sex = sexth;
}

Person::Person(const Person &c)
{
	name = *new std::string("小芳");
	age = c.age;
	sex = c.sex;
	
}
Person::~Person()
{
	std::cout << "姓名" << name << "\n" << "年龄" << age << "\n" << "性别" << "\n" << sex << std::endl;
}