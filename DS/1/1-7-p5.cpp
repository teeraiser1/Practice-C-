#include<iostream>
#define N 9

int main(void)
{
	int cnt = 0;
	for(int i = 0; i < N-1; i++)
	{
		cnt++;
		for(int j = i+1; j < N; j++)
		{
			cnt += 2;
		}
		cnt++;
	}
	cnt++;
	std::cout<<cnt<<" / "<<(N+2)*(N-1)+1<<std::endl;
}