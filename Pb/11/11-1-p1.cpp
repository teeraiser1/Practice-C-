#include<iostream>

class Gun
{
	public:
		int A;
	public:
		Gun(int a) : A(a)
		{  };
		Gun(const Gun& gun2) : A(gun2.A)
		{  };
		Gun& operator=(Gun gun2)
		{
			A = gun2.A;
			return *this;
		}
};
class Police
{
	public:
		int H;
		Gun *pistol;
	public:
		Police(int b, int h) : H(h)
		{
			if(b>0)
				pistol = new Gun(b);
			else
				pistol = NULL;
		};
		Police& operator=(Police pol2)
		{
			this->H = pol2.H;
			this->pistol = pol2.pistol;
			return *this;
		}
};

int main(void)
{
	Police pol1(5, 10);
	Police pol2(3, 8);
	std::cout<<pol1.pistol->A<<std::endl;
	std::cout<<pol2.pistol->A<<std::endl;
	pol1 = pol2;
	std::cout<<pol1.pistol->A<<std::endl;
	std::cout<<pol2.pistol->A<<std::endl;
}