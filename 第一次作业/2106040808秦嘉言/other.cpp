#pragma once
#include"head.h"

void in_all(Stu student[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "�������" << i + 1 << "��ѧ������Ϣ��" << endl;
		student[i].set_all();
	}
}
void out_all(Stu student[], int len)
{
	cout << "����    " << "ѧ��    " << "�ɼ�    " << endl;
	for (int i = 0; i < len; i++)
	{
		student[i].print_s();
	}
}
void sum_score(Stu student[], int len)
{
	for (int i = 0; i < len; i++)
	{
		Stu::all_score += student[i].score;
	}
}
void avar()
{
	cout << "�ܳɼ���" << Stu::all_score << endl;
	cout << "��������" << Stu::people << endl;
	cout << "ƽ���ɼ���"
		<< Stu::calc(Stu::all_score, Stu::people) << endl;
}