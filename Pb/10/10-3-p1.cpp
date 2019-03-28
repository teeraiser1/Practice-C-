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
		friend istream& operator>>(const istream is, const Point& pos);
};

ostream& operator<<(ostream& os, Point& pos)
{
	pos.ShowPosition();
	return os;
}
istream& operator>>(istream& is, Point& pos)
{
	int x, y;
	std::cin>>x>>y;
	Point tmppos(x, y);
	pos = tmppos;
	return is;
}

int main(void)
{
	Point pos1;
	cin>>pos1;
	cout<<pos1;
	
}