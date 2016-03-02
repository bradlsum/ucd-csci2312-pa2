#include "Point.h"

using _CMATH_::sqrt;

namespace Clustering {

	unsigned int Point::__idGen = 0;

	// Constructor
	Clustering::Point::Point(int dim)
	{
		__id = __idGen;
		__idGen++;
		__dim = dim;

		__values = new double[__dim];

		for (int i = 0; i < __dim;++i) {
			__values[i] = 0.0;
		}
	}

	// Two varriable constructor
	Clustering::Point::Point(int dim, double * values)
	{
		__id = __idGen;
		__idGen++;
		__dim = dim;
		__values = values;
	}

	// Copy constructor
	Clustering::Point::Point(const Point & npoint)
	{
		__dim = npoint.getDims();
		__id = npoint.getId();
		__values = new double[npoint.getDims()];

		for (int i = 0; i < npoint.getDims();++i) setValue(i, npoint.getValue(i));
	}

	// Assignment operator
	Point & Clustering::Point::operator=(const Point & npoint)
	{
		for (int i = 0; i < __dim;++i) {
			this->__values[i] = npoint.getValue(i);
		}
		return *this;
	}

	// Destructor
	Clustering::Point::~Point() {
		if (__values != NULL)
	{
		delete[] __values;
	}
		__values = NULL;

	}

	// Accessors & mutators
	int Clustering::Point::getId() const
	{
		return __id;
	}

	int Clustering::Point::getDims() const
	{
		return __dim;
	}

	void Clustering::Point::setValue(int i, double v)
	{
		__values[i] = v;
	}

	double Clustering::Point::getValue(int i) const
	{
		return __values[i];
	}

	// Functions
	double Clustering::Point::distanceTo(const Point & point) const
	{
		double distance = 0;

		for (int i = 0; i < __dim;++i) {
			distance += (__values[i] - point.__values[i]) * (__values[i] - point.__values[i]);

		}

		return sqrt(distance);
	}

	// Members
	Point & Clustering::Point::operator*=(double x)
	{
		for (int i = 0; i < __dim;++i) {

			__values[i] *= x;
		}

		// TODO: insert return statement here
		return *this;
	}

	Point & Clustering::Point::operator/=(double x)
	{
		for (int i = 0; i < __dim;++i) {
			__values[i] = __values[i] / x;
		}
		// TODO: insert return statement here
		return *this;
	}

	const Point Clustering::Point::operator*(double x) const
	{
		for (int i = 0; i < __dim;++i) {
			__values[i] = __values[i] * x;
		}
		return *this;
	}

	const Point Clustering::Point::operator/(double x) const
	{
		for (int i = 0; i < __dim;++i) {
			__values[i] = __values[i] / x;
		}
		return *this;
	}

	double & Clustering::Point::operator[](int index)
	{
		// TODO: insert return statement here
		return __values[index];
	}

	Point &operator+=(Point &arg_Point_left, const Point &arg_Point_right)
	{
		if (arg_Point_left.__dim == arg_Point_right.__dim)
		for (int index = 0; index < arg_Point_left.__dim; ++index)
		arg_Point_left.__values[index] += arg_Point_right.__values[index];

		return arg_Point_left;
	}


	Point &operator-=(Point &arg_Point_left, const Point &arg_Point_right)
	{
		if (arg_Point_left.__dim == arg_Point_right.__dim)
		for (int index = 0; index < arg_Point_left.__dim; ++index)
		arg_Point_left.__values[index] -= arg_Point_right.__values[index];

		return arg_Point_left;
	}


	const Point operator+(const Point & p1, const Point & p2)
	{
		Point p0(p1.getDims());

		if (p1.getDims() == p2.getDims()) {
			for (int i = 0; i < p1.getDims();++i) {
				p0.__values[i] = p1.__values[i] + p2.__values[i];
			}
		}

		return p0;
	}

	const Point operator-(const Point & p1, const Point & p2)
	{
		Point p0(p1.getDims());

		if (p1.getDims() == p2.getDims()) {
			for (int i = 0; i < p1.getDims();++i) {
				p0.__values[i] = p1.__values[i] - p2.__values[i];
			}
		}

		return p0;
	}

	bool operator==(const Point & p1, const Point & p2)
	{
		if (p1.__id != p2.__id) return false;
		if (p1.__dim == p2.__dim) {
			for (int i = 0; i < p1.__dim;++i) {
				if (p1.__values[i] != p2.__values[i]) return false;
			}
			return true;
		}
		return false;
	}

	bool operator!=(const Point & p1, const Point & p2)
	{
		if (p1.__id != p2.__id) return true;
		if (p1.__dim == p2.__dim) {
			for (int i = 0; i < p1.__dim;++i) {
				if (p1.__values[i] != p2.__values[i]) return true;
			}
			return false;
		}
		return true;
	}

	bool operator<(const Point & p1, const Point & p2)
	{
		if (p1.__dim == p2.__dim) {
			for (int i = 0; i < p1.__dim;++i) {
				if (p1.__values[i] < p2.__values[i]) return true;
			}
		}
		return false;
	}

	bool operator>(const Point & p1, const Point & p2)
	{
		if (p1.__dim == p2.__dim) {
			for (int i = 0; i < p1.__dim;++i) {
				if (p1.__values[i] > p2.__values[i]) return true;
			}
		}
		return false;
	}

	bool operator<=(const Point & p1, const Point & p2)
	{
		if (p1.__dim == p2.__dim) {
			for (int i = 0; i < p1.__dim;++i) {
				if (p1.__values[i] <= p2.__values[i]) return true;
			}
		}
		return false;
	}

	bool operator>=(const Point & p1, const Point & p2)
	{
		if (p1.__dim == p2.__dim) {
			for (int i = 0; i < p1.__dim;++i) {
				if (p1.__values[i] >= p2.__values[i]) return true;
			}
		}
		return false;
	}

	std::ostream & operator<<(std::ostream & os, const Point & p1)
	{
		for (int i = 0; i < p1.__dim;++i) {
			os << p1.__values[i] << ", ";
		}
		os << std::endl;
		// TODO: insert return statement here
		return os;
	}

	std::istream & operator>>(std::istream & os, Point & p1)
	{
		int i = 0;
		while (os) {
			if (os.peek() == ' ') os.ignore();
			if (os.peek() == ',') os.ignore();
			os >> p1.__values[i];
			++i;
		}
		// TODO: insert return statement here
		return os;
	}
}
