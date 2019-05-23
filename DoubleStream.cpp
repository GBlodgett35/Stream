/*
Author: Greg Blodgett

The implementation of the DoubleStream class
*/

#include "DoubleStream.h"

DoubleStream::DoubleStream(std::vector<double> e) : elements(e){}

DoubleStream DoubleStream::operator=(const DoubleStream &other)
{
	return DoubleStream(other.elements);
}

DoubleStream::DoubleStream(const DoubleStream &other) : elements(other.elements ){}

int DoubleStream::count() const
{
	return elements.size();
}

const double * DoubleStream::toArray() const
{
	return &elements[0];
}

bool DoubleStream::anyMatch(std::function<bool(const double&)> predicate) const
{
	for (auto i = elements.begin(); i != elements.end(); ++i) {
		if (predicate(*i)) {
			return true;
		}
	}
	return false;
}

bool DoubleStream::noneMatch(std::function<bool(const double&)> predicate) const
{
	for (auto i = elements.begin(); i != elements.end(); ++i) {
		if (predicate(*i)) {
			return false;
		}
	}
	return true;
}

bool DoubleStream::allMatch(std::function<bool(const double&)> predicate) const
{
	for (auto i = elements.begin(); i != elements.end(); ++i) {
		if (!predicate(*i)) {
			return false;
		}
	}
	return true;
}

std::optional<double> DoubleStream::findFirst(std::function<bool(const double&)> predicate) const
{
	for (auto i = elements.begin(); i != elements.end(); ++i) {
		if (predicate(*i)) {
			double copy = *i;
			return {copy};
		}
	}
	return std::nullopt;
}
DoubleStream DoubleStream::of(double args...)
{
	return DoubleStream(std::vector<double>{args});
}

void DoubleStream::forEach(std::function<void(const double&)> consumer) const
{
	for (auto i = elements.begin(); i != elements.end(); ++i) {
		consumer(*i);
	}
}
