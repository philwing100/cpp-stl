// ============================================================
// EXERCISE 3: std::lexicographical_compare()
// ============================================================
// std::lexicographical_compare() returns true if range1 is
// lexicographically LESS THAN range2 — the same ordering used
// in a dictionary. Elements are compared one by one from the
// front; the first differing element decides the result.
//
// If one range is a prefix of the other, the shorter range is
// considered "less than" the longer one.
// If the ranges are equal, the function returns false
// (neither is less than the other).
//
// Syntax:
//   std::lexicographical_compare(first1, last1, first2, last2)
//   std::lexicographical_compare(first1, last1, first2, last2, comp)
//
// Example:
//   std::vector<int> a = {1, 2, 3};
//   std::vector<int> b = {1, 2, 4};
//   std::lexicographical_compare(a.begin(), a.end(),
//                                b.begin(), b.end()); // true  (3 < 4)
//
//   std::vector<int> c = {1, 2};
//   std::lexicographical_compare(c.begin(), c.end(),
//                                a.begin(), a.end()); // true  (prefix rule)
//
// KEY IDEA: This is exactly how strings are sorted alphabetically.
// It works on ANY range — ints, chars, custom types.
// ============================================================

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: isLexBefore
// Return true if vector a comes before vector b in
// lexicographic order.
//
// Use std::lexicographical_compare().
// ------------------------------------------------------------
bool isLexBefore(const std::vector<int>& a, const std::vector<int>& b) {
    // YOUR CODE HERE
    return false;
}

// ------------------------------------------------------------
// TASK 2: sortStringsLex
// Given a vector of strings, sort them in lexicographic order
// and return the sorted vector.
//
// Use std::sort() with std::lexicographical_compare as the
// comparator argument.
// ------------------------------------------------------------
std::vector<std::string> sortStringsLex(std::vector<std::string> words) {
    // YOUR CODE HERE
    return words;
}

// ------------------------------------------------------------
// TASK 3: shortestLex
// Given a vector<vector<int>>, return the 0-based INDEX of
// the lexicographically smallest sub-vector.
// You may assume the outer vector is non-empty.
//
// Hint: iterate through the sub-vectors, tracking the index
// of the current minimum. Use lexicographical_compare to
// decide if a new candidate is smaller.
// ------------------------------------------------------------
int shortestLex(const std::vector<std::vector<int>>& vecs) {
    // YOUR CODE HERE
    return 0;
}

// ============================================================
int main() {
    std::cout << "=== std::lexicographical_compare() ===\n";

    test::section("isLexBefore");
    test::check("first differs — less",      isLexBefore({1,2,3}, {2,2,3})     == true);
    test::check("last differs — less",       isLexBefore({1,2,3}, {1,2,4})     == true);
    test::check("prefix is less",            isLexBefore({1,2},   {1,2,3})     == true);
    test::check("equal — false",             isLexBefore({1,2,3}, {1,2,3})     == false);
    test::check("greater — false",           isLexBefore({1,2,4}, {1,2,3})     == false);
    test::check("empty is less than non-empty", isLexBefore({}, {1})           == true);

    test::section("sortStringsLex");
    {
        auto result = sortStringsLex({"banana","apple","cherry"});
        test::check("apple first",   result[0] == "apple");
        test::check("banana second", result[1] == "banana");
        test::check("cherry third",  result[2] == "cherry");
    }
    {
        auto result = sortStringsLex({"zoo","ant","mango","bee"});
        test::check("ant first",  result[0] == "ant");
        test::check("zoo last",   result[3] == "zoo");
    }
    {
        auto result = sortStringsLex({"only"});
        test::check("single element unchanged", result[0] == "only");
    }

    test::section("shortestLex");
    test::check("smallest at index 1",
        shortestLex({{3,4,5},{1,2,3},{2,2,2}}) == 1);
    test::check("smallest at index 0",
        shortestLex({{1,0},{2,0},{3,0}})        == 0);
    test::check("smallest at last index",
        shortestLex({{5},{3},{1}})              == 2);
    test::check("single sub-vector — index 0",
        shortestLex({{7,8,9}})                  == 0);
    test::check("prefix rule — shorter is smaller",
        shortestLex({{1,2,3},{1,2},{1,2,4}})    == 1);
    test::check("tie broken by first diff",
        shortestLex({{1,9},{1,2},{1,5}})        == 1);

    return test::summary();
}
