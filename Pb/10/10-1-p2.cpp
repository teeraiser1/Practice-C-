#include<iostream>
using namespace std;

class Point
{
	private:
		int xpos, ypos;
	public:
		Point(int x = 0, int y = 0) : xpos(x), ypos(y)
		{  };
		void ShowPosition() const
		{
			cout<<xpos<<" / "<<ypos<<endl;
		}
		Point& operator+=(const Point &pos1)
		{
			this->xpos += pos1.xpos;
			this->ypos += pos1.ypos;
			return *this;
		}
		Point& operator-=(const Point &pos1)
		{
			this->xpos -= pos1.xpos;
			this->ypos -= pos1.ypos;
			return *this;
		}
};

int main(void)
{
	Point pos1(10,10);
	Point pos2(2,2);
	pos1 += pos2;
	pos1.ShowPosition();
	pos1 -= pos2;
	pos1.ShowPosition();
}