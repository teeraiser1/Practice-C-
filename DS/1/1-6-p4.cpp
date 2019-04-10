#include<iostream>
#include<algorithm>

int main(void)
{
	int a[30];
	for(int i = 0; i < 30; i++)
	{
		a[i] = i%5;
	}
	std::cout<<std::count(a, a+30, a[0]);
}