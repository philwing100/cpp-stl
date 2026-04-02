// ============================================================
// EXERCISE 8: std::transform()
// ============================================================
// std::transform() applies a function to each element (or pair
// of elements) and writes the results to a destination range.
// It comes in two forms:
//
//   Unary  — one input range, one output range:
//     std::transform(first, last, dest, unary_op);
//
//   Binary — two input ranges, one output range:
//     std::transform(first1, last1, first2, dest, binary_op);
//
// Example (unary):
//   std::vector<int> v = {1, 2, 3};
//   std::vector<int> out;
//   std::transform(v.begin(), v.end(), std::back_inserter(out),
//                  [](int x){ return x * 2; });
//   // out == {2, 4, 6}
//
// Example (binary):
//   std::vector<int> a = {1,2,3}, b = {10,20,30};
//   std::vector<int> sum;
//   std::transform(a.begin(), a.end(), b.begin(),
//                  std::back_inserter(sum),
//                  [](int x, int y){ return x + y; });
//   // sum == {11, 22, 33}
//
// KEY IDEA: std::transform does NOT modify the source; it
// writes results to the destination. Source and destination
// CAN overlap (in-place transform is valid).
// ============================================================

#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: doubleAll
// Given a vector<int>, return a NEW vector where each element
// is multiplied by 2.
//
// Use the unary form of std::transform with std::back_inserter.
// ------------------------------------------------------------
std::vector<int> doubleAll(const std::vector<int>& v) {
    // YOUR CODE HERE
    return {};
}

// ------------------------------------------------------------
// TASK 2: toUpperCase
// Given a vector<string>, return a new vector where every
// character in every string has been converted to uppercase.
//
// Use std::transform on the outer vector. For each string,
// apply another std::transform (or modify in-place) using
// ::toupper on individual characters.
// ------------------------------------------------------------
std::vector<std::string> toUpperCase(const std::vector<std::string>& words) {
    // YOUR CODE HERE
    return {};
}

// ------------------------------------------------------------
// TASK 3: addVectors
// Given two equal-length vectors<int>, return a new vector
// where each element is the sum of the corresponding elements
// from both input vectors.
//
// Use the binary form of std::transform.
// ------------------------------------------------------------
std::vector<int> addVectors(const std::vector<int>& a, const std::vector<int>& b) {
    // YOUR CODE HERE
    return {};
}

// ============================================================
int main() {
    std::cout << "=== std::transform() ===\n";

    test::section("doubleAll");
    test::check("basic doubling",     doubleAll({1,2,3,4,5})  == std::vector<int>({2,4,6,8,10}));
    test::check("includes zero",      doubleAll({0,1,2})       == std::vector<int>({0,2,4}));
    test::check("negative values",    doubleAll({-1,-2,-3})    == std::vector<int>({-2,-4,-6}));
    test::check("single element",     doubleAll({7})           == std::vector<int>({14}));
    test::check("empty vector",       doubleAll({})            == std::vector<int>({}));
    test::check("mixed signs",        doubleAll({-1,0,1})      == std::vector<int>({-2,0,2}));

    test::section("toUpperCase");
    test::check("all lowercase",
        toUpperCase({"hello","world"}) == std::vector<std::string>({"HELLO","WORLD"}));
    test::check("already uppercase",
        toUpperCase({"ABC","DEF"})     == std::vector<std::string>({"ABC","DEF"}));
    test::check("mixed case",
        toUpperCase({"hElLo"})         == std::vector<std::string>({"HELLO"}));
    test::check("empty string in vec",
        toUpperCase({""})              == std::vector<std::string>({""}));
    test::check("empty vector",
        toUpperCase({})               == std::vector<std::string>({}));
    test::check("single char words",
        toUpperCase({"a","b","c"})     == std::vector<std::string>({"A","B","C"}));

    test::section("addVectors");
    test::check("basic addition",     addVectors({1,2,3},{4,5,6})   == std::vector<int>({5,7,9}));
    test::check("add zeros",          addVectors({1,2,3},{0,0,0})   == std::vector<int>({1,2,3}));
    test::check("negative values",    addVectors({-1,-2},{1,2})     == std::vector<int>({0,0}));
    test::check("single elements",    addVectors({10},{20})         == std::vector<int>({30}));
    test::check("empty vectors",      addVectors({},{})             == std::vector<int>({}));
    test::check("larger vectors",     addVectors({1,1,1,1},{2,2,2,2}) == std::vector<int>({3,3,3,3}));

    return test::summary();
}
