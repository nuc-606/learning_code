#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
	string* n_name;
	string Gender;
	int Age;
public:
	Person()
	{
		n_name = new string("Mike");
		Gender = "man";
		Age = 19;
	}
	Person(string name, string gender, int age)
	{
		n_name = new string(name);
		Gender = gender;
		Age = age;

	}
	Person(const Person& p)
	{
		n_name = new string(*p.n_name);
		Gender = p.Gender;
		Age = p.Age;
	}
	~Person()
	{
		cout << "Name:" << *n_name << "\tGender" << Gender << "\tAge" << Age << endl;
	}


};
void person1()
{
	Person p;
}
void message()
{
	Person p1("John", "man", 23);
	Person p2(p1);
}
int main() {
	person1();
	message();

	return 0;
}
