#pragma once
#include"head.h"

int main()
{
	cout << "������ѧ��������";
	int N = 0;
	cin >> N;

	Stu* student = new Stu[N];//��̬��������
	Stu::people = N;
	in_all(student, N);//����ȫ����Ϣ
	out_all(student, N);//��ӡȫ����Ϣ
	sum_score(student, N);//���
	avar();//��ƽ���ɼ�

	delete []student;
	return 0;
}