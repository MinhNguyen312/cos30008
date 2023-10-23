#include "Inductor.h"
#include <cmath>

//	Constructor

Inductor::Inductor(double aBaseValue) : ResistorBase(aBaseValue) {
	setBaseValue(aBaseValue);
};

bool Inductor::mustScale(double aValue) const {
	return aValue < 1.0;
}

const double Inductor::getMultiplier() const {
	return 1000.0;
}

const std::string Inductor::getMajorUnit() const {
	return "H";
}

const std::string Inductor::getMinorUnits() const {
	return "Hmunp";
}

double Inductor::getReactance(double aFrequency) const {
	return 2.0 * (4.0 * atan(1.0)) * aFrequency * getBaseValue();
}