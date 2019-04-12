#include<iostream>
#define N 10

int main(void)
{
	int cnt = 0;
	
	for(int i = 0; i < N; i++)
	{
		cnt++;
		for(int j = 0; j < N; j++)
		{
			cnt++;
			cnt++;
			for(int k = 0; k < N; k++)
			{
				cnt++;
				cnt++;
			}
			cnt++;
		}
		cnt++;
	}
	cnt++;
	
	std::cout<<cnt<<" / "<<2*N*N*N+3*N*N+2*N+1<<std::endl;
}