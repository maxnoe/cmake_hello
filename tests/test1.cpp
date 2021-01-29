#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "fibonacci/fibonacci.h"

using testing::ElementsAre;

TEST(Fibonacci, Test0) {
    auto fib = fibonacci_numbers(0);
    ASSERT_EQ(0, fib.size());
}

TEST(Fibonacci, Test1) {
    auto fib = fibonacci_numbers(1);
    ASSERT_THAT(fib, ElementsAre(1));
}

TEST(Fibonacci, Test2) {
    auto fib = fibonacci_numbers(2);
    ASSERT_THAT(fib, ElementsAre(1, 1));
}


TEST(Fibonacci, Test10) {
    auto fib = fibonacci_numbers(10);
    ASSERT_THAT(fib, ElementsAre(1, 1, 2, 3, 5, 8, 13, 21, 34, 55));
}
