#include<iostream>
static 

int HornersMethod(int a[], int x, int i, int n)
{	
	if(i == n-1)
	{
		return a[n]*x + a[n-1];
	}
	return (HornersMethod(a,x, i+1, n))*x + a[i];
}

int main(void)
{
	
}