#include "Cluster.h"
#include "Point.h"

using Clustering::Point;
namespace Clustering {

	Clustering::LNode::LNode(const Point & p, LNodePtr n): point(p), next(n) {}

	void Clustering::Cluster::__del()
	{
	}

	void Clustering::Cluster::__cpy(LNodePtr pts)
	{
		__points = pts;
	}

	Clustering::Cluster::Cluster()
	{
		__size = 0;
		__points = NULL;
	}

	Clustering::Cluster::Cluster(const Cluster & c)
	{
		__points = c.__points;
		__size = c.__size;
	}

	Cluster & Clustering::Cluster::operator=(const Cluster & c1)
	{
		Cluster c2;
		c2.__points = c1.__points;
		c2.__size = c2.__size;
		// TODO: insert return statement here
		return c2;
	}

	Clustering::Cluster::~Cluster()
	{
	}

	int Clustering::Cluster::getSize() const
	{
		return __size;
	}

	void Clustering::Cluster::add(const Clustering::Point & p)
	{
		
	}

	const Clustering::Point & Clustering::Cluster::remove(const Clustering::Point &)
	{
		// TODO: insert return statement here
	}

	bool Clustering::Cluster::contains(const Clustering::Point &)
	{
		return false;
	}

	const Point & Clustering::Cluster::operator[](unsigned int index) const
	{
		// TODO: insert return statement here
	}

	Cluster & Clustering::Cluster::operator+=(const Clustering::Point &)
	{
		// TODO: insert return statement here
	}

	Cluster & Clustering::Cluster::operator-=(const Clustering::Point &)
	{
		// TODO: insert return statement here
	}

	Cluster & Clustering::Cluster::operator+=(const Cluster &)
	{
		// TODO: insert return statement here
	}

	Cluster & Clustering::Cluster::operator-=(const Cluster &)
	{
		// TODO: insert return statement here
	}

	std::ostream & Clustering::operator<<(std::ostream &, const Cluster &)
	{
		// TODO: insert return statement here
	}

	std::istream & Clustering::operator>>(std::istream &, Cluster &)
	{
		// TODO: insert return statement here
	}

	bool Clustering::operator==(const Cluster &, const Cluster &)
	{
		return false;
	}

	bool Clustering::operator!=(const Cluster &, const Cluster &)
	{
		return false;
	}

	const Cluster Clustering::operator+(const Cluster &, const Point &)
	{
		return Cluster();
	}

	const Cluster Clustering::operator-(const Cluster &, const Point &)
	{
		return Cluster();
	}

	const Cluster Clustering::operator+(const Cluster &, const Cluster &)
	{
		return Cluster();
	}

	const Cluster Clustering::operator-(const Cluster &, const Cluster &)
	{
		return Cluster();
	}
}