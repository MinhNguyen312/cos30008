#include "DataWrapper.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

const char DataMap::getAsChar() const {
	return static_cast <const char>(fDatum);
}

DataWrapper::DataWrapper() : fSize (0), fData(nullptr)
{
}

DataWrapper::~DataWrapper() {
	delete [] fData;
}


bool DataWrapper::load(const std::string& aFileName) {
	bool flag;
	ifstream lIStream(aFileName);
	if (!lIStream) {
		cout << "Error opening input file!";
		flag = false;
	}
	else {
		lIStream >> fSize;
		if (fSize) {
			fData = new DataMap[fSize];
			for (int i = 0; i < fSize; i++) {
				lIStream >> fData[i].fIndex >> fData[i].fDatum;
			}
		}
		
		flag = true;

	}

	lIStream.close();
	return flag;
}

size_t DataWrapper::size() const
{
	return fSize;
}

const DataMap& DataWrapper::operator[](size_t aIndex) const
{
	if (aIndex < fSize) {
		return fData[aIndex];
	}
	else {
		throw out_of_range("Index Out Of Range!");
	}
}

const char DataWrapper::get(size_t aIndex, Callable aSelector) {
	return aSelector(aIndex);
}





