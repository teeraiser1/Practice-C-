#include"03-2-1-Cal.h"
#include<iostream>

void Calculator::Init(void)
{
	opCount[0] = opCount[1] = opCount[2] = opCount[3] = 0;
	return ;
}
double Calculator::Add(double a, double b)
{
	opCount[0]++;
	return a+b;
}
double Calculator::Min(double a, double b)
{
	opCount[1]++;
	return a-b;
}
double Calculator::Mul(double a, double b)
{
	opCount[2]++;
	return a*b;
}
double Calculator::Div(double a, double b)
{
	opCount[3]++;
	return a/b;
}
void Calculator::ShowOpCount(void)
{
	std::cout<<"덧셈 : "<<opCount[0]<<" 뺄셈 : "<<opCount[1]<<" 곱셈 : "<<opCount[2]<<" 나눗셈 : "<<opCount[3]<<std::endl;
	return ;
}