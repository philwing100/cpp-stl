// ============================================================
// EXERCISE 7: std::fill()
// ============================================================
// std::fill() assigns a single value to every element in a
// range [first, last). It is the simplest way to initialise
// or overwrite a range without a loop.
//
// Syntax:
//   std::fill(first, last, value);
//
// Related: std::fill_n(first, n, value) fills exactly n
// elements starting at `first`.
//
// Example:
//   std::vector<int> v(5);
//   std::fill(v.begin(), v.end(), 7);
//   // v == {7, 7, 7, 7, 7}
//
//   std::fill(v.begin() + 1, v.begin() + 3, 0);
//   // v == {7, 0, 0, 7, 7}
//
// KEY IDEA: std::fill overwrites existing elements — make sure
// the range is already allocated (use resize, not reserve).
// ============================================================

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: createFilled
// Return a new vector<int> of size n where every element is
// set to `value`.
//
// Resize the vector first, then use std::fill.
// ------------------------------------------------------------
std::vector<int> createFilled(int n, int value) {
    // YOUR CODE HERE
    return {};
}

// ------------------------------------------------------------
// TASK 2: zeroOut
// Given a vector<int>, set all its elements to 0 and return
// the modified vector.
//
// Use std::fill over the full range.
// ------------------------------------------------------------
std::vector<int> zeroOut(std::vector<int> v) {
    // YOUR CODE HERE
    return v;
}

// ------------------------------------------------------------
// TASK 3: fillMiddle
// Given a vector<int> and indices `start` and `end` (exclusive),
// fill the subrange [start, end) with `value`. Return the
// modified vector; elements outside the range are unchanged.
//
// Use std::fill with offset iterators.
// ------------------------------------------------------------
std::vector<int> fillMiddle(std::vector<int> v, int start, int end, int value) {
    // YOUR CODE HERE
    return v;
}

// ============================================================
int main() {
    std::cout << "=== std::fill() ===\n";

    test::section("createFilled");
    test::check("fill 5 with 7",      createFilled(5, 7)  == std::vector<int>({7,7,7,7,7}));
    test::check("fill 3 with 0",      createFilled(3, 0)  == std::vector<int>({0,0,0}));
    test::check("fill 1 with 42",     createFilled(1, 42) == std::vector<int>({42}));
    test::check("fill 0 elements",    createFilled(0, 9)  == std::vector<int>({}));
    test::check("fill 4 with -1",     createFilled(4, -1) == std::vector<int>({-1,-1,-1,-1}));
    test::check("fill 2 with 100",    createFilled(2, 100)== std::vector<int>({100,100}));

    test::section("zeroOut");
    test::check("zero a vector",      zeroOut({1,2,3,4,5})     == std::vector<int>({0,0,0,0,0}));
    test::check("already zeros",      zeroOut({0,0,0})          == std::vector<int>({0,0,0}));
    test::check("single element",     zeroOut({99})             == std::vector<int>({0}));
    test::check("empty vector",       zeroOut({})               == std::vector<int>({}));
    test::check("negative values",    zeroOut({-3,-2,-1})       == std::vector<int>({0,0,0}));
    test::check("mixed values",       zeroOut({1,0,-1,2,0})     == std::vector<int>({0,0,0,0,0}));

    test::section("fillMiddle");
    test::check("fill indices 1..3",  fillMiddle({1,2,3,4,5}, 1, 4, 0) == std::vector<int>({1,0,0,0,5}));
    test::check("fill from start",    fillMiddle({9,8,7,6}, 0, 2, 1)   == std::vector<int>({1,1,7,6}));
    test::check("fill to end",        fillMiddle({1,2,3,4}, 2, 4, 5)   == std::vector<int>({1,2,5,5}));
    test::check("zero-length range",  fillMiddle({1,2,3}, 1, 1, 9)     == std::vector<int>({1,2,3}));
    test::check("fill entire range",  fillMiddle({5,6,7}, 0, 3, 0)     == std::vector<int>({0,0,0}));
    test::check("single-element mid", fillMiddle({1,2,3,4,5}, 2, 3, 7) == std::vector<int>({1,2,7,4,5}));

    return test::summary();
}
