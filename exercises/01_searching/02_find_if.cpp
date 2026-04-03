// ============================================================
// EXERCISE 2: std::find_if()
// ============================================================
// std::find_if() searches a range and returns an iterator to
// the FIRST element for which a predicate returns true.
// Returns the end iterator if no element matches.
//
// Syntax:
//   auto it = std::find_if(first, last, predicate);
//
// The predicate is any callable: lambda, function pointer, or
// functor that takes one element and returns bool.
//
// Example:
//   std::vector<int> v = {1, 3, 8, 5};
//   auto it = std::find_if(v.begin(), v.end(),
//                          [](int x){ return x % 2 == 0; });
//   // *it == 8  (first even number)
//
// KEY DIFFERENCE FROM find(): find() matches exact values;
// find_if() matches by condition — far more flexible.
// ============================================================

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: firstEven
// Return the first even number in vec.
// Return -1 if there is no even number.
//
// Use std::find_if() with a lambda.
// ------------------------------------------------------------
int firstEven(const std::vector<int>& vec) {
    auto it = std::find_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0;});
    if(it==vec.end()){
        return -1;
    }else{
        return vec[it-vec.begin()];
    }
}

// ------------------------------------------------------------
// TASK 2: firstLongerThan
// Given a vector of strings and a length n, return the first
// string whose length is strictly greater than n.
// Return "" (empty string) if none qualifies.
//
// Use std::find_if().
// ------------------------------------------------------------
std::string firstLongerThan(const std::vector<std::string>& words, int n) {
    auto it = std::find_if(words.begin(), words.end(), [&n](const std::string x){ return x.length() > n; });
    if (it == words.end()) return "";
    return *it;
}

// ------------------------------------------------------------
// TASK 3: firstNegativeIndex
// Return the 0-based index of the first negative number in vec.
// Return -1 if no negative number exists.
//
// Use std::find_if().
// ------------------------------------------------------------
int firstNegativeIndex(const std::vector<int>& vec) {
    auto it = std::find_if(vec.begin(), vec.end(), [](const int x){ return x<0; });
    if(it==vec.end()) return -1;
    return it-vec.begin();
}

// ============================================================
int main() {
    std::cout << "=== std::find_if() ===\n";

    test::section("firstEven");
    test::check("first even at start",    firstEven({2,3,5,7}) == 2);
    test::check("first even in middle",   firstEven({1,3,4,7}) == 4);
    test::check("first even at end",      firstEven({1,3,5,6}) == 6);
    test::check("no even — returns -1",   firstEven({1,3,5,7}) == -1);
    test::check("empty — returns -1",     firstEven({}) == -1);
    test::check("multiple evens",         firstEven({2,4,6}) == 2);
    test::check("negative even",          firstEven({-3,-2,1}) == -2);

    test::section("firstLongerThan");
    test::check("finds longer word",      firstLongerThan({"hi","world","!"}, 3) == "world");
    test::check("first qualifying",       firstLongerThan({"abc","de","fghi"}, 2) == "abc");
    test::check("none qualify — empty",   firstLongerThan({"a","bb","ccc"}, 5) == "");
    test::check("empty vector — empty",   firstLongerThan({}, 1) == "");
    test::check("exact length excluded",  firstLongerThan({"four","seven"}, 4) == "seven");

    test::section("firstNegativeIndex");
    test::check("negative at start",      firstNegativeIndex({-1,2,3}) == 0);
    test::check("negative in middle",     firstNegativeIndex({1,2,-3,4}) == 2);
    test::check("negative at end",        firstNegativeIndex({1,2,-3}) == 2);
    test::check("no negatives — -1",      firstNegativeIndex({1,2,3}) == -1);
    test::check("empty — -1",             firstNegativeIndex({}) == -1);
    test::check("all negative",           firstNegativeIndex({-5,-3,-1}) == 0);

    return test::summary();
}
