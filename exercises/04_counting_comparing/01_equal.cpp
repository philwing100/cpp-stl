// ============================================================
// EXERCISE 1: std::equal()
// ============================================================
// std::equal() returns true if two ranges contain the same
// elements in the same order. A custom comparator can be
// supplied to change how elements are matched.
//
// The second range only needs a starting iterator — it must be
// at least as long as the first range. A four-iterator form
// (C++14) is also available and is safer when lengths may differ.
//
// Syntax:
//   std::equal(first1, last1, first2)
//   std::equal(first1, last1, first2, last2)
//   std::equal(first1, last1, first2, comparator)
//   std::equal(first1, last1, first2, last2, comparator)
//
// Example:
//   std::vector<int> a = {1, 2, 3};
//   std::vector<int> b = {1, 2, 3};
//   std::equal(a.begin(), a.end(), b.begin()); // true
//
//   std::vector<int> c = {1, 2, 9};
//   std::equal(a.begin(), a.end(), c.begin()); // false
//
// KEY IDEA: equal() checks BOTH value AND position. Use
// is_permutation() if order does not matter.
// ============================================================

#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: sameContents
// Return true if two vectors<int> have identical elements in
// the same order, false otherwise.
//
// Use std::equal().
// ------------------------------------------------------------
bool sameContents(const std::vector<int>& a, const std::vector<int>& b) {
    // YOUR CODE HERE
    return false;
}

// ------------------------------------------------------------
// TASK 2: caseInsensitiveEqual
// Return true if two strings are equal ignoring case.
//
// Use std::equal() with a comparator that calls std::tolower
// on each character before comparing.
// ------------------------------------------------------------
bool caseInsensitiveEqual(const std::string& s1, const std::string& s2) {
    // YOUR CODE HERE
    return false;
}

// ------------------------------------------------------------
// TASK 3: hasSamePrefix
// Given two vectors<int> and a length n, return true if their
// first n elements are identical (in the same order).
// You may assume n <= min(a.size(), b.size()).
//
// Use std::equal() on subranges — pass a.begin(), a.begin()+n,
// and b.begin() as iterators.
// ------------------------------------------------------------
bool hasSamePrefix(const std::vector<int>& a,
                   const std::vector<int>& b,
                   int n) {
    // YOUR CODE HERE
    return false;
}

// ============================================================
int main() {
    std::cout << "=== std::equal() ===\n";

    test::section("sameContents");
    test::check("identical vectors",          sameContents({1,2,3}, {1,2,3})     == true);
    test::check("different values",           sameContents({1,2,3}, {1,2,9})     == false);
    test::check("different lengths — false",  sameContents({1,2,3}, {1,2})       == false);
    test::check("both empty — true",          sameContents({}, {})               == true);
    test::check("same values, wrong order",   sameContents({1,2,3}, {3,2,1})     == false);
    test::check("single element match",       sameContents({42}, {42})           == true);

    test::section("caseInsensitiveEqual");
    test::check("exact same string",          caseInsensitiveEqual("hello", "hello")   == true);
    test::check("mixed case — equal",         caseInsensitiveEqual("Hello", "hELLO")   == true);
    test::check("all caps vs lower",          caseInsensitiveEqual("WORLD", "world")   == true);
    test::check("different content",          caseInsensitiveEqual("abc", "xyz")       == false);
    test::check("different length — false",   caseInsensitiveEqual("hi", "high")       == false);
    test::check("empty strings — true",       caseInsensitiveEqual("", "")             == true);

    test::section("hasSamePrefix");
    test::check("prefix matches",             hasSamePrefix({1,2,3,4}, {1,2,9,9}, 2) == true);
    test::check("full length matches",        hasSamePrefix({1,2,3},   {1,2,3},   3) == true);
    test::check("prefix differs",             hasSamePrefix({1,2,3},   {1,9,3},   2) == false);
    test::check("n=0 — always true",          hasSamePrefix({5,6,7},   {1,2,3},   0) == true);
    test::check("n=1 — first elements equal", hasSamePrefix({7,8,9},   {7,1,2},   1) == true);
    test::check("n=1 — first elements differ",hasSamePrefix({7,8,9},   {6,8,9},   1) == false);

    return test::summary();
}
