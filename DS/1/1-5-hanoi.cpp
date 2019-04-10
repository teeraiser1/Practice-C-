#include<iostream>
#include<unistd.h>

#define MAX_HEIGHT 32
#define HANOI_TARGET_HEIGHT 5
#define NO_ELEMENT -1
#define WAITING_TIME 1000000

namespace SticksNumber
{
	enum {first, second, third};
}

using namespace std;

class Stack
{
	private: 
		int data[MAX_HEIGHT];
		int top;
	public:
		Stack():top(NO_ELEMENT)
		{  }
		int Pop()
		{
			if(top <= NO_ELEMENT)
				throw "There's no element. Cannot Pop";
			int inttmp = data[top];
			data[top--] = 0;
			return inttmp;
		}
		void Push(int n)
		{
			if(++top == MAX_HEIGHT)
				throw "Stack is full. Cannot Push";
			data[top] = n;
		}
		void ShowData(int leng)
		{
			for(int i = 0; i < leng; i++)
			{
				if(data[i] == 0)
					break;
				cout<<data[i]<<' ';
			}
			cout<<endl;
		}
		void SetTop(int n)
		{
			top = n;
		}
};


class Hanoi
{
	private:
		Stack stack[3];
		int cnt;
	public:
		Hanoi(int height) : cnt(0)
		{
			try
			{
				for(int i = 0; i < height; i++)
				{
					stack[0].Push(height-i);
				}
				for(int i = height; i < MAX_HEIGHT; i++)
				{
					stack[0].Push(0);
				}
				for(int i = 0; i < MAX_HEIGHT; i++)
				{
					stack[1].Push(0);
					stack[2].Push(0);
				}
				stack[0].SetTop(height-1);
				stack[1].SetTop(NO_ELEMENT);
				stack[2].SetTop(NO_ELEMENT);
			}
			catch(const char* e)
			{
				cout<<e<<endl;
			}
		}
		void Play(int from, int to, int els, int height)
		{
			if(height == 1)
			{
				try
				{
					cnt++;
					stack[to].Push(stack[from].Pop());
					this->ShowTower();
					return ;
				}
				catch(const char* e)
				{
					cout<<e<<endl;
				}
			}
			Play(from,els,to,height-1);
			Play(from,to,els,1);
			Play(els,to,from,height-1);
		}
		void ShowTower()
		{
			cout<<"n = "<<cnt<<endl;
			stack[0].ShowData(HANOI_TARGET_HEIGHT);
			stack[1].ShowData(HANOI_TARGET_HEIGHT);
			stack[2].ShowData(HANOI_TARGET_HEIGHT);
			cout<<"---------------------------------------------------------------"<<endl;
			usleep(WAITING_TIME);
		}
	
};

int main(void)
{
	Hanoi hanoi(HANOI_TARGET_HEIGHT);
	hanoi.ShowTower();
	hanoi.Play(SticksNumber::first, SticksNumber::second, SticksNumber::third, HANOI_TARGET_HEIGHT);
}