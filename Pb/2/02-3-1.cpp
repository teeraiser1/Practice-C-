#include<iostream>
using namespace std;

struct Point{
	int xpos;
	int ypos;
};

Point& pntAdder(const Point &p1, const Point &p2)
{
	Point *tmppnt = new Point;
	tmppnt->xpos = p1.xpos+p2.xpos;
	tmppnt->ypos = p1.ypos+p2.ypos;
	return *tmppnt;
}

int main(void)
{
	Point* p1 = new Point;
	Point* p2 = new Point;
	p1->xpos = p1->ypos = 1;
	p2->xpos = p2->ypos = 3;
	cout<<p1->xpos<<" "<<p1->ypos<<endl;
	cout<<p2->xpos<<" "<<p2->ypos<<endl;
	Point *tmpp = new Point;
	*tmpp = pntAdder(*p1, *p2);
	cout<<tmpp->xpos<<" "<<tmpp->ypos<<endl;
}