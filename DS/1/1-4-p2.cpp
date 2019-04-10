#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int SumArraytoN(int a[], int n)
{
	int sum = 0;
	if(n <= 0)
		throw "QWER";
	for(int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	return sum;
}

int main(void)
{
	int a[10];
	for (int i = 0; i < 10; i++)
		a[i] = i+1;
	try
	{
		cout<<SumArraytoN(a, -1)<<endl;
	}
	catch(const char* e)
	{
		cout<<e<<endl;
	}
}