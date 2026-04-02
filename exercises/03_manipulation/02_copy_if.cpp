// ============================================================
// EXERCISE 2: std::copy_if()
// ============================================================
// std::copy_if() copies elements from a source range into a
// destination, but only those for which a predicate returns
// true. It is the filtering variant of std::copy.
//
// Syntax:
//   std::copy_if(first, last, dest_first, predicate);
//   std::copy_if(first, last, std::back_inserter(dest), pred);
//
// Example:
//   std::vector<int> v = {1, -2, 3, -4, 5};
//   std::vector<int> pos;
//   std::copy_if(v.begin(), v.end(), std::back_inserter(pos),
//                [](int x){ return x > 0; });
//   // pos == {1, 3, 5}
//
// KEY IDEA: The predicate is called once per element; only
// elements where pred(elem) == true are written to the output.
// ============================================================

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: filterPositive
// Given a vector<int>, return a new vector containing only
// the elements that are strictly positive (> 0).
//
// Use std::copy_if with a lambda predicate.
// ------------------------------------------------------------
std::vector<int> filterPositive(const std::vector<int>& src) {
    // YOUR CODE HERE
    return {};
}

// ------------------------------------------------------------
// TASK 2: filterWords
// Given a vector<string> and a minimum length `minLen`, return
// a new vector containing only the words whose length is
// strictly greater than minLen.
//
// Use std::copy_if.
// ------------------------------------------------------------
std::vector<std::string> filterWords(const std::vector<std::string>& words,
                                     std::size_t minLen) {
    // YOUR CODE HERE
    return {};
}

// ------------------------------------------------------------
// TASK 3: copyUniqueFirst
// Given a SORTED vector<int>, return a new vector containing
// only the first occurrence of each value (i.e., remove
// consecutive duplicates).
//
// Use std::copy_if: keep an element only when it differs from
// the previously kept value. Capture a "previous" variable in
// your lambda and update it each time you copy an element.
//
// Hint: initialise prev to a sentinel that can never appear
// (e.g. INT_MIN) so the very first element is always kept.
// ------------------------------------------------------------
std::vector<int> copyUniqueFirst(const std::vector<int>& src) {
    // YOUR CODE HERE
    return {};
}

// ============================================================
int main() {
    std::cout << "=== std::copy_if() ===\n";

    test::section("filterPositive");
    test::check("mixed values",           filterPositive({-3,-1,0,2,4})   == std::vector<int>({2,4}));
    test::check("all positive",           filterPositive({1,2,3})          == std::vector<int>({1,2,3}));
    test::check("all negative",           filterPositive({-1,-2,-3})       == std::vector<int>({}));
    test::check("zero excluded",          filterPositive({0,1,0,2})        == std::vector<int>({1,2}));
    test::check("empty input",            filterPositive({})               == std::vector<int>({}));
    test::check("single positive",        filterPositive({7})              == std::vector<int>({7}));

    test::section("filterWords");
    test::check("length > 3",             filterWords({"hi","hello","hey","world"}, 3) == std::vector<std::string>({"hello","world"}));
    test::check("length > 0",             filterWords({"","a","ab","abc"}, 0)          == std::vector<std::string>({"a","ab","abc"}));
    test::check("none qualify",           filterWords({"a","b","c"}, 5)                == std::vector<std::string>({}));
    test::check("all qualify",            filterWords({"long","words","here"}, 2)      == std::vector<std::string>({"long","words","here"}));
    test::check("empty input",            filterWords({}, 2)                           == std::vector<std::string>({}));
    test::check("exact length excluded",  filterWords({"cat","dog","bird"}, 3)         == std::vector<std::string>({"bird"}));

    test::section("copyUniqueFirst");
    test::check("basic duplicates",       copyUniqueFirst({1,1,2,3,3,3,4}) == std::vector<int>({1,2,3,4}));
    test::check("no duplicates",          copyUniqueFirst({1,2,3,4,5})     == std::vector<int>({1,2,3,4,5}));
    test::check("all same",               copyUniqueFirst({5,5,5,5})       == std::vector<int>({5}));
    test::check("empty input",            copyUniqueFirst({})              == std::vector<int>({}));
    test::check("single element",         copyUniqueFirst({9})             == std::vector<int>({9}));
    test::check("two distinct groups",    copyUniqueFirst({1,1,2,2})       == std::vector<int>({1,2}));

    return test::summary();
}
