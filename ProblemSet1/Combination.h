#pragma once

#include <cstddef>

class Combination
{
private:
	size_t fN;
	size_t fK;
public:
	//	constructor for combination n over k with defaults
	Combination(size_t aN = 0, size_t aK = 0);

	//	getters
	size_t getN() const;
	size_t getK() const;

	//	call operator to calculate n over k
	unsigned long long operator() () const;
};