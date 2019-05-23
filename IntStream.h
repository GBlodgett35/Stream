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
	IntStream(const IntStream&);
	const int* toArray() const;
	int count() const;
	static IntStream range(int, int);
	IntStream filter(std::function<bool(const int&)>) const;
	bool noneMatch(std::function<bool(const int&)>) const;
	bool anyMatch(std::function<bool(const int&)>) const;
	bool allMatch(std::function<bool(const int&)>) const;
	std::optional<int> max() const;
	std::optional<int> min() const;
	std::optional<int> findFirst(std::function<bool(const int&)>) const;
	void forEach(std::function<void(const int&)>) const;
	static IntStream of(int args...);
private:
	const std::vector<int> elements;
};
