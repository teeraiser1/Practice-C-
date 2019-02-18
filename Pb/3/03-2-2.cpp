#include<iostream>
#include<cstring>

class Printer{
	private :
		char string[20];
	public : 
		void SetString(const char* str)
		{
			if (strlen(str) >= 20)
			{
				strncpy(string, str, 19);
				string[19] = '\0';
				return ;
			}
			strncpy(string, str, strlen(str));
		}
		void ShowString(void)
		{
			std::cout<<string<<std::endl;
			return ;
		}
};

int main(void)
{
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();
	pnt.SetString("123456789012345678901234567890");
	pnt.ShowString();
}