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
		bool operator==(const Point &pos1)
		{
			if(this->xpos == pos1.xpos && this->ypos == pos1.ypos)
				return true;
			return false;
		}
		bool operator!=(const Point &pos1)
		{
			if(this->xpos != pos1.xpos || this->ypos != pos1.ypos)
				return true;
			return false;
		}
};

int main(void)
{
	Point pos1(10,10);
	Point pos3(10,10);
	Point pos2(2,2);
	if (pos1 == pos3)
		cout<<"ASD"<<endl;
	if (pos1 != pos3)
		cout<<"QWE"<<endl;
}