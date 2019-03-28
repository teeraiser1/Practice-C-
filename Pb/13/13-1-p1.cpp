#include<iostream>

using namespace std;

template <class T>
void SwapData(T& data1, T& data2)
{
	T tmp = data1;
	data1 = data2;
	data2 = tmp;
	return ;
}

class Point
{
	private:
		int xpos, ypos;
	public:
		Point(int x = 0, int y = 0) : xpos(x), ypos(y)
		{  }
		void ShowPosition() const
		{
			cout<<xpos<<"/"<<ypos<<endl;
		}
};

int main(void)
{
	Point pos0;
	Point pos1(1,1);
	pos0.ShowPosition();
	pos1.ShowPosition();
	SwapData<Point>(pos0, pos1);
	pos0.ShowPosition();
	pos1.ShowPosition();
}