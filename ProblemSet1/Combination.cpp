#include "Combination.h"

#include <iostream>

Combination::Combination(size_t aN, size_t aK)
{
	fN = aN;
	fK = aK;
}

size_t Combination::getN() const
{
	return fN;
}

size_t Combination::getK() const
{
	return fK;
}


unsigned long long Combination::operator() () const {
	unsigned long long result = 1;
	for (size_t i = 1; i <= getK(); i++) {
		result =result * ((double)(getN() - (i - 1)) / i);
	}
	return result;
}