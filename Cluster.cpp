#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "Cluster.h"
#include "Point.h"

using namespace Clustering;
using Clustering::Point;

namespace Clustering {
	typedef Point * PointPtr;
	LNode::LNode(const Point & p, LNodePtr n) : point(p), next(n) {}

	/*void Cluster::__del()
	{
	}

	void Cluster::__cpy(LNodePtr pts)
	{

	}*/

	Cluster::Cluster()
	{
		__size = 0;
		__points = NULL;
	}

	Cluster::Cluster(const Cluster &arg_Cluster)
	{
		if (&arg_Cluster == this)
		{
			// DO NOTHING
		}
		else if (arg_Cluster.__points == NULL)
		{
			// INSTANTIATE EMPTY CLUSTER
			__size = 0;
			__points = NULL;
		}
		// ELSE DO CONSTRUCTOR
		else
		{
			__size = 0;

			// DO MEMBERWISE ASSIGNMENT
			LNodePtr cursor_oldCluster = arg_Cluster.__points;

			PointPtr newPoint;
			newPoint = new Point(arg_Cluster.__points->point);
			__points = new LNode(/*POINT, NEXT*/ *newPoint, NULL);
			++__size;

			LNodePtr cursor_newCluster = __points;
			LNodePtr prev_newCluster = cursor_newCluster;
			cursor_oldCluster = cursor_oldCluster->next;

			for (; cursor_oldCluster != NULL; cursor_oldCluster = cursor_oldCluster->next)
			{

				newPoint = new Point(cursor_oldCluster->point);
				cursor_newCluster = new LNode(/*POINT, NEXT*/ *newPoint, NULL);

				prev_newCluster->next = cursor_newCluster;

				++__size;

				prev_newCluster = cursor_newCluster;
				//				__points = arg_Cluster.__points;
			}
		}
	}

	Cluster & Cluster::operator=(const Cluster & c1)
	{
		Cluster c2;
		c2.__points = c1.__points;
		c2.__size = c2.__size;
		// TODO: insert return statement here
		return c2;
	}

	Cluster::~Cluster()
	{
		__points = NULL;
		__size = 0;
	}

	int Cluster::getSize() const
	{
		return __size;
	}

	void Cluster::add(const Clustering::Point & p) {

		PointPtr newPoint;
		newPoint = new Point(p);


		if (__points == NULL)
		{
			LNodePtr newNode;
			newNode = new LNode(*newPoint, NULL);
			__points = newNode;
			__size = 1;

		}
		else
		{
			LNodePtr Npre;
			LNodePtr cur;
			Npre = __points;
			cur = Npre->next;

			LNodePtr insertBefore = NULL;

			if (cur == NULL)
			{
				if (p < Npre->point)
					insertBefore = Npre;
				else insertBefore = cur;
			}
			else
			{
				if (p < Npre->point)
					insertBefore = Npre;

				for (; insertBefore == NULL && cur != NULL; cur = cur->next)
				{
					if (p < cur->point)
						insertBefore = cur;
					else
						Npre = cur;
				}
			}
			if (insertBefore == __points)
			{
				LNodePtr newNode;
				newNode = new LNode(*newPoint, __points);
				__points = newNode;
				++__size;
			}
			else
			{
				LNodePtr newNode;
				newNode = new LNode(*newPoint, insertBefore);
				Npre->next = newNode;
				++__size;
			}
		}
	}

	const Point &Cluster::remove(const Point &p) {
		if (contains(p)) {
			// Point is in list
			LNodePtr Nptr;
			LNodePtr Pptr = nullptr;

			Nptr = __points;

			while (Nptr != nullptr) {
				if (Nptr->point == p) {
					if (Pptr == nullptr) {
						__points = Nptr->next;
						delete Nptr;
						__size--;

						break;
					}
					else {
						Pptr->next = Nptr->next;
						delete Nptr;
						--__size;
						break;
					}
				}
				Pptr = Nptr;
				Nptr = Nptr->next;
			}
		}

		return p;
	}

	bool Cluster::contains(const Point &p) {
		LNodePtr next = __points;

		while (next != nullptr) {
			if (next->point.getId() == p.getId())
				return true;
			else
				next = next->next;
		}
		return false;
	}

	const Point & Cluster::operator[](unsigned int index) const
	{
		if (__points != NULL) {
			LNodePtr cursor = __points;

			for (int i = 0; i < index;++i) {
				cursor = cursor->next;
			}
			return cursor->point;
		}
	}

	Cluster &Cluster::operator+=(const Point &p) {
		add(p);

		return *this;
	}

	Cluster &Cluster::operator-=(const Point &p) {
		remove(p);

		return *this;
	}

	Cluster &Cluster::operator+=(const Cluster &arg_Cluster)
	{
		LNodePtr cursor_right = arg_Cluster.__points;

		for (; cursor_right != NULL; cursor_right = cursor_right->next)
		{
			if (!(this->contains(cursor_right->point)))
				add(cursor_right->point);
		}

		return *this;
	}

	Cluster &Cluster::operator-=(const Cluster &rhs) {
		for (int i = 0; i < rhs.getSize(); ++i) {
			remove(rhs[i]);
		}

		return *this;
	}

	std::ostream &operator<<(std::ostream &out, const Cluster &cluster) {
		out << std::setprecision(20);
		for (int i = 0; i < cluster.getSize(); ++i) {
			out << cluster[i] << std::endl;
			//std::cout << cluster[i] << std::endl;
		}

		return out;
	}

	std::istream &operator>>(std::istream &ins, Cluster &c)
	{
		std::string line, buffer;
		PointPtr newPoint = NULL;
		while (getline(ins, line))
		{
			int pointSize = 0;

			std::stringstream lineStream_count(line);
			std::stringstream lineStream_do(line);

			while (getline(lineStream_count, buffer, ','))
				++pointSize;

			newPoint = new Point(pointSize);
			lineStream_do >> *newPoint;
			c.add(*newPoint);

		}
		return ins;
	}

	bool operator==(const Cluster &c, const Cluster &cr)
	{
		bool Equal = true;
		LNodePtr Cleft = c.__points;
		LNodePtr Cright = cr.__points;

		while (Equal && Cleft != NULL && Cright != NULL)
		{
			if (Cleft->point != Cright->point)
			{
				Equal = false;
				continue;
			}
			else
			{
				Cleft = Cleft->next;
				Cright = Cright->next;
			}
		}
		if (Equal)
		{
			if (Cleft != NULL || Cright != NULL) Equal = false;
		}
		return Equal;
	}

	bool operator!=(const Cluster &c, const Cluster &cr)
	{
		return (!(c == cr));
	}

	const Cluster operator+(const Cluster &c, const Point &p)
	{
		Cluster newCluster(c);
		return newCluster += p;
	}

	const Cluster operator-(const Cluster &c, const Point &p)
	{
		Cluster newCluster(c);
		return newCluster -= p;
	}

	const Cluster operator+(const Cluster &c, const Cluster &cr)
	{
		Cluster newCluster(c);
		return newCluster += cr;
	}

	const Cluster operator-(const Cluster &c, const Cluster &cr)
	{
		Cluster newCluster(c);
		return newCluster -= cr;
	}
}