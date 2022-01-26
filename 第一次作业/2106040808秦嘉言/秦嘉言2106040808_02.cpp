#pragma once
#include"head.h"

int main()
{
	cout << "请输入学生个数：";
	int N = 0;
	cin >> N;

	Stu* student = new Stu[N];//动态对象数组
	Stu::people = N;
	in_all(student, N);//输入全部信息
	out_all(student, N);//打印全部信息
	sum_score(student, N);//求和
	avar();//求平均成绩

	delete []student;
	return 0;
}