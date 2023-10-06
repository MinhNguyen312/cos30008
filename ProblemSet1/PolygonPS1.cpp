#include "Polygon.h"
#include <stdexcept>


using namespace std;

Polygon::Polygon() : fNumberOfVertices(0) {}


size_t Polygon::getNumberOfVertices() const {
	return fNumberOfVertices;
}

const Vector2D& Polygon::getVertex(size_t aIndex) const {
	if (aIndex < MAX_VERTICES) {
		return fVertices[aIndex];
	}
	else {
		throw out_of_range("Index out of range!!");
	}
}

void Polygon::readData(std::istream& aIStream)
{
	while (aIStream >> fVertices[fNumberOfVertices]) {
		fNumberOfVertices++;
	}
}

float Polygon::getPerimeter() const
{
	float perimeter = 0.0f;
	Vector2D segment;

	for (int i = 0; i < fNumberOfVertices; i++) {
		if (i + 1 == fNumberOfVertices) {
			segment = getVertex(i) - getVertex(0);
		}
		else {
			segment = getVertex(i) - getVertex(i + 1);
		}
		perimeter += segment.length();
	}

	return perimeter;
}

Polygon Polygon::scale(float aScalar) const
{
	Polygon Result = *this;

	for (int i = 0; i < fNumberOfVertices; i++) {
		Result.fVertices[i] = fVertices[i] * aScalar;
	}
	return Result;
}

float Polygon::getSignedArea() const {
	float signedResult = 0.0f;

	for (int i = 0; i < fNumberOfVertices; i++) {

		if (i == fNumberOfVertices - 1) {
			signedResult += (getVertex(i).getX() * getVertex(0).getY()) - (getVertex(i).getY() * getVertex(0).getX());
		}
		else {
			signedResult += (getVertex(i).getX() * getVertex(i + 1).getY()) - (getVertex(i).getY() * getVertex(i + 1).getX());
		}
	}

	signedResult = signedResult * 1 / 2;
	

	return signedResult;
	
}










