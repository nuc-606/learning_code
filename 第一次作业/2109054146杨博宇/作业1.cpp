#include "cstring"
#include "string"
#include "stdio.h"
#include "iostream"
using namespace std;
class person
{public:
        string name;
		string sex;
		int age;
		void give(void){name="zhuocuang";
		sex="male";
		age=18;}
		int get(string a,string b,int c)
		{name=a;
		sex=b;
		age=c;}
		int get(person& s)
		{age=s.age;
		sex=s.sex;
		name=s.name;} 
		};
	
	int main()
	{person p1,p2,p3;
	p1=person.give();
	p2=person.get();
	strcpy(p3,p2);}
	


