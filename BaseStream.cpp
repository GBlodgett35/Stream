#include<iostream>
#include<functional>
#include<vector>

template<typename T>
class BaseStream {
public:
	virtual ~BaseStream() {};
	virtual int count() const = 0;
	virtual const T* toArray() const = 0;
};