#include<iostream>
#include<cstring>

//#define DEBUG

using namespace std;

class String
{
	private:
		char* data;
	public:
		String() : data(NULL)
		{  };
		String(const char* str)
		{
			this->data = new char[strlen(str)+1];
			strcpy(this->data, str);
		}
		String(const String& str)
		{
			cout<<"QWE"<<endl;
			this->data = new char[strlen(str.data)+1];
			cout<<"QWE"<<endl;
			strcpy(this->data, str.data);
			cout<<"QWE"<<endl;
		}
		~String()
		{
			cout<<data<<endl;
			delete[] data;
		}
	// #ifdef DEBUG
		String operator+(const String& ref) const
		{
			char* tmp = new char[strlen(this->data)+strlen(ref.data)+1];
			strcpy(tmp, this->data);
			strcat(tmp, ref.data);
			String tmpMStr(tmp);
			delete[] tmp;
			return tmpMStr;
		}
	// #else
	// 	char* operator+(const String& ref) const
	// 	{
	// 		char* tmp = new char[strlen(this->data)+strlen(ref.data)+1];
	// 		strcpy(tmp, this->data);
	// 		strcat(tmp, ref.data);
	// 		return tmp;
	// 	}
	// #endif
		String& operator=(const String& ref)
		{
			if(this->data != NULL)
				delete[] this->data;
			this->data = new char[strlen(ref.data)+1];
			strcpy(this->data, ref.data);
			return *this;
		}
		String& operator+=(const String& ref)
		{
			char* tmpstr = new char[strlen(this->data)+strlen(ref.data)+1];
			strcpy(tmpstr, this->data);
			strcat(tmpstr, ref.data);
			if(this->data != NULL)
				delete[] this->data;
			this->data = new char[strlen(tmpstr)+1];
			strcpy(this->data, tmpstr);
			return *this;
		}
		bool operator==(const String& ref) const
		{
			if(strcmp(this->data, ref.data) == 0)
				return true;
			else
				return false;
		}
		friend ostream& operator<<(ostream& os, String& str);
		friend istream& operator>>(istream& is, String& str);
}; 
ostream& operator<<(ostream& os, String& str)
{
	cout<<str.data;
	return os;
}
istream& operator>>(istream& is, String& str)
{
	char tmpStr[100];
	is>>tmpStr;
	String tmpMStr = tmpStr;
	str = tmpMStr;
	return is;
}

int main(void)
{
	String str1 = "I like ";
	String str2 = "string class";
	String str3 = str1 + str2;
	
	cout<<str1<<endl;
	cout<<str2<<endl;
	cout<<str3<<endl;
	
	// str1 += str2;
	// if(str1==str3)
	// 	cout<<"동일"<<endl;
	// else
	// 	cout<<"다름"<<endl;
	
	// String str4;
	// cin>>str4;
	// cout<<str4<<endl;
	return 0;
}