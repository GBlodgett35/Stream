/*
Author: Greg Blodgett

The header file for the DoubleStream class
*/

#pragma once
#include "BaseStream.h"
#include<vector>

class DoubleStream : public BaseStream<double> {
public:
	DoubleStream(std::vector<double>);
	DoubleStream operator=(const DoubleStream&);
	DoubleStream(const DoubleStream& );
	int count() const;
	const double* toArray() const;
	bool anyMatch(std::function<bool(const double&)>) const;
	bool noneMatch(std::function<bool(const double&)>) const;
	bool allMatch(std::function<bool(const double&)>) const;
	std::optional<double> findFirst(std::function<bool(const double&)>) const;
	void forEach(std::function<void(const double&)>) const;
	static DoubleStream of(double args...);

private: 
	std::vector<double> elements;
};
