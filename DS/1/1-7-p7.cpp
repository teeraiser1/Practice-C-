#include<iostream>
#define M 37
#define P 12
#define N 1

int main(void)
{
	int cnt = 0;
	
	for(int i = 0; i < M; i++)
	{
		cnt++;
		
		for(int j = 0; j < P; j++)
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
	
	int tmpint = 2*M*P*N+3*M*P+2*M+1;
	std::cout<<cnt<<" / "<<tmpint<<std::endl;
	tmpint==cnt?std::cout<<"true":std::cout<<"false";
}