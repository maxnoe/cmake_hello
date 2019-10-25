#include <iostream>
#include <string>
#include "hello/hello.hpp"


void greet() {
	greet("World");
}

void greet(std::string name) {
	std::cout << "Hello " << name << "!" << std::endl;
} 

