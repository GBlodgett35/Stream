/*
Author: Greg Blodgett
The int specialization of the BaseStream Class
*/


#include "IntStream.h"
#include<numeric>
#include<functional>

IntStream::IntStream(const IntStream &other) : elements(other.elements){}

IntStream::IntStream(std::vector<int> const& vec) : elements(vec) {}

IntStream IntStream::operator=(IntStream const &other)
{
	return IntStream{ other.elements };
}

const int* IntStream::toArray() const {
	return &elements[0];
}

int IntStream::count() const {
	return elements.size();
}

IntStream IntStream::range(int start, int end) {
	if (start > end) {
		throw std::runtime_error("Invalid range");
	}
	std::vector<int> v(end - start); 
	std::iota(std::begin(v), std::end(v), 0);
	return IntStream{ v };
}


IntStream IntStream::filter(std::function<bool(const int&)> predicate) const
{
	std::vector<int> intStream;
	for (auto i = elements.begin(); i != elements.end(); ++i) {
		if (predicate(*i)) {
			intStream.push_back(*i);
		}
	}
	return IntStream{ intStream };
}

bool IntStream::allMatch(std::function<bool(const int&)> target) const {
	std::vector<int> newStream;
	for (auto i = elements.begin(); i != elements.end(); ++i) {
		if (!target(*i)) {
			return false;
		}
	}
	return true;
}

bool IntStream::noneMatch(std::function<bool(const int&)> target) const {
	std::vector<int> newStream;
	for (auto i = elements.begin(); i != elements.end(); ++i) {
		if (target(*i)) {
			return false;
		}
	}
	return true;
}

bool IntStream::anyMatch(std::function<bool(const int&)> target) const {
	std::vector<int> newStream;
	for (auto i = elements.begin(); i != elements.end(); ++i) {
		if (target(*i)) {
			return true;
		}
	}
	return false;
}

std::optional<int> IntStream::max() const
{
	if (!elements.empty()) {
		int _max = elements[0];
		for (auto i = elements.begin(); i != elements.end(); ++i) {
			if (*i > _max) {
				_max = *i;
			}
		}
		return std::optional<int>{_max};
	}
	return std::nullopt;
}

std::optional<int> IntStream::min() const
{
	if (!elements.empty()) {
		int _min = elements[0];
		for (auto i = elements.begin(); i != elements.end(); ++i) {
			if (*i > _min) {
				_min = *i;
			}
		}
		return std::optional<int>{_min};
	}
	return std::nullopt;
}

std::optional<int> IntStream::findFirst(std::function<bool(const int&)> predicate ) const
{
	for (auto i = elements.begin(); i != elements.end(); ++i) {
		if (predicate(*i)) {
			int copy = *i;
			return { copy };
		}
	}
	return std::nullopt;
}

void IntStream::forEach(std::function<void(const int&)> consumer) const
{
	for (auto i = elements.begin(); i != elements.end(); ++i) {
		consumer(*i);
	}
}

IntStream IntStream::of(int args...)
{
	return IntStream(std::vector<int>{args});
}
