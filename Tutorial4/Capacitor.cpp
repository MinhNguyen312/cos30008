#include "Capacitor.h"
#include <cmath>

using namespace std;
//	Constructor
Capacitor::Capacitor(double aBaseValue) : ResistorBase(aBaseValue) {
}


bool Capacitor::mustScale(double aValue) const {
	return aValue < 1.0;
}

const double Capacitor::getMultiplier() const {
	return 1000.0;
}

const string Capacitor::getMajorUnit() const {
	return "F";
}

// "OkM", the first letter means "no minor unit"
const string Capacitor::getMinorUnits() const
{
	return "Fmunp";
}


double Capacitor::getReactance(double aFrequency) const {
	return 1 / (2.0 * (4.0 *atan(1.0)) * aFrequency * getBaseValue());
}

