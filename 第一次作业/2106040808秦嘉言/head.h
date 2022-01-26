#pragma once
#include<iostream>
using namespace std;
#include<string>//string头文件
#include<malloc.h>

class Stu
{
public:
	static int calc(int a, int b);
	void set_all();//输入信息
	void print_s();//打印信息
public:
	string name;
	int id;
	int score;
	static int all_score;
	static int people;
};
void in_all(Stu student[], int len);
void out_all(Stu student[], int len);
void sum_score(Stu student[], int len);
void avar();