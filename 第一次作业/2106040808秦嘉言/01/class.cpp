#include"all.h"

person::person()
{
	name = new string("ÍõÎå");
	sex = "Å®";
	age = 25;
}
person::person(string name, string sex, int age)
{
	this->sex = sex;
	this->age = age;
	this->name = new string(name);
}
person::person(const person& p)
{
	name = new string(*p.name);
	age = p.age;
	sex = p.sex;
}
person::~person()
{
	cout << *name << "  " << sex << "  " << age << endl;
	if (name != NULL)
	{
		delete name;
		name = NULL;
	}
}