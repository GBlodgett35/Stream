#include<iostream>
#include<string>
#include "Stream.cpp"


int main() {
	auto lambda = [](std::string str) {return stoi(str); };
	Stream<std::string> a{ std::vector<std::string>{"1", "2", "3"} };
	
	a.map(lambda).filter([](int e) {return e > 1; }).forEach(std::cout);
	//b.print();
	std::cin.get();
	return 0;
}