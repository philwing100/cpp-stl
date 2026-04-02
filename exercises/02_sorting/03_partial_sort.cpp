// ============================================================
// EXERCISE 3: std::partial_sort()
// ============================================================
// std::partial_sort() rearranges the range [first, last) so
// that the smallest (N = middle - first) elements are in
// sorted order in [first, middle). Elements in [middle, last)
// are in an unspecified order.
//
// Syntax:
//   std::partial_sort(first, middle, last);
//   std::partial_sort(first, middle, last, comparator);
//
// Example:
//   std::vector<int> v = {5, 2, 8, 1, 9, 3};
//   std::partial_sort(v.begin(), v.begin() + 3, v.end());
//   // First 3 elements are sorted: {1, 2, 3, ...}
//   // Remaining elements are unspecified (some permutation of 5,8,9)
//
// KEY IDEAS:
//   - Use partial_sort when you only need the top/bottom N
//     elements and don't care about the rest.
//   - More efficient than a full sort when N << size:
//     O(n log N) instead of O(n log n).
//   - Pass a reverse comparator (a > b) to get the N LARGEST
//     elements in descending order.
// ============================================================

#include <algorithm>
#include <vector>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: topN
// Given a vector of ints and a count N, return a new vector
// containing the N smallest elements IN SORTED (ascending)
// order.
//
// Work on a copy so the original is unchanged.
// Use std::partial_sort() on the copy, then return only the
// first N elements.
// ------------------------------------------------------------
std::vector<int> topN(std::vector<int> vec, int n) {
    // YOUR CODE HERE
    return {};
}

// ------------------------------------------------------------
// TASK 2: bottomNMax
// Given a vector of ints and a count N, return a new vector
// containing the N LARGEST elements in DESCENDING order.
//
// Use std::partial_sort() with a comparator lambda (a > b)
// on a copy, then return only the first N elements.
// ------------------------------------------------------------
std::vector<int> bottomNMax(std::vector<int> vec, int n) {
    // YOUR CODE HERE
    return {};
}

// ------------------------------------------------------------
// TASK 3: isTopNSorted
// Given a vector of ints and a count N, return true if and
// only if the first N elements of vec are sorted ascending AND
// every element at index < N is <= every element at index >= N.
//
// In other words: would partial_sort produce a result equal to
// what vec already shows?
//
// Strategy: make a copy, run partial_sort on the copy, then
// compare the first N elements of the copy with the first N
// elements of the original vec.
// ------------------------------------------------------------
bool isTopNSorted(std::vector<int> vec, int n) {
    // YOUR CODE HERE
    return false;
}

// ============================================================
int main() {
    std::cout << "=== std::partial_sort() ===\n";

    test::section("topN");
    test::check("3 smallest of 6",       topN({5,2,8,1,9,3}, 3) == std::vector<int>({1,2,3}));
    test::check("1 smallest",            topN({7,4,2,9}, 1)     == std::vector<int>({2}));
    test::check("all elements (N==size)",topN({3,1,2}, 3)        == std::vector<int>({1,2,3}));
    test::check("duplicates included",   topN({4,4,1,2,4}, 3)   == std::vector<int>({1,2,4}));
    test::check("already sorted input",  topN({1,2,3,4,5}, 2)   == std::vector<int>({1,2}));
    test::check("N == 0 returns empty",  topN({1,2,3}, 0)        == std::vector<int>({}));

    test::section("bottomNMax");
    test::check("3 largest of 6",        bottomNMax({5,2,8,1,9,3}, 3) == std::vector<int>({9,8,5}));
    test::check("1 largest",             bottomNMax({7,4,2,9}, 1)     == std::vector<int>({9}));
    test::check("all elements (N==size)",bottomNMax({3,1,2}, 3)        == std::vector<int>({3,2,1}));
    test::check("duplicates included",   bottomNMax({4,4,1,2,4}, 3)   == std::vector<int>({4,4,4}));
    test::check("already sorted input",  bottomNMax({1,2,3,4,5}, 2)   == std::vector<int>({5,4}));
    test::check("N == 0 returns empty",  bottomNMax({1,2,3}, 0)        == std::vector<int>({}));

    test::section("isTopNSorted");
    test::check("correctly sorted prefix",    isTopNSorted({1,2,3,9,7,8}, 3) == true);
    test::check("prefix sorted but too large",isTopNSorted({1,2,9,3,7,8}, 3) == false);
    test::check("prefix unsorted",            isTopNSorted({2,1,3,4,5,6}, 2) == false);
    test::check("N == 1 always ok",           isTopNSorted({1,5,3,7}, 1)     == true);
    test::check("full sort equals partial",   isTopNSorted({1,2,3}, 3)       == true);
    test::check("N == 0 always true",         isTopNSorted({3,1,2}, 0)       == true);

    return test::summary();
}
