#include <iostream>
#include<string>
using namespace std;
class Stud
{
public:
	string Name;
	int Id;
	int Guide;
	static double Membersum;
	static double Guidesum;

public:
	void message(int id, string name, int guide)
	{
		Name = name;
		Id = id;
		Guide = guide;
		cout << "Id:" << id << '\t' << "Name:" << name << '\t' << "Guide" << guide << endl;
	}
};
double Stud::Guidesum = 0;
double Stud::Membersum = 0;

int main()
{
	string name = " ";
	int sum = 0;
	cout << "Input the number of students." << endl;
	cin >> sum;
	Stud stu[1000];
	int i;
	int id = 0;
	int guide = 0;
	int guide_sum = 0;
	for (i = 1; i < sum; i++)
	{
		name = " ";
		id = 0;
		guide = 0;
		cout << "Input NO." << i << " student's Id ,name and guide." << endl;
		cin >> id >> name >> guide;
		stu[i].message(id, name, guide);
		guide_sum += guide;


	}
	Stud::Guidesum = guide_sum;
	Stud::Membersum = sum;
	cout << "Students' average guide is " << guide_sum / sum;
	return 0;
}
