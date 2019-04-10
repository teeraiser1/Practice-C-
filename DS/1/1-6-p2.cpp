#include<iostream>
#include<algorithm>
#include<iterator>
#include<unistd.h>

#define NUM 3

using namespace std;

void Print(char* a)
{
	for(int i = 0; i < NUM; i++)
	{
		cout<<a[i]<<' ';
	}
	cout<<endl;
}

void permutP(char* a, const int m)
{
	do{
		copy(a, a+m, ostream_iterator<char>(cout," "));
		usleep(1000000);
		cout<<endl;
	} while(prev_permutation(a, a+m));
}
void permutN(char* a, const int m)
{
	do{
		copy(a, a+m, ostream_iterator<char>(cout," "));
		usleep(1000000);
		cout<<endl;
	} while(next_permutation(a, a+m));
}


int main(void)
{
	char a[NUM] = {'a','c','b'};
	permutP(a, NUM);
	cout<<"QWER"<<endl;
	permutN(a, NUM);
}
