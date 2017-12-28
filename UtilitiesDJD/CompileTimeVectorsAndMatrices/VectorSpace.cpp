// VectorSpace.cpp


#ifndef VectorSpace_cpp
#define VectorSpace_cpp

#include "UtilitiesDJD/CompileTimeVectorsAndMatrices/VectorSpace.hpp"
#include <cmath>

// Default constructor
template<typename Type, int N>
	VectorSpace<Type, N>::VectorSpace()
{
	// Create an VectorSpace with default value
	for (int i=0; i<N; ++i) 
		arr[i]= Type();

}


template<typename Type, int N>
	VectorSpace<Type, N>::VectorSpace(const Type& value)
{
	// Create an VectorSpace with default n
	for (int i=0; i<N; ++i) 
		arr[i]= value;

}


// Copy constructor
template<typename Type, int N>
	VectorSpace<Type, N>::VectorSpace(const VectorSpace<Type, N>& source)
{
	// Deep copy source
	for (int i=0; i < N; ++i) arr[i]=source.arr[i];
}

// Destructor
template<typename Type, int N>
	VectorSpace<Type, N>::~VectorSpace()
{
}

template<typename Type, int N>
	int VectorSpace<Type, N>::Size() const
{
	return N;
}

template<typename Type, int N>
	int VectorSpace<Type, N>::MinIndex() const
{
	return 1;
}

template<typename Type, int N>
	int VectorSpace<Type, N>::MaxIndex() const
{
	return N;
}



template<typename Type, int N>
	Type VectorSpace<Type, N>::innerProduct (const VectorSpace<Type, N>& source) const
{ // Dot product

	Type result = arr[0] * source.arr[0];

	for (int i=1; i<N; ++i)
	{
		
		result += (arr[i] * source.arr[i]);

	}

	return result;
}

template<typename Type, int N>
	Type VectorSpace<Type, N>::Norm() const
{ // The l Infinity norm

	Type result = arr[0];

	for (int i=1; i<N; ++i)
	{
		result = max(arr[i], result);
	}

	return result;
}

template<typename Type, int N>
	VectorSpace<Type, N> VectorSpace<Type, N>::operator - () const
{ // The negation of a vector

	// Vectors should have same size
	VectorSpace<Type, N> result;

	for (int i= MinIndex(); i <= MaxIndex(); ++i)
	{
		result[i] = -(*this)[i];
	}

	return result;

}

// Addition
template<typename Type, int N>
	VectorSpace<Type, N> VectorSpace<Type, N>::operator + (const VectorSpace<Type, N>& v2) const
{

	// Vectors should have same size
	VectorSpace<Type, N> result;

	for (int i= v2.MinIndex(); i <= v2.MaxIndex(); ++i)
	{
		result[i] = (*this)[i] + v2[i];
	}

	return result;

}

template<typename Type, int N>
	VectorSpace<Type, N> VectorSpace<Type, N>::operator + (const Type& offset) const
{

	// Vectors should have same size
	VectorSpace<Type, N> result;

	for (int i= MinIndex(); i <= MaxIndex(); ++i)
	{
		result[i] = (*this)[i] + offset;
	}

	return result;

}

template<typename Type, int N>
	VectorSpace<Type, N> VectorSpace<Type, N>::operator - (const Type& offset) const
{

	// Vectors should have same size
	VectorSpace<Type, N> result;

	for (int i= MinIndex(); i <= MaxIndex(); ++i)
	{
		result[i] = (*this)[i] - offset;
	}

	return result;

}

template<typename Type, int N>
VectorSpace<Type, N> VectorSpace<Type, N>::operator -(const VectorSpace<Type, N>& v2) const
{

	// Vectors should have same size
	VectorSpace<Type, N> result;

	for (int i= v2.MinIndex(); i <= v2.MaxIndex(); ++i)
	{
		result[i] = (*this)[i] - v2[i];
	}

	return result;

}


// Premultiplication by a field value
template <typename Type, int N, typename F> VectorSpace<Type, N> 
				operator * (const F& scalar, const VectorSpace<Type, N>& v)
{

	VectorSpace<Type, N> result;

	for (int i= v.MinIndex(); i <= v.MaxIndex(); ++i)
	{
		
		result[i]  = (scalar * v[i]);

	}

	return result;
}



// Index operator for non const VectorSpaces
template<typename Type, int N>
	Type& VectorSpace<Type, N>::operator[](int index)
{
	return arr[index-1];
}

template<typename Type, int N>
	const Type& VectorSpace<Type, N>::operator[](int index) const
{
	return arr[index-1];
}

// Assignment operator
template<typename Type, int N>
	VectorSpace<Type, N>& VectorSpace<Type, N>::operator = (const VectorSpace<Type, N>& source)
{
	// Exit if same object
	if (this==&source) return *this;

	// Deep copy source
	for (int i=0; i<N;++i) arr[i]=source.arr[i];

	return *this;
}

// Other selector functions
template<typename Type, int N>
Type VectorSpace<Type, N>::componentProduct() const
{ // The product of all components

	Type result = arr[0];
	

	for (int i=1; i<N; ++i)
	{
		
		result *= arr[i];

	}

	return result;
	
}

#endif // VectorSpace_cpp

