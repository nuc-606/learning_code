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
	cout<<"ѧ��" << Num <<' '<< "����" << Name <<' '<< "�ɼ�" << Score << endl;
}
float Stud::Ave()
{
	return Sum_S / Sum_N;
}
float Stud::Sum_N = 0;
float Stud::Sum_S = 0;
int main()
{
	Stud A[N] = { Stud(1,100,"����"),Stud(2,99,"Ǯ��"),Stud(3,98,"���")};
	for (int i = 0;i <N;i++)
	A[i].printf();
	cout << "����ѧ����ƽ����Ϊ" << A[2].Ave() << endl;
	return 0;
}