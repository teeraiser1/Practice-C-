#include<iostream>

int Hanoi(int height)
{
	if(height == 1)
		return 1;
	return 2*Hanoi(height-1)+1;
}

int main(void)
{
	std::cout<<Hanoi(7)<<std::endl;
}