#include<iostream>
using namespace std;

class Point
{
	int xpos, ypos;
	public:
		void Init(int x, int y)
		{
			xpos = x;
			ypos = y;
		}
	void ShowPointInfo() const
	{
		cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
	}
};

class Circle
{
	Point myCenter;
	int myRadius;
	public:
		void Init(int xpos, int ypos, int radius)
		{
			myCenter.Init(xpos, ypos);
			myRadius = radius;
		}
		void ShowCircleInfo() const
		{
			cout<<"radius : "<<myRadius<<endl;
			myCenter.ShowPointInfo();
		}
};

class Ring
{
	Circle myInnerCircle, myOutterCircle;
	public:
		void Init(int innerXpos, int innerYpos, int innerRadius, int outterXpos, int outterYpos, int outterRadius)
		{
			myInnerCircle.Init(innerXpos, innerYpos, innerRadius);
			myOutterCircle.Init(outterXpos, outterYpos, outterRadius);
		}
		void ShowRingInfo() const
		{
			cout<<"Inner Circle Info..."<<endl;
			myInnerCircle.ShowCircleInfo();
			cout<<"Outter Circle Info..."<<endl;
			myOutterCircle.ShowCircleInfo();
		}
};


int main(void)
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}