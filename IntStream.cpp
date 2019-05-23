/*
Author: Greg Blodgett

The int specialization for the BaseStream class. 
*/

#include "IntStream.h"
#include<numeric>
#include<functional>

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

bool IntStream::allMatch(int target) const {
	std::vector<int> newStream;
	for (auto i = elements.begin(); i != elements.end(); ++i) {
		if (*i != target) {
			return false;
		}
	}
	return true;
}

bool IntStream::noneMatch(int target) const {
	std::vector<int> newStream;
	for (auto i = elements.begin(); i != elements.end(); ++i) {
		if (*i == target) {
			return false;
		}
	}
	return true;
}

bool IntStream::anyMatch(int target) const {
	std::vector<int> newStream;
	for (auto i = elements.begin(); i != elements.end(); ++i) {
		if (*i == target) {
			return true;
		}
	}
	return false;
}
