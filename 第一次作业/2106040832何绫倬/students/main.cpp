#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include "students.h"
int main()
{
	
	std::cout << "请输入学生数据" << std::endl;
	
	Stud st;
	Stud inf[100];
	st.writedown();
	
	st.output();
		
		return 0;
}