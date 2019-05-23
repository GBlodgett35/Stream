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
};
