/*
Author: Greg Blodgett

The int specialization of the BaseStream Class
*/

#pragma once
#include "BaseStream.h" 
#include<vector>

class IntStream : BaseStream<int> {
	const int* toArray() const;
	int count() const;
private:
	const std::vector<int> elements;
};
