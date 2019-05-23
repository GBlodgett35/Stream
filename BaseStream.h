#pragma once
#include<optional>
#include<functional>
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
	virtual bool anyMatch(std::function<bool(const T&)>) const = 0;
	virtual bool noneMatch(std::function<bool(const T&)>) const = 0;
	virtual bool allMatch(std::function<bool(const T&)>) const = 0;
	virtual std::optional<T> findFirst(std::function<bool(const T&)>) const = 0;
	virtual void forEach(std::function<void(const T&)>) const = 0;
	
};
