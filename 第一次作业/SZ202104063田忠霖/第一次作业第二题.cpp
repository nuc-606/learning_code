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
	while (true){
		cout << "输入记录个数: " << endl;
		try
		{
			cin >> i;
			break;
		}
		catch (const std::exception&)
		{
			cout << "输入错误重新输入 " << endl;
			continue;
		}
		
	}
    Stud stud_list[10] = {};
	int index = 0;
	while (index<i)
	{
		Stud stud;
		string id_input;
		string name_input;
		int grade;
		int flag = 0;
		while (true)
		{
			cout << "输入学号: " << endl;
			cin >> id_input;
			for (int z = 0; z < index; z++) {
				if (stud_list[z].id == id_input)
				{
					cout << "重复学号，重新输入! " << endl;
					flag = 1;
					break;
				}
				else {
					flag = 0;
				}
			}
			if (flag == 0) {
				break;
			}
		}
		cout << "输入姓名: " << endl;
		cin >> name_input;
		while (true)
		{
			try
			{
				cout << "输入成绩: " << endl;
				cin >> grade;
				if (grade<0||grade>100)
				{
					cout << "成绩输入错误: " << endl;
					continue;
				}
				break;
			}
			catch (const std::exception&)
			{
				cout << "成绩输入错误: " << endl;
				continue;
			}
		}			
		stud.StudSet(id_input, name_input, grade);
		stud_list[index] = stud;
		index++;
		cout << "是否继续(y/n): " << endl;
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

