#include<iostream>
using namespace std;

class Point
{
	int xpos, ypos;
	public:
		Point(int x, int y)
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
		Circle(int xpos, int ypos, int radius)
			:myCenter(xpos, ypos)
		{
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
		Ring(int innerXpos, int innerYpos, int innerRadius, int outterXpos, int outterYpos, int outterRadius)
			:myInnerCircle(innerXpos, innerYpos, innerRadius), myOutterCircle(outterXpos, outterYpos, outterRadius)
		{
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
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}