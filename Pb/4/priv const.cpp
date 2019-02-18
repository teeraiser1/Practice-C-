#include<iostream>
class AAA
{
	private:
		int num;
	public:
		AAA() : num(0){}
		AAA& CreateInitObj(int n) const
		{
			AAA *ptr = new AAA(n);
			return *ptr;
		}
	void ShowNum() const{std::cout<<num<<std::endl;}
	private:
		AAA(int n) : num(n){}
};

int main()
{
	AAA base;
	base.ShowNum();
}