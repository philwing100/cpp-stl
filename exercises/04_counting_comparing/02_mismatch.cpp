// ============================================================
// EXERCISE 2: std::mismatch()
// ============================================================
// std::mismatch() compares two ranges element by element and
// returns a std::pair of iterators pointing to the FIRST
// position where they differ. If the ranges are identical
// (up to the length of the first range), it returns
// {last1, corresponding_position_in_range2}.
//
// Syntax:
//   auto [it1, it2] = std::mismatch(first1, last1, first2);
//   auto [it1, it2] = std::mismatch(first1, last1, first2, last2);
//   auto [it1, it2] = std::mismatch(first1, last1, first2, comparator);
//
// Example:
//   std::vector<int> a = {1, 2, 3, 4};
//   std::vector<int> b = {1, 2, 9, 4};
//   auto [ia, ib] = std::mismatch(a.begin(), a.end(), b.begin());
//   // ia points to 3 (index 2), ib points to 9 (index 2)
//   // std::distance(a.begin(), ia) == 2
//
// KEY IDEA: Subtract (or use std::distance from) the begin
// iterator to convert the returned iterator into an index.
// If it1 == last1, the ranges matched completely.
// ============================================================

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: firstDiffIndex
// Given two same-length vectors<int>, return the 0-based index
// of the first position where they differ.
// Return -1 if the vectors are identical.
//
// Use std::mismatch(), then std::distance(a.begin(), it1).
// ------------------------------------------------------------
int firstDiffIndex(const std::vector<int>& a, const std::vector<int>& b) {
    // YOUR CODE HERE
    return -1;
}

// ------------------------------------------------------------
// TASK 2: commonPrefixLength
// Return the length of the longest common prefix shared by two
// vectors<int>. For example:
//   {1,2,3,4} and {1,2,9,9} → 2   (first two elements match)
//   {1,2,3}   and {1,2,3}   → 3   (all match)
//   {5,6}     and {9,8}     → 0   (no common prefix)
//
// Use std::mismatch(), then std::distance(a.begin(), it1).
// ------------------------------------------------------------
int commonPrefixLength(const std::vector<int>& a, const std::vector<int>& b) {
    // YOUR CODE HERE
    return 0;
}

// ------------------------------------------------------------
// TASK 3: firstDiffChar
// Given two strings, return the 0-based index of the first
// character that differs between them.
// Return -1 if the strings are identical (up to the shorter
// one's length — treat them as equal only if lengths also match).
//
// Use std::mismatch() on the string iterators directly.
// ------------------------------------------------------------
int firstDiffChar(const std::string& s1, const std::string& s2) {
    // YOUR CODE HERE
    return -1;
}

// ============================================================
int main() {
    std::cout << "=== std::mismatch() ===\n";

    test::section("firstDiffIndex");
    test::check("differs at index 2",       firstDiffIndex({1,2,3,4}, {1,2,9,4})  == 2);
    test::check("differs at index 0",       firstDiffIndex({5,2,3},   {9,2,3})    == 0);
    test::check("differs at last index",    firstDiffIndex({1,2,3},   {1,2,9})    == 2);
    test::check("identical — returns -1",   firstDiffIndex({1,2,3},   {1,2,3})    == -1);
    test::check("empty vectors — returns -1",firstDiffIndex({},        {})         == -1);
    test::check("single element differs",   firstDiffIndex({7},       {8})        == 0);

    test::section("commonPrefixLength");
    test::check("two elements match",       commonPrefixLength({1,2,3,4}, {1,2,9,9}) == 2);
    test::check("all elements match",       commonPrefixLength({1,2,3},   {1,2,3})   == 3);
    test::check("no common prefix",         commonPrefixLength({5,6,7},   {9,8,7})   == 0);
    test::check("both empty — 0",           commonPrefixLength({},         {})        == 0);
    test::check("first element matches",    commonPrefixLength({4,5,6},   {4,9,9})   == 1);
    test::check("different lengths — uses shorter",
                                            commonPrefixLength({1,2,3},   {1,2})     == 2);

    test::section("firstDiffChar");
    test::check("differs at index 1",       firstDiffChar("abc", "axc")  == 1);
    test::check("differs at index 0",       firstDiffChar("hello", "world") == 0);
    test::check("identical strings — -1",   firstDiffChar("same", "same") == -1);
    test::check("empty strings — -1",       firstDiffChar("", "")         == -1);
    test::check("differs at last char",     firstDiffChar("cat", "cap")   == 2);
    test::check("one char different",       firstDiffChar("a", "b")       == 0);

    return test::summary();
}
