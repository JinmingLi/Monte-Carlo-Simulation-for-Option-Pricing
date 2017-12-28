// VectorSpace.hpp


#ifndef VectorSpace_HPP
#define VectorSpace_HPP


template<typename Type, int N> class VectorSpace
{
private:
	
	Type arr[N];

public:
	// Constructors & destructor
	VectorSpace();
	VectorSpace(const Type& value);	// All elements get this value
	VectorSpace(const VectorSpace<Type, N>& source);
	virtual ~VectorSpace();

	// Selectors
	int Size() const;
	int MinIndex() const;
	int MaxIndex() const;

	// Some properties
	Type innerProduct (const VectorSpace<Type, N>& p2) const; // Inner product
	Type Norm() const; // The l Infinity norm
	Type componentProduct() const;				// The product of all components

	// Numeric operations
	VectorSpace<Type, N> operator - () const; // The negative of a vector

	VectorSpace<Type, N> operator + (const VectorSpace<Type, N>& v2) const;
	VectorSpace<Type, N> operator - (const VectorSpace<Type, N>& v2) const;

	VectorSpace<Type, N> operator + (const Type& offset) const; // Add offset to each coord
	VectorSpace<Type, N> operator - (const Type& offset) const; // Sub offset to each coord

	// ** Template member functions ** Premultiplication by a field value
	template <typename F> VectorSpace<Type, N> 
				friend operator * (const F& scalar, const VectorSpace<Type, N>& pt);

	// Operators
	Type& operator[](int index);				// Index operator for non const VectorSpaces
	const Type& operator[](int index) const;	// Index operator for const VectorSpaces

	VectorSpace<Type, N>& operator = (const VectorSpace<Type, N>& source);

	
};

#endif // VectorSpace_hpp
