/*
Author: Greg Blodgett

The int specialization of the BaseStream Class
*/

#pragma once
#include "BaseStream.h" 
#include<vector>
#include<functional>
#include<optional>

class IntStream : public BaseStream<int> {
public:
	IntStream(std::vector<int> const&);
	IntStream operator = (IntStream const&);
	const int* toArray() const;
	int count() const;
	static IntStream range(int, int);
	IntStream filter(std::function<bool(const int&)>) const;
	bool noneMatch(int) const;
	bool anyMatch(int) const;
	bool allMatch(int) const;
	std::optional<int> max() const;
	std::optional<int> min() const;
	std::optional<int> findFirst(int) const;
private:
	const std::vector<int> elements;
};
