#include<iostream>

class A
{
	private:
		int a;
	public:
		A(int a):a(a)
		{}
		void ShowA()
		{
			std::cout<<a<<std::endl;
		}
		A* operator->()
		{
			return this;
		}
};

int main(void)
{
	A qwe(10);
	qwe.ShowA();
	qwe->ShowA();
	qwe->a = 11;
	qwe.ShowA();
	
}