// ============================================================
// EXERCISE 4: std::is_permutation()
// ============================================================
// std::is_permutation() returns true if one range is a
// rearrangement (permutation) of the other — they contain
// the same elements with the same frequencies, but possibly
// in a different order.
//
// Syntax:
//   std::is_permutation(first1, last1, first2)
//   std::is_permutation(first1, last1, first2, last2)  // C++14
//   std::is_permutation(first1, last1, first2, comparator)
//
// Example:
//   std::vector<int> a = {1, 2, 3};
//   std::vector<int> b = {3, 1, 2};
//   std::is_permutation(a.begin(), a.end(), b.begin()); // true
//
//   std::vector<int> c = {1, 1, 3};
//   std::is_permutation(a.begin(), a.end(), c.begin()); // false (frequencies differ)
//
// KEY DIFFERENCE from std::equal():
//   equal()          → same elements, SAME order   → {1,2,3} vs {1,2,3} only
//   is_permutation() → same elements, ANY order    → {1,2,3} vs {3,2,1} too
// ============================================================

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: isAnagram
// Return true if two strings are anagrams — they contain the
// same characters with the same frequencies, in any order.
// The comparison should be case-sensitive.
//
// Use std::is_permutation() directly on the string iterators.
// ------------------------------------------------------------
bool isAnagram(const std::string& s1, const std::string& s2) {
    // YOUR CODE HERE
    return false;
}

// ------------------------------------------------------------
// TASK 2: sameMultiset
// Return true if two vectors<int> contain the same elements
// with the same frequencies (order does not matter).
//
// Use std::is_permutation().
// ------------------------------------------------------------
bool sameMultiset(const std::vector<int>& a, const std::vector<int>& b) {
    // YOUR CODE HERE
    return false;
}

// ------------------------------------------------------------
// TASK 3: canRearrangeTo
// Given a "source" vector and a "target" vector, return true
// if the source can be rearranged to exactly produce the target
// (i.e., they are permutations of each other).
//
// Use std::is_permutation().
// ------------------------------------------------------------
bool canRearrangeTo(const std::vector<int>& source,
                    const std::vector<int>& target) {
    // YOUR CODE HERE
    return false;
}

// ============================================================
int main() {
    std::cout << "=== std::is_permutation() ===\n";

    test::section("isAnagram");
    test::check("classic anagram",           isAnagram("listen", "silent")   == true);
    test::check("another anagram",           isAnagram("triangle", "integral") == true);
    test::check("not an anagram",            isAnagram("hello", "world")     == false);
    test::check("different lengths — false", isAnagram("abc", "ab")          == false);
    test::check("same string — true",        isAnagram("abc", "abc")         == true);
    test::check("empty strings — true",      isAnagram("", "")               == true);

    test::section("sameMultiset");
    test::check("same elements any order",   sameMultiset({1,2,3}, {3,1,2})   == true);
    test::check("different frequencies",     sameMultiset({1,1,2}, {1,2,2})   == false);
    test::check("identical order — true",    sameMultiset({4,5,6}, {4,5,6})   == true);
    test::check("different values",          sameMultiset({1,2,3}, {1,2,9})   == false);
    test::check("both empty — true",         sameMultiset({}, {})             == true);
    test::check("different lengths — false", sameMultiset({1,2,3}, {1,2})     == false);

    test::section("canRearrangeTo");
    test::check("can rearrange",             canRearrangeTo({3,1,2}, {1,2,3}) == true);
    test::check("cannot rearrange — wrong elements",
                                             canRearrangeTo({1,2,3}, {1,2,4}) == false);
    test::check("cannot rearrange — wrong counts",
                                             canRearrangeTo({1,1,2}, {1,2,2}) == false);
    test::check("single element match",      canRearrangeTo({7}, {7})         == true);
    test::check("single element mismatch",   canRearrangeTo({7}, {8})         == false);
    test::check("empty source and target",   canRearrangeTo({}, {})           == true);

    return test::summary();
}
