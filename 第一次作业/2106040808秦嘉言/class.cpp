#pragma once
#include"head.h"
int Stu::calc(int a, int b)
{
	return a / b;
}
void Stu::set_all()
{
	cout << "������";
	cin >> name;
	cout << "ѧ�ţ�";
	cin >> id;
	cout << "�ɼ���";
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