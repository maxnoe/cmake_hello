#include <vector>
#include "fibonacci/fibonacci.h"

std::vector<unsigned long> fibonacci_numbers(unsigned int n) {
    std::vector<unsigned long> numbers;
    numbers.reserve(n);

    if (n == 0) return numbers;

    numbers.push_back(1);

    if (n == 1) return numbers;

    numbers.push_back(1);

    if (n == 2) return numbers;

    for (unsigned int i = 2; i < n; i++) {
        numbers.push_back(numbers[i - 2] + numbers[i - 1]);
    }

    return numbers;
}
