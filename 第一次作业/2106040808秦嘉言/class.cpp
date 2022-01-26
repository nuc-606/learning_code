#pragma once
#include"head.h"
int Stu::calc(int a, int b)
{
	return a / b;
}
void Stu::set_all()
{
	cout << "ÐÕÃû£º";
	cin >> name;
	cout << "Ñ§ºÅ£º";
	cin >> id;
	cout << "³É¼¨£º";
	cin >> score;
}
void Stu::print_s()
{
	cout << name << "  \t"
		<< id << "  \t"
		<< score << "  \t" << endl;
}
int Stu::all_score = 0;
int Stu::people = 0;