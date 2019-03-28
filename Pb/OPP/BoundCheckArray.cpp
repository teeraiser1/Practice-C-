#include"BoundCheckArray.h"

#include<iostream>
#include<cstdlib>

template <class T>
BoundCheckArray<T>::BoundCheckArray(int size) : leng(size)
{
	accounts = new T[size];
}

template <class T>
T BoundCheckArray<T>::operator[](int index) const
{
	if(index < 0 || index >= leng)
	{
		std::cout<<"잘못된 인덱스 접근"<<std::endl;
		exit(1);
	}
	return accounts[index];

}

template <class T>
T& BoundCheckArray<T>::operator[](int index)
{
	if(index < 0 || index >= leng)
	{
		std::cout<<"잘못된 인덱스 접근"<<std::endl;
		exit(1);
	}
	return accounts[index];

}

template <class T>
BoundCheckArray<T>::~BoundCheckArray()
{
	delete[] accounts;
}

