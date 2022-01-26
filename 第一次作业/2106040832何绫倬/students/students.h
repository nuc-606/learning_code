#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Stud
{
	public:
		
		char name1[100];
		char num1[100];
		int  grade1;
		static int count;
		static int add;

		void output();
		void writedown();
		static double  level();
		
		

};
int Stud::count = 0;
int Stud::add = 0;
Stud inf[100];
void Stud::writedown()
{
	while (cin >> inf[count].num1 >> inf[count].name1 >> inf[count].grade1)
	{
		count++;
		char i;
		i = getchar();
		if (i == '\n')
		{
			break;
		}
		
	}
}

void Stud::output()
{
	for (int j = 0; j < count; j++)
	{
		add += inf[j].grade1;
		cout << "姓名:" << inf[j].name1 <<'\t' << "学号:" << inf[j].num1<<'\t' << "分数:" << inf[j].grade1 << endl;
	}
	cout << "总和" <<add<< endl;
	cout << "人数" << count << endl;
	cout << "平均分" << Stud::level()<< endl;
}
double Stud::level()
{
	
	
	return  add / count;
}

