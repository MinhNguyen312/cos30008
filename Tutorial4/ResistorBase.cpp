#include "ResistorBase.h"

using namespace std;

void ResistorBase::setBaseValue(double aBaseValue) {
	fBaseValue = aBaseValue;
}

ResistorBase::ResistorBase(double aBaseValue)
{
	setBaseValue(aBaseValue);
}


double ResistorBase::getBaseValue() const {
	return fBaseValue;
}

// V = R * I
double ResistorBase::getPotentialAt(double aCurrent, double aFrequency) const {
	return getReactance(aFrequency) * aCurrent;
}

// I = V / R
double ResistorBase::getCurrentAt(double aVoltage, double aFrequency) const {
	return aVoltage / getReactance(aFrequency);
}

istream& operator>>(istream& aIStream, ResistorBase& aObject)
{
	double lRawValue;
	string lRawUnit;

	aIStream >> lRawValue >> lRawUnit;
	aObject.flatten(lRawValue, lRawUnit);

	return aIStream;
}

ostream& operator<<(ostream& aOStream, const ResistorBase& aObject) {
	double lNormalizeValue;
	string lNormalizeUnit;

	aObject.normalize(lNormalizeValue, lNormalizeUnit);

	aOStream << lNormalizeValue << lNormalizeUnit;

	return aOStream;
}
