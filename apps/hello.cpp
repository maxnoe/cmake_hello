#include <iostream>
#include <string>
#include "hello/hello.hpp"


int main(int argc, char* argv[]) {
	if (argc > 2) {
		std::cerr << "Usage hello [name]" << std::endl;
		return 1;
	}

	if (argc == 1) {
		greet();
	} else {
		std::string arg(argv[1]);
		if (arg == "-v") {
			std::cout << "hello version " << HELLO_VERSION << std::endl;
		} else if (arg == "-h") {
			std::cerr << "Usage hello [name]" << std::endl;
		} else {
			greet(arg);
		}
	}

	return 0;
}
