#pragma once
//	include for size_t (unsigned integral type)

class IntVector {
private:
	int* fElements;
	size_t fNumberOfElements;
public:

	//	Constructor: copy argument array
	IntVector(const int aArrayOfIntegers[], size_t aNumberOfElements);

	//	Destructor: release memory
	//	Destructor is virtual to allow inheritance
	virtual ~IntVector();

	//	Size getter
	size_t size() const;

	//	Element getter
	const int get(size_t aIndex) const;

	//	Swap two elements within the vector
	void swap(size_t aSourceIndex, size_t aTargetIndex);

	//	indexer
	const int operator[](size_t aIndex) const;
};