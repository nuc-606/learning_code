// 2022_1_26work2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int student_sum = 0;
int grade_sum = 0;
class Stud
{
public:
	string id;
	string name;
	int grade;
	void StudSet(string id_input, string name_input , int grade_input);
	void StuPrint();
	void SumPrint();
};

void Stud::SumPrint() {
	cout << "总人数:" << student_sum << " 总分:" << grade_sum << " 平均成绩:" << double(grade_sum)/ double(student_sum) << endl;
}
void Stud::StuPrint() {
	cout << "学号:" << id << " 姓名:" << name << " 成绩:" << grade <<endl;
}
void Stud::StudSet(string id_input, string name_input, int grade_input)
{
	id = id_input;
	name = name_input;
	grade = grade_input;
	student_sum += 1;
	grade_sum += grade_input;

	cout << "Structure success!" << endl;
}
int main()
{
	int i;
	cout << "输入记录个数: " << endl;
	cin >> i;
    Stud stud_list[10] = {};
	int index = 0;
	while (index<i)
	{
		Stud stud;
		string id_input;
		string name_input;
		int grade;
		cout << "输入学号: " << endl;
		cin >> id_input;
		cout << "输入姓名: " << endl;
		cin >> name_input;
		cout << "输入成绩: " << endl;
		cin >> grade;
		stud.StudSet(id_input, name_input, grade);
		stud_list[index] = stud;
		cout << "是否继续(y/n): " << endl;
		index++;
		char order;
		cin >> order;
		if (order != 'y') {
			break;
		}
	}
	for (i = 0; i < index; i++) {
		stud_list[i].StuPrint();
	}
	stud_list[index].SumPrint();
	return 0;
}

