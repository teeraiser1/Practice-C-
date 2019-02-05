#include<iostream>

int main(void)
{
	const int num = 12;
	const int *ptr = &num;
	const int* &pref = ptr;
	
	std::cout<<num<<std::endl;
	std::cout<<*ptr<<std::endl;
	std::cout<<*pref<<std::endl;
	
}