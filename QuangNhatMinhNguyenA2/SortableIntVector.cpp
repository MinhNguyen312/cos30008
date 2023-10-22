#include "SortableIntVector.h"

SortableIntVector::SortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements) : IntVector(aArrayOfIntegers,aNumberOfElements) {

}


void SortableIntVector::sort(Comparable aOrderFunction) {
	for (size_t i = 0; i <= this->size() - 1; i++) {
		for (size_t j = 0; j <= this->size()-2; j++) {
			if (aOrderFunction(this->get(j), this->get(j + 1)) == false) {
				this->swap(j, j + 1);
			}
		}
	}
}