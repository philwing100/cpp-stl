// ============================================================
// EXERCISE 1: std::copy()
// ============================================================
// std::copy() copies elements from a source range into a
// destination range, preserving order. The destination must
// have enough space — either pre-resize the destination vector
// or use std::back_inserter to grow it automatically.
//
// Syntax:
//   std::copy(first, last, dest_first);
//   std::copy(first, last, std::back_inserter(dest));
//
// Example:
//   std::vector<int> src = {1, 2, 3};
//   std::vector<int> dst;
//   std::copy(src.begin(), src.end(), std::back_inserter(dst));
//   // dst == {1, 2, 3}
//
// KEY IDEA: std::copy does not resize the destination — you
// must ensure space exists beforehand, or use back_inserter.
// ============================================================

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: copyToNew
// Given a vector<int>, copy all its elements into a brand-new
// vector and return it.
//
// Use std::copy with std::back_inserter — do not use the
// vector copy constructor or assignment directly.
// ------------------------------------------------------------
std::vector<int> copyToNew(const std::vector<int>& src) {
    // YOUR CODE HERE
    return {};
}

// ------------------------------------------------------------
// TASK 2: copySlice
// Given a vector<int> and indices `start` and `end` (exclusive),
// copy the elements in that range into a new vector and return it.
//
// Use std::copy with iterators offset by start and end.
// ------------------------------------------------------------
std::vector<int> copySlice(const std::vector<int>& src, int start, int end) {
    // YOUR CODE HERE
    return {};
}

// ------------------------------------------------------------
// TASK 3: prependZeros
// Given a vector<int> and a count m, return a new vector that
// contains m zeros followed by all elements of the original.
//
// Use std::fill (or two std::copy calls) — do not manually
// push_back in a loop.
// ------------------------------------------------------------
std::vector<int> prependZeros(const std::vector<int>& src, int m) {
    // YOUR CODE HERE
    return {};
}

// ============================================================
int main() {
    std::cout << "=== std::copy() ===\n";

    test::section("copyToNew");
    test::check("copies full vector",        copyToNew({1,2,3,4,5}) == std::vector<int>({1,2,3,4,5}));
    test::check("single element",            copyToNew({42})        == std::vector<int>({42}));
    test::check("empty vector",              copyToNew({})          == std::vector<int>({}));
    test::check("preserves order",           copyToNew({5,4,3,2,1}) == std::vector<int>({5,4,3,2,1}));
    test::check("duplicates preserved",      copyToNew({7,7,7})     == std::vector<int>({7,7,7}));
    test::check("negative values",           copyToNew({-1,-2,-3})  == std::vector<int>({-1,-2,-3}));

    test::section("copySlice");
    test::check("middle slice",        copySlice({10,20,30,40,50}, 1, 4) == std::vector<int>({20,30,40}));
    test::check("from start",          copySlice({1,2,3,4,5}, 0, 3)      == std::vector<int>({1,2,3}));
    test::check("to end",              copySlice({1,2,3,4,5}, 3, 5)      == std::vector<int>({4,5}));
    test::check("single element",      copySlice({1,2,3,4,5}, 2, 3)      == std::vector<int>({3}));
    test::check("zero-length slice",   copySlice({1,2,3}, 1, 1)          == std::vector<int>({}));
    test::check("full range",          copySlice({9,8,7}, 0, 3)          == std::vector<int>({9,8,7}));

    test::section("prependZeros");
    test::check("prepend 3 zeros",     prependZeros({1,2,3}, 3)   == std::vector<int>({0,0,0,1,2,3}));
    test::check("prepend 1 zero",      prependZeros({5,6}, 1)     == std::vector<int>({0,5,6}));
    test::check("prepend 0 zeros",     prependZeros({4,5,6}, 0)   == std::vector<int>({4,5,6}));
    test::check("empty src, 2 zeros",  prependZeros({}, 2)        == std::vector<int>({0,0}));
    test::check("prepend 5 zeros",     prependZeros({1}, 5)       == std::vector<int>({0,0,0,0,0,1}));
    test::check("all zeros remain",    prependZeros({0,0}, 2)     == std::vector<int>({0,0,0,0}));

    return test::summary();
}
