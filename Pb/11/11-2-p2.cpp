#include<iostream>
#include<vector>


class IntArray
{
	private:
		int* pos1DArray;
	public:
		IntArray(int width)
		{ 
			pos1DArray = new int[width];
		}
		int& operator[](int index)
		{
			return pos1DArray[index];
		}
		~IntArray()
		{
			delete []pos1DArray;
		}
};

class Int2DArray
{
	private:
		IntArray** pos2DArray;
	public:
		Int2DArray(int height, int width)
		{
			pos2DArray = new IntArray*[height];
			for(int i = 0; i < height; i++)
			{
				pos2DArray[i] = new IntArray(width);
			}
		}
		IntArray& operator[](int index)
		{
			return *pos2DArray[index];
		}
		~Int2DArray()
		{
			delete []pos2DArray;
		}
};

int main(void)
{
	Int2DArray posArray(3, 4);
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			posArray[i][j] = i*10+j;
		}
	}
	std::cout<<posArray[0][3];
}