#include"String.h"

#include<iostream>
#include<cstring>

String::String() : str(NULL)
{  };
String::String(const char* str)
{
	this->str = new char[strlen(str+1)];
	strcpy(this->str, str);
}
String::~String()
{
	delete[] str;
}
char* String::GetString() const
{
	return str;
}
String& String::operator+(const String& ref) const
{
	char* tmp = new char[strlen(this->str)+strlen(ref.str)+1];
	strcpy(tmp, this->str);
	strcat(tmp, ref.str);
	String tmpMStr(tmp);
	delete[] tmp;
	return tmpMStr;
}
// char* String::operator+(const String& ref) const
// {
// 	char* tmp = new char[strlen(this->str)+strlen(ref.str)+1];
// 	strcpy(tmp, this->str);
// 	strcat(tmp, ref.str);
// 	return tmp;
// }
String& String::operator=(const String& ref)
{
	if(this->str != NULL)
		delete[] this->str;
	this->str = new char[strlen(ref.str)];
	strcpy(this->str, ref.str);
	return *this;
}
// String& String::operator=(const char* str)
// {
// 	if(this->str != NULL)
// 		delete[] this->str;
// 	this->str = new char[strlen(str)+1];
// 	strcpy(this->str, str);
// 	return *this;
// }
String& String::operator+=(const String& ref)
{
	char* tmpstr = new char[strlen(this->str)+strlen(ref.str)+1];
	strcpy(tmpstr, this->str);
	strcat(tmpstr, ref.str);
	if(this->str != NULL)
		delete[] this->str;
	this->str = new char[strlen(tmpstr)+1];
	strcpy(this->str, tmpstr);
	return *this;
}
bool String::operator==(const String& ref) const
{
	if(strcmp(this->str, ref.str) == 0)
		return true;
	else
		return false;
}
std::ostream& operator<<(std::ostream& os, String& str)
{
	std::cout<<str.str;
	return os;
}
std::istream& operator>>(std::istream& is, String& str)
{
	char tmpStr[100];
	std::cin>>tmpStr;
	String tmpMStr = tmpStr;
	str = tmpMStr;
	return is;
}