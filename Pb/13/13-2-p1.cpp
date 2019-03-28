#include<iostream>

using namespace std;

template <class T>
class SmartPtr
{
	private:
		T* posptr;
	public:
		SmartPtr(T *ptr) : posptr(ptr)
		{  }
		T& operator*() const
		{
			return *posptr;
		}
		T* operator->() const
		{
			return posptr;
		}
		~SmartPtr()
		{
			delete posptr;
		}
};

class Point
{
	private:
		int xpos, ypos;
	public:
		Point(int x = 0, int y = 0) : xpos(x), ypos(y)
		{  }
		void SetPoint(int x, int y)
		{
			xpos = x;
			ypos = y;
			return ;
		}
		void ShowPosition() const
		{
			cout<<xpos<<"/"<<ypos<<endl;
		}
};

class Point3D
{
	private:
		int xpos, ypos, zpos;
	public:
		Point3D(int x = 0, int y = 0, int z = 0) : xpos(x), ypos(y), zpos(z)
		{  }
		void SetPoint(int x, int y, int z)
		{
			xpos = x;
			ypos = y;
			zpos = z;
			return ;
		}
		void ShowPosition() const
		{
			cout<<xpos<<"/"<<ypos<<"/"<<zpos<<endl;
		}
};

int main(void)
{
	SmartPtr<Point> sptr1(new Point(1, 2));
	SmartPtr<Point> sptr2(new Point(3, 4));
	sptr1->ShowPosition();
	sptr2->ShowPosition();
	sptr1->SetPoint(10, 20);
	sptr2->SetPoint(30, 40);
	sptr1->ShowPosition();
	sptr2->ShowPosition();
	
	SmartPtr<Point3D> sptr13(new Point3D(1, 2, 3));
	SmartPtr<Point3D> sptr23(new Point3D(4, 5, 6));
	sptr13->ShowPosition();
	sptr23->ShowPosition();
	sptr13->SetPoint(10, 20, 30);
	sptr23->SetPoint(40, 50, 60);
	sptr13->ShowPosition();
	sptr23->ShowPosition();
}