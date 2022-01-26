#include <iostream>
#include <string>
using namespace std;

class person
{
public:
	person()
	{
		m_name = new string("����");
		m_age = 18;
		m_sex = "��";
	}
	person( string name,string sex, int age)
	{
		m_name = new string(name);
		m_age = age;
		m_sex = sex;
	}
	person(const person &p)
	{
		m_name = new string(*p.m_name);
		m_age = p.m_age;
		m_sex = p.m_sex;
	}
	~person()
	{

		cout << "������" << *m_name << " �Ա�" << m_sex << " ���䣺" << m_age << endl;
		if (m_name != NULL)
		{
			delete m_name;
			m_name = NULL;
		}
	}
public:
	string* m_name;
	string m_sex;
	int m_age;
};
void text_1()
{
	person p;
}
void text_2()
{
	person p1("����", "��", 18);
	person p2(p1);
}



int main()
{

	text_1();
	text_2();

	return 0;
}