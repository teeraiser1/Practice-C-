#include<iostream>
#include<algorithm>

void Print(int* a)
{
	for(int i = 0; i < 30; i++)
	{
		std::cout<<a[i]<<' ';
	}
	std::cout<<std::endl;
}

int main(void)
{
	int a[30];
	for(int i = 0; i < 30; i++)
	{
		std::fill(a, a+30, 5);
	}
	Print(a);
}