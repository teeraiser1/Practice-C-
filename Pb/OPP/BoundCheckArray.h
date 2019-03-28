#ifndef __BOUNDCHECKARRAY_H__
#define __BOUNDCHECKARRAY_H__

#include"Account.h"
#include"BankingCommonDec1.h"

template <class T>
class BoundCheckArray
{
	private:
		T* accounts;
		int leng;
	public:
		BoundCheckArray(int size = ACC_SIZE);
		T& operator[](int index);
		T operator[](int index) const;
		~BoundCheckArray();
};
#endif