// ============================================================
// EXERCISE 9: std::generate()
// ============================================================
// std::generate() fills a range by calling a generator
// function (a callable that takes NO arguments) once per
// element and assigning its return value.
//
// Syntax:
//   std::generate(first, last, generator);
//
// Related: std::generate_n(first, n, generator) generates
// exactly n values starting at `first`.
//
// Example:
//   int counter = 0;
//   std::vector<int> v(5);
//   std::generate(v.begin(), v.end(), [&counter]{ return counter++; });
//   // v == {0, 1, 2, 3, 4}
//
// KEY IDEA: The generator is called repeatedly with no input —
// it must capture any state it needs via a lambda capture.
// The vector must be pre-sized (use resize); generate does NOT
// push new elements.
// ============================================================

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: generateSequence
// Return a vector of size n where element i equals:
//   start + i * step
// E.g. start=2, step=3, n=4 → {2, 5, 8, 11}
//
// Use std::generate with a capturing lambda that tracks a
// running value.
// ------------------------------------------------------------
std::vector<int> generateSequence(int start, int step, int n) {
    // YOUR CODE HERE
    return {};
}

// ------------------------------------------------------------
// TASK 2: generateFibonacci
// Return the first n Fibonacci numbers (starting 0, 1, 1, 2, …).
//
// Use std::generate. Track the last two values in the lambda
// capture (a and b), yield a each call, then advance: a=b, b=a+b.
// ------------------------------------------------------------
std::vector<int> generateFibonacci(int n) {
    // YOUR CODE HERE
    return {};
}

// ------------------------------------------------------------
// TASK 3: generateAlternating
// Return a vector of size n that alternates between values
// `a` and `b`, starting with `a`.
// E.g. a=1, b=2, n=6 → {1, 2, 1, 2, 1, 2}
//
// Use std::generate with a lambda that flips a boolean flag
// (or uses a counter % 2) each call.
// ------------------------------------------------------------
std::vector<int> generateAlternating(int a, int b, int n) {
    // YOUR CODE HERE
    return {};
}

// ============================================================
int main() {
    std::cout << "=== std::generate() ===\n";

    test::section("generateSequence");
    test::check("start=0 step=1 n=5",  generateSequence(0, 1, 5)  == std::vector<int>({0,1,2,3,4}));
    test::check("start=2 step=3 n=4",  generateSequence(2, 3, 4)  == std::vector<int>({2,5,8,11}));
    test::check("step=0 all same",      generateSequence(7, 0, 3)  == std::vector<int>({7,7,7}));
    test::check("n=0 empty",            generateSequence(1, 1, 0)  == std::vector<int>({}));
    test::check("negative step",        generateSequence(10,-2,4)  == std::vector<int>({10,8,6,4}));
    test::check("start=1 step=10 n=3", generateSequence(1, 10, 3) == std::vector<int>({1,11,21}));

    test::section("generateFibonacci");
    test::check("first 7 fibonacci",    generateFibonacci(7)  == std::vector<int>({0,1,1,2,3,5,8}));
    test::check("first 1",              generateFibonacci(1)  == std::vector<int>({0}));
    test::check("first 2",              generateFibonacci(2)  == std::vector<int>({0,1}));
    test::check("first 5",              generateFibonacci(5)  == std::vector<int>({0,1,1,2,3}));
    test::check("n=0 empty",            generateFibonacci(0)  == std::vector<int>({}));
    test::check("first 10",             generateFibonacci(10) == std::vector<int>({0,1,1,2,3,5,8,13,21,34}));

    test::section("generateAlternating");
    test::check("a=1 b=2 n=6",         generateAlternating(1,2,6) == std::vector<int>({1,2,1,2,1,2}));
    test::check("a=0 b=1 n=4",         generateAlternating(0,1,4) == std::vector<int>({0,1,0,1}));
    test::check("a=5 b=5 n=4",         generateAlternating(5,5,4) == std::vector<int>({5,5,5,5}));
    test::check("n=1 single value",     generateAlternating(3,7,1) == std::vector<int>({3}));
    test::check("n=0 empty",            generateAlternating(1,2,0) == std::vector<int>({}));
    test::check("odd count ends on a",  generateAlternating(9,0,5) == std::vector<int>({9,0,9,0,9}));

    return test::summary();
}
