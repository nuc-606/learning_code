#include <iostream>
#include "person.h"
int main()
{
		Person();
		{
			std::string str = "Ð¡ºì";
			Person per(&str, 19, "female");

			Person per1 = per;

			std::cout << per1.name << std::endl;
		}
		
	
	
	
	return 0;
}