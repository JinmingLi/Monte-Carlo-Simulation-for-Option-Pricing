// ArrayMechanisms.cpp


#ifndef ArrayMechanisms_cpp
#define ArrayMechanisms_cpp

#include "UtilitiesDJD/VectorsAndMatrices/ArrayMechanisms.hpp"

#include <iostream>
using namespace std;


////////////////////// Print Functions /////////////////////////////////////////
template <typename V, typename I> void print(const Array<V,I>& v)
{

	cout << "\n\nMinIndex: " << v.MinIndex() << " , MaxIndex: " << v.MaxIndex() << endl;

	cout << "\nARR:[";
	for (I j = v.MinIndex(); j <= v.MaxIndex(); ++j)
	{
		cout << v[j] << ", ";
	
	}

	cout << "]";
}

template <typename V, typename I> void print(const Vector<V,I>& v)
{

	cout << "\n\nMinIndex: " << v.MinIndex() << " , MaxIndex: " << v.MaxIndex() << endl;

	cout << "\nARR:[";
	for (I j = v.MinIndex(); j <= v.MaxIndex(); ++j)
	{
		cout << v[j] << ", ";
	
	}

	cout << "]";
}


#endif