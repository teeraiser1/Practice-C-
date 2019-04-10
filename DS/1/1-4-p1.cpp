#include<iostream>

using namespace std;

int DivZero(int a, int b, int c)
{
	if (a<0 && b<0 && c< 0)
		throw 1;
	else if(a==0 && b==0 && c==0)
		throw 2;
	return a+b*c+b/c;
}

int main(void)
{
	try
	{
		cout<<DivZero(-1,-1,-1)<<endl;
	}
	catch(int e)
	{
		switch(e)
		{
			case 1:
				cout<<"<0"<<endl;
				break;
			case 2:
				cout<<"==0"<<endl;
				break;
			default:
				;
		}
	}
}