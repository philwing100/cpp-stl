// ============================================================
// EXERCISE 4: std::move() — the algorithm
// ============================================================
// std::move (in <algorithm>) is a RANGE algorithm that moves
// elements from a source range into a destination, leaving
// the source elements in a valid-but-unspecified state.
//
// For trivial types like int this is identical to copy.
// For types with resources (std::string, etc.) it "steals"
// the internal buffer, which avoids expensive deep copies.
//
// Syntax:
//   std::move(first, last, dest_first);
//   std::move(first, last, std::back_inserter(dest));
//
// Example:
//   std::vector<std::string> src = {"hello", "world"};
//   std::vector<std::string> dst;
//   std::move(src.begin(), src.end(), std::back_inserter(dst));
//   // dst == {"hello", "world"}; src strings may be empty
//
// KEY IDEA: This is std::move the *algorithm* (two iterators +
// destination), NOT std::move the *cast* (single argument).
// After moving, do not rely on the source elements' values.
// ============================================================

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: moveStrings
// Given a vector<string> by value, use the std::move algorithm
// to transfer all elements into a new vector and return it.
//
// Do NOT use std::move(element) — use the range form:
//   std::move(src.begin(), src.end(), std::back_inserter(dst))
// ------------------------------------------------------------
std::vector<std::string> moveStrings(std::vector<std::string> src) {
    // YOUR CODE HERE
    return {};
}

// ------------------------------------------------------------
// TASK 2: moveFirstN
// Given a vector<string> by value and a count n, move only
// the first n elements into a new vector and return it.
//
// Use the std::move algorithm with an end iterator offset by n.
// ------------------------------------------------------------
std::vector<std::string> moveFirstN(std::vector<std::string> src, int n) {
    // YOUR CODE HERE
    return {};
}

// ------------------------------------------------------------
// TASK 3: mergeByMoving
// Given two vectors<string> by value, move all elements from
// both into a single result vector using two calls to the
// std::move algorithm; return the result.
// ------------------------------------------------------------
std::vector<std::string> mergeByMoving(std::vector<std::string> a,
                                        std::vector<std::string> b) {
    // YOUR CODE HERE
    return {};
}

// ============================================================
int main() {
    std::cout << "=== std::move() — the algorithm ===\n";

    test::section("moveStrings");
    test::check("moves all elements",
        moveStrings({"hello","world","foo"}) == std::vector<std::string>({"hello","world","foo"}));
    test::check("single string",
        moveStrings({"only"}) == std::vector<std::string>({"only"}));
    test::check("empty source",
        moveStrings({}) == std::vector<std::string>({}));
    test::check("preserves order",
        moveStrings({"c","b","a"}) == std::vector<std::string>({"c","b","a"}));
    test::check("longer sequence",
        moveStrings({"one","two","three","four","five"}) ==
            std::vector<std::string>({"one","two","three","four","five"}));

    test::section("moveFirstN");
    test::check("first 2 of 4",
        moveFirstN({"a","b","c","d"}, 2) == std::vector<std::string>({"a","b"}));
    test::check("first 0",
        moveFirstN({"x","y","z"}, 0) == std::vector<std::string>({}));
    test::check("first 1",
        moveFirstN({"alpha","beta"}, 1) == std::vector<std::string>({"alpha"}));
    test::check("n equals size",
        moveFirstN({"p","q","r"}, 3) == std::vector<std::string>({"p","q","r"}));
    test::check("single element source",
        moveFirstN({"sole"}, 1) == std::vector<std::string>({"sole"}));

    test::section("mergeByMoving");
    test::check("two equal halves",
        mergeByMoving({"a","b"},{"c","d"}) == std::vector<std::string>({"a","b","c","d"}));
    test::check("empty first",
        mergeByMoving({},{"x","y"}) == std::vector<std::string>({"x","y"}));
    test::check("empty second",
        mergeByMoving({"x","y"},{}) == std::vector<std::string>({"x","y"}));
    test::check("both empty",
        mergeByMoving({},{}) == std::vector<std::string>({}));
    test::check("longer merge",
        mergeByMoving({"one","two","three"},{"four","five"}) ==
            std::vector<std::string>({"one","two","three","four","five"}));
    test::check("order preserved across both",
        mergeByMoving({"first"},{"second","third"}) ==
            std::vector<std::string>({"first","second","third"}));

    return test::summary();
}
