#include "ShakerSortableIntVector.h"

ShakerSortableIntVector::ShakerSortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements) : SortableIntVector(aArrayOfIntegers, aNumberOfElements) {

}



void ShakerSortableIntVector::sort(Comparable aOrderFunction) {
	for (size_t i = 0; i <= this->size() - 1; i++) {
		if (i % 2 == 0) {
			for (size_t j = 0; j < this->size() - 1; j++) {
				if (aOrderFunction(this->get(j), this->get(j + 1))) {
					this->swap(j, j + 1);
				}
			}
		}
		else {
			for (size_t k = this->size() - 1; k > 0; k--) {
				if (aOrderFunction(this->get(k-1), this->get(k))) {
					this->swap(k-1, k);
				}
			}
		}
	}
}