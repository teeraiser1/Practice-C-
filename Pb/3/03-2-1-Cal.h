#ifndef __CAL_H__
#define __CAL_H__
class Calculator
{
	private :
		unsigned opCount[4];
	public :
		void Init(void);
		double Add(double, double);
		double Min(double, double);
		double Mul(double, double);
		double Div(double, double);
		void ShowOpCount(void);
};
#endif