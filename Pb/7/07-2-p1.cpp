#include<iostream>

using namespace std;

class Rectangle
{
	protected:
		int a, b;
	public:
		Rectangle(int a, int b) : a(a), b(b)
		{
			return ;
		}
		void ShowAreaInfo()
		{
			cout<<a*b<<endl;
			return ;
		}
};

class Square : public Rectangle
{
	private:
	public:
		Square(int r) : Rectangle(r, r)
		{
			return ;
		}
};

int main(void)
{
	Rectangle rec(4,3);
	rec.ShowAreaInfo();
	
	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}