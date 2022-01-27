#include "iostream"

using namespace std;

class Stud
{
public:
	int num, score;
	char name[200] = "\0";
	static int grade;
	static int n;
	void Input();
	void Output();
	void static Average();
};
int Stud::grade = 0;
int Stud::n = 0;

void Stud::Input()
{
	cout << "请输入学生学号、姓名、成绩：" << endl;
	cin >> num >> name >> score;
}

void Stud::Output()
{
	cout << num << endl << name << endl << score << endl;
}

void Stud::Average()
{
	cout << grade / n << endl;
}
