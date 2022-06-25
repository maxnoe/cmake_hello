#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

#include "fibonacci/fibonacci.h"

using Catch::Matchers::Equals;
using fibonacci::fibonacci_numbers;
using fibonacci::numbers_t;


TEST_CASE("Fib 0") {
    auto fib = fibonacci_numbers(0);
    REQUIRE(fib.size() == 0);
}

TEST_CASE("Fib 1") {
    auto fib = fibonacci_numbers(1);
    REQUIRE_THAT(fib, Equals(numbers_t{0, }));
}

TEST_CASE("Fib 2") {
    auto fib = fibonacci_numbers(2);
    REQUIRE_THAT(fib, Equals(numbers_t{0, 1}));
}

TEST_CASE("Fib 10") {
    auto fib = fibonacci_numbers(10);
    REQUIRE_THAT(fib, Equals(numbers_t{0, 1, 1, 2, 3, 5, 8, 13, 21, 34}));
}
