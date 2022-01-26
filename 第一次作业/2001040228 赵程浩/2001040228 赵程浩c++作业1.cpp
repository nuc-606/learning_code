#include <iostream>
using namespace std;
class Person
{
 	static int count;
public:
	char *Name,Sex;
	int Age;
	Person()
	{
		Name = new char('X');
		Sex = 'N';
		Age = 18;
	}
	Person(char *p,char sex,int age)
	{
		Name = p;
		Sex = sex;
		Age = age;
	}
	Person(const Person& P)
	{
		this->Age = P.Age;
		this->Sex = P.Sex;
		Name = new char;
		*Name = *(P.Name);
	}
	~Person()
	{
		count++;
		cout << "对象已析构" <<count<< endl;
	}
	void printf()
	{
		cout << "年龄为" << Age << endl;
		cout << "性别" << Sex << endl;
		cout << "姓名" << *Name << endl;
	}

};
int Person::count = 0;

int main()
{
	char name;
	name= 'Y';
	char *p;
	p = &name;
		Person P1;
		Person P2(p,'N', 20);
		Person P3(P2);
		P1.printf();
		P2.printf();
		P3.printf();
		return 0;
}