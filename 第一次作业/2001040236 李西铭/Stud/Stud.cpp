#define N 6

#include "Stud.h"

int main()
{
	Stud p[N];
	for (int i = 1; i <= N-1; i++)
	{
		p[i].Input();
		p[i].grade += p[i].score;
		p[i].n ++;
	}
	for (int j = 1; j <= N-1; j++)
	{
		p[j].Output();
		if (j == N-1)
			p[j].Average();
	}
}
