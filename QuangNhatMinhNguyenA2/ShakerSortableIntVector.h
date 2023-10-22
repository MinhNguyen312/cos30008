#pragma once

#include "SortableIntVector.h"

class ShakerSortableIntVector : public SortableIntVector {
public:
	//	Constructor

	ShakerSortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements);

	//	Sort
	void sort(Comparable aOrderFunction = [] (int aLeft, int aRight) -> bool {if (aLeft <= aRight) {
        return true;
    }
    else {
        return false;
    }});
};