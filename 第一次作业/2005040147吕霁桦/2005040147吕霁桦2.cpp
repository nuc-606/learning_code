#include<iostream>
#include<string>
using namespace std;
class student
{
public:
	student()
	{
	}
	void init(string name,int num,int score)
	{
		stu_name = name;
		stu_num = num;
		stu_score = score;
		cout << "����:" << stu_name << " ѧ��:" << stu_num << " ����:" << stu_score << endl;
	}
	static double ava(double & sum_score)
	{
		double aver = sum_score / sum_stu;
		return aver;
	}
public:
	string stu_name;
	int stu_num;
	int stu_score;
	static double sum_score;
	static double sum_stu;
};
double student::sum_score = 0;
double student::sum_stu = 0;

int main()
{
	int i,sum;
	string name="����";
	int num = 0, score = 0;
	double num_score=0;
	cout << "������ѧ������"<<endl;
	cin >> sum;
	student stu[1000];
	cout << "������" << sum << "��ѧ����������ѧ�š�������"<<endl;
	for (i = 1; i <= sum; i++)
	{
		 name = "����";
		 num = 0;
		 score= 0;
		cout << "�������" << i << "��ѧ����������ѧ�š�������" << endl;
		cin >> name >> num >> score;
		stu[i].init(name, num, score);
		num_score += score;
	}
	student::sum_stu = sum;
	cout << "ѧ��ƽ����Ϊ��" << stu[i].ava(num_score) << endl;
	return 0;
}