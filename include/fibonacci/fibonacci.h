#ifndef FIBONACCI_FIBONACCI_HPP
#define FIBONACCI_FIBONACCI_HPP
#include <vector>
#include "fibonacci/version.h"

namespace fibonacci {
    using numbers_t = std::vector<unsigned long>;
    numbers_t fibonacci_numbers(unsigned int n);
}

#endif
