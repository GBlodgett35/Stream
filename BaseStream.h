#pragma once
#include<optional>
/*
Author: Greg Blodgett

The pure virtual base class that all other Stream classes will extend from 
*/

template<typename T>
class BaseStream {
public:
	virtual ~BaseStream() {};
	virtual int count() const = 0;
	virtual const T* toArray() const = 0;
	virtual bool anyMatch(T) const = 0;
	virtual bool noneMatch(T) const = 0;
	virtual bool allMatch(T) const = 0;
	virtual std::optional<T> findFirst(T) const = 0;
	virtual static BaseStream<T> of(T...) const = 0;
};
