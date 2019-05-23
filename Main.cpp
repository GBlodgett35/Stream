/*
Author: Greg Blodgett

An example usage of the classes
*/

#include<iostream>
#include<string>
#include "Stream.cpp"
#include "IntStream.h"


int main() {
	auto lambda = [](std::string str) {return stoi(str); };
	Stream<std::string> a{ std::vector<std::string>{"1", "2", "3"} };
	int size = IntStream::range(0, 5).count();
	std::string str = a.map([](std::string s) {return s + " "; }).findFirst("2 ").value_or("");
	int x = Stream<std::string>::of("1", "2", "3", "4").mapToInt([](std::string str) {return stoi(str); }).max().value_or(-1);



	std::cin.get();
	return 0;
}
