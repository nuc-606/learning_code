#pragma once
#include"head.h"

void in_all(Stu student[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "请输入第" << i + 1 << "个学生的信息：" << endl;
		student[i].set_all();
	}
}
void out_all(Stu student[], int len)
{
	cout << "姓名    " << "学号    " << "成绩    " << endl;
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
	cout << "总成绩：" << Stu::all_score << endl;
	cout << "总人数：" << Stu::people << endl;
	cout << "平均成绩："
		<< Stu::calc(Stu::all_score, Stu::people) << endl;
}