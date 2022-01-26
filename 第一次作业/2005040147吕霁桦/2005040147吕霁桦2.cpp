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
		cout << "姓名:" << stu_name << " 学号:" << stu_num << " 分数:" << stu_score << endl;
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
	string name="姓名";
	int num = 0, score = 0;
	double num_score=0;
	cout << "请输入学生人数"<<endl;
	cin >> sum;
	student stu[1000];
	cout << "请输入" << sum << "个学生的姓名、学号、分数。"<<endl;
	for (i = 1; i <= sum; i++)
	{
		 name = "姓名";
		 num = 0;
		 score= 0;
		cout << "请输入第" << i << "个学生的姓名、学号、分数。" << endl;
		cin >> name >> num >> score;
		stu[i].init(name, num, score);
		num_score += score;
	}
	student::sum_stu = sum;
	cout << "学生平均分为：" << stu[i].ava(num_score) << endl;
	return 0;
}