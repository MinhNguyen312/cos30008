#include "Polynomial.h"
#include <cmath>

using namespace std;

//Initialize Polynomial Object
Polynomial::Polynomial() :fDegree(0) {

	for (size_t i = 0; i < MAX_DEGREE; i++) {
		fCoeffs[i] = 0.0;
	}
}


Polynomial Polynomial::operator*(const Polynomial& aRHS) const
{
	Polynomial resultPolynomial;

	resultPolynomial.fDegree = fDegree + aRHS.fDegree;

	cout << "fDegree: " << resultPolynomial.fDegree << endl;

	for (size_t i = 0; i <= fDegree; i++) {
		for (size_t j = 0; j <= aRHS.fDegree; j++) {
			resultPolynomial.fCoeffs[i + j] += fCoeffs[i] * aRHS.fCoeffs[j];
		}
	}

	return resultPolynomial;
}

bool Polynomial::operator==(const Polynomial& aRHS) const
{
	bool result = (fDegree == aRHS.fDegree);

	for (size_t i = 0; i < fDegree; i++) {
		if (fCoeffs[i] == aRHS.fCoeffs[i]) {
			result = true;
		}
		else {
			result = false;
			break;
		}
	}

	return result;
}

double Polynomial::operator()(double aX) const
{
	double resultOfPolynomial = 0.0;
	for (int i = fDegree; i >= 0; i--) {
		resultOfPolynomial += fCoeffs[i] * pow(aX, i);
	}	

	return resultOfPolynomial;
}

Polynomial Polynomial::getDerivative() const
{

	Polynomial derivativePoly;
	
	derivativePoly.fDegree = fDegree - 1;
	
	for (int i = fDegree; i > 0;i--) {
		derivativePoly.fCoeffs[i - 1] = fCoeffs[i] * i;
	}

	return derivativePoly;
}

Polynomial Polynomial::getIndefiniteIntegral() const
{
	Polynomial indefiniteIntegralResult;
	indefiniteIntegralResult.fDegree = fDegree + 1;
	for (int i = indefiniteIntegralResult.fDegree; i > 0; i--) {
		indefiniteIntegralResult.fCoeffs[i] = (fCoeffs[i - 1] / i);
	}
	return indefiniteIntegralResult;
}

double Polynomial::getDefiniteIntegral(double aXLow, double aXHigh) const
{
	double definiteIntegral = 0.0;
	Polynomial indefiniteIntegral = getIndefiniteIntegral();
	definiteIntegral = indefiniteIntegral(aXHigh) - indefiniteIntegral(aXLow);

	return definiteIntegral;
}


std::istream& operator>>(std::istream& aIStream, Polynomial& aObject)
{
	aIStream >> aObject.fDegree;

	for (int i = aObject.fDegree; i >= 0; i--) {
		aIStream >> aObject.fCoeffs[i];
	}
	return aIStream;

}



std::ostream& operator<<(std::ostream& aOStream, const Polynomial& aObject)
{
	for (int i = aObject.fDegree; i >= 0; i--) {

		aOStream << aObject.fCoeffs[i] << "x" << "^" << i;
		if (i != 0) {
			aOStream << " + ";
		}
	}
	return aOStream;
}
