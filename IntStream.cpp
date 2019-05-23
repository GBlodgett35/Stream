/*
Author: Greg Blodgett

The int specialization for the BaseStream class. 
*/

#include "IntStream.h"

/*
  A method to return an Array consisting of the elements of the Stream
  Returns: An int* 
*/
const int* IntStream::toArray() const {
	return &elements[0];
}

/*
  A method that returns the count of the elements in the Stream
  Returns: The size of the Stream
*/
int IntStream::count() const {
	return elements.size();
}
