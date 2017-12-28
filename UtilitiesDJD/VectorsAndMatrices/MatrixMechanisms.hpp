// MatrixMechanisms.hpp
//
// Mechanism functions for matrices. We do everthing inline
// for convenience and pressure of time.


#ifndef MatrixMechanisms_hpp
#define MatrixMechanisms_hpp


#include "UtilitiesDJD/VectorsAndMatrices/NumericMatrix.cpp"
#include "UtilitiesDJD/VectorsAndMatrices/ArrayMechanisms.cpp"

////////////// Useful and Basic Print Functions ////////////////////////////////////////////////////
template <class V, class I> void print(const Matrix<V,I>& v);

#endif