#include <iostream>
#include <string>
#include "fibonacci/fibonacci.h"

using fibonacci::fibonacci_numbers;


int main(int argc, char* argv[]) {
	if (argc == 1 || argc > 2) {
		std::cerr << "Usage fiboncacci <n> | fiboncacci -h | fiboncacci -v" << std::endl;
		return 1;
	}
	std::string arg(argv[1]);

    if (arg == "-v" || arg == "--version") {
        std::cout << "fiboncacci version " << FIBONACCI_VERSION << std::endl;
    } else if (arg == "-h" || arg == "--help") {
        std::cerr << "Print the first N fibonacci numbersr" << std::endl << std::endl;
        std::cerr << "Usage fiboncacci <n>" << std::endl;
    } else {
        int n = std::stoi(argv[1]);
        for (auto fib: fibonacci_numbers(n)) {
            std::cout << fib << std::endl;
        }
    }

	return 0;
}
