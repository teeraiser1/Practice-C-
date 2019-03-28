#ifndef __STRING_H__
#define __STRING_H__

#include<iostream>

class String
{
	private:
		char* str;
	public:
		String();
		String(const char* str);
		~String();
		char* GetString() const;
		String& operator+(const String& ref) const;
		// char* operator+(const String& ref) const;
		String& operator=(const String& ref);
		// String& operator=(const char* str);
		String& operator+=(const String& ref);
		bool operator==(const String& ref) const;
		friend std::ostream& operator<<(std::ostream& os, String& str);
		friend std::istream& operator>>(std::istream& is, String& str);
}; 

#endif