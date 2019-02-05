#include<iostream>
using namespace std;

void a(int &num)
{
	num++;
}
void b(int &num)
{
	num = -num;
}

int main(void)
{
	int n = 10;
	cout<<"n : "<<n<<endl;
	a(n);
	cout<<"n : "<<n<<endl;
	b(n);
	cout<<"n : "<<n<<endl;
}