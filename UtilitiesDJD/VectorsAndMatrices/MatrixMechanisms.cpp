// MatrixMechanisms.cpp
//
// Mechanism functions for matrices. 


#ifndef MatrixMechanisms_cpp
#define MatrixMechanisms_cpp


#include "UtilitiesDJD/VectorsAndMatrices/MatrixMechanisms.hpp"
////////////// Useful and Basic Print Functions ////////////////////////////////////////////////////
template <class V, class I> void print(const Matrix<V,I>& mat)
{


	for (int i = mat.MinRowIndex(); i <= mat.MaxRowIndex(); i++)
	{
	
		cout << "\n[";
		for (I j = mat.MinColumnIndex(); j <= mat.MaxColumnIndex()-1; j++)
		{
			cout << mat(i,j) << ", ";
		}
		cout << mat(i, mat.MaxColumnIndex());
		cout << "]" << endl;
	
	}
	cout << endl;
}

#endif