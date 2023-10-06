#include "BernsteinBasisPolynomial.h"
#include <cmath>



BernsteinBasisPolynomial::BernsteinBasisPolynomial(unsigned int aV, unsigned int aN)
{
	Combination b(aN, aV);
	fFactor = b;
}

double BernsteinBasisPolynomial::operator()(double aX) const
{
	double result = fFactor() * pow(aX, fFactor.getK()) * pow(1 - aX, fFactor.getN() - fFactor.getK());
	return result;
}
