#pragma once
#include<iostream>
using namespace std;

#include<string>//stringͷ�ļ�

class person
{
public:
	person();//Ĭ�Ϲ���
	person(string name, string sex, int age);//�вι���
	person(const person& p);//��������
	~person();//����
public:
	int age;
	string* name;
	string sex;
};