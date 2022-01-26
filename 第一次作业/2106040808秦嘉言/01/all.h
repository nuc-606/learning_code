#pragma once
#include<iostream>
using namespace std;

#include<string>//string头文件

class person
{
public:
	person();//默认构造
	person(string name, string sex, int age);//有参构造
	person(const person& p);//拷贝构造
	~person();//析构
public:
	int age;
	string* name;
	string sex;
};