#include <iostream>
#include "hello/hello.hpp"

int main(int argc, char* argv[]) {
	if (argc > 2) {
		std::cerr << "Usage hello [name]" << std::endl;
		return 1;
	}

	if (argc == 1) {
		greet();
	} else {
		greet(argv[1]);
	}

	return 0;
}
