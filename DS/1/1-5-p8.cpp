#include<iostream>
static int cnt;
int CalculateCombination(int n, int m)
{
	cnt++;
	if (n == m)
		return 1;
	else if(m == 0)
		return 1;
	return CalculateCombination(n-1, m) + CalculateCombination(n-1, m-1);
}


int main(void)
{
	cnt = 0;
	std::cout<<CalculateCombination(10,2)<<std::endl;
	std::cout<<cnt<<std::endl;
}