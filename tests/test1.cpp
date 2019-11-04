#include "gtest/gtest.h"
#include "hello/hello.hpp"

TEST(GreetTest, TestArg) {
	greet("World");
}

TEST(GreetTest, TestVoid) {
	greet();
}
