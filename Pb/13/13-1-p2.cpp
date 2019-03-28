#include<iostream>

using namespace std;

template <class T>
T SumArray(T arr[], int len)
{
	T sum = 0;
	for(int i = 0; i < len; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int main(void)
{
	double a[10];
	for(int i = 0; i < 10; i++)
	{
		a[i] = i*1.1f;
	}
	cout<<SumArray(a, 10)<<endl;
}