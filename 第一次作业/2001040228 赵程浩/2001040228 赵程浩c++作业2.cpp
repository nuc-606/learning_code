#include<iostream>
using namespace std;
#define N 3
class Stud
{
private:
	int Num;
	int Score;
	string Name;
	static float Sum_N;
	static float Sum_S;
public:
	Stud(int num, int score, string name);
	void printf();
	static float Ave();
};
Stud::Stud(int num, int score, string name)
{
	Num = num;
	Score = score;
	Name = name;
	Sum_N++;
	Sum_S += score;
}
void Stud::printf()
{
	cout<<"学号" << Num <<' '<< "姓名" << Name <<' '<< "成绩" << Score << endl;
}
float Stud::Ave()
{
	return Sum_S / Sum_N;
}
float Stud::Sum_N = 0;
float Stud::Sum_S = 0;
int main()
{
	Stud A[N] = { Stud(1,100,"赵青"),Stud(2,99,"钱花"),Stud(3,98,"孙瓷")};
	for (int i = 0;i <N;i++)
	A[i].printf();
	cout << "本组学生的平均分为" << A[2].Ave() << endl;
	return 0;
}