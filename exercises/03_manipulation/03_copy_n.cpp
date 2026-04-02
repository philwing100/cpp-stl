// ============================================================
// EXERCISE 3: std::copy_n()
// ============================================================
// std::copy_n() copies exactly n elements starting from a
// source iterator into a destination. It is a convenient
// alternative to std::copy when you know the count rather
// than having an end iterator.
//
// Syntax:
//   std::copy_n(first, n, dest_first);
//   std::copy_n(first, n, std::back_inserter(dest));
//
// Example:
//   std::vector<int> v = {10, 20, 30, 40, 50};
//   std::vector<int> out;
//   std::copy_n(v.begin(), 3, std::back_inserter(out));
//   // out == {10, 20, 30}
//
// KEY IDEA: n must not exceed the number of available elements
// in the source — there is no bounds checking.
// ============================================================

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: firstN
// Given a vector<int> and a count n, return a new vector
// containing only the first n elements.
// If n == 0 return an empty vector.
//
// Use std::copy_n.
// ------------------------------------------------------------
std::vector<int> firstN(const std::vector<int>& src, int n) {
    // YOUR CODE HERE
    return {};
}

// ------------------------------------------------------------
// TASK 2: takeFrom
// Given a vector<int>, a starting index `start`, and a count
// n, return a new vector containing n elements beginning at
// position `start`.
//
// Use std::copy_n with an iterator offset by `start`.
// ------------------------------------------------------------
std::vector<int> takeFrom(const std::vector<int>& src, int start, int n) {
    // YOUR CODE HERE
    return {};
}

// ------------------------------------------------------------
// TASK 3: repeatBlock
// Given a vector<int> `block` and a repeat count n, return a
// new vector that is `block` concatenated n times.
//
// Use std::copy_n inside a loop — call it once per repetition.
// ------------------------------------------------------------
std::vector<int> repeatBlock(const std::vector<int>& block, int n) {
    // YOUR CODE HERE
    return {};
}

// ============================================================
int main() {
    std::cout << "=== std::copy_n() ===\n";

    test::section("firstN");
    test::check("first 3 of 5",      firstN({1,2,3,4,5}, 3) == std::vector<int>({1,2,3}));
    test::check("first 1",           firstN({9,8,7}, 1)      == std::vector<int>({9}));
    test::check("n == size",         firstN({4,5,6}, 3)      == std::vector<int>({4,5,6}));
    test::check("n == 0",            firstN({1,2,3}, 0)      == std::vector<int>({}));
    test::check("empty vector n=0",  firstN({}, 0)           == std::vector<int>({}));
    test::check("first 2 negatives", firstN({-1,-2,-3}, 2)   == std::vector<int>({-1,-2}));

    test::section("takeFrom");
    test::check("offset 1 take 3",   takeFrom({10,20,30,40,50}, 1, 3) == std::vector<int>({20,30,40}));
    test::check("offset 0 take 2",   takeFrom({1,2,3,4}, 0, 2)        == std::vector<int>({1,2}));
    test::check("offset 2 take 1",   takeFrom({5,6,7,8}, 2, 1)        == std::vector<int>({7}));
    test::check("take 0 elements",   takeFrom({1,2,3}, 1, 0)          == std::vector<int>({}));
    test::check("last element only", takeFrom({3,1,4,1,5}, 4, 1)      == std::vector<int>({5}));
    test::check("full range",        takeFrom({7,8,9}, 0, 3)          == std::vector<int>({7,8,9}));

    test::section("repeatBlock");
    test::check("repeat 3 times",    repeatBlock({1,2}, 3)   == std::vector<int>({1,2,1,2,1,2}));
    test::check("repeat 1 time",     repeatBlock({4,5,6}, 1) == std::vector<int>({4,5,6}));
    test::check("repeat 0 times",    repeatBlock({1,2,3}, 0) == std::vector<int>({}));
    test::check("single element ×4", repeatBlock({9}, 4)     == std::vector<int>({9,9,9,9}));
    test::check("longer block ×2",   repeatBlock({1,2,3}, 2) == std::vector<int>({1,2,3,1,2,3}));
    test::check("empty block ×5",    repeatBlock({}, 5)      == std::vector<int>({}));

    return test::summary();
}
