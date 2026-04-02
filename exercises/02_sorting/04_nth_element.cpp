// ============================================================
// EXERCISE 4: std::nth_element()
// ============================================================
// std::nth_element() partially rearranges a range so that:
//   - The element at position `nth` is the element that WOULD
//     be there if the range were fully sorted.
//   - All elements BEFORE `nth` are <= *nth.
//   - All elements AFTER  `nth` are >= *nth.
//   - Neither partition is sorted internally.
//
// Syntax:
//   std::nth_element(first, nth, last);
//   std::nth_element(first, nth, last, comparator);
//
// Example:
//   std::vector<int> v = {5, 2, 8, 1, 9, 3};
//   std::nth_element(v.begin(), v.begin() + 2, v.end());
//   // v[2] == 3  (3rd smallest — index 2 in 0-based sorted order)
//   // Elements before index 2 are each <= 3
//   // Elements after  index 2 are each >= 3
//   // (internal order of those groups is unspecified)
//
// KEY IDEAS:
//   - O(n) average complexity — much faster than a full sort
//     when you only need one order-statistic value.
//   - Classic use cases: median, kth smallest/largest,
//     splitting a dataset around a pivot.
//   - Use on a COPY when you must preserve the original.
// ============================================================

#include <algorithm>
#include <vector>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: medianValue
// Given a vector of ints with ODD length, return the median.
// The median is the element at index size/2 in sorted order.
//
// Work on a copy. Use std::nth_element() at position size/2.
// ------------------------------------------------------------
int medianValue(std::vector<int> vec) {
    // YOUR CODE HERE
    return 0;
}

// ------------------------------------------------------------
// TASK 2: kthSmallest
// Given a vector of ints and k (1-indexed), return the kth
// smallest value. For example, kthSmallest({3,1,4,1,5}, 2)
// should return 1 (the 2nd smallest is 1).
//
// Work on a copy. Use std::nth_element() at position k-1.
// ------------------------------------------------------------
int kthSmallest(std::vector<int> vec, int k) {
    // YOUR CODE HERE
    return 0;
}

// ------------------------------------------------------------
// TASK 3: partitionAround
// Given a vector and a pivotIndex, use std::nth_element() to
// rearrange the copy so that the element at pivotIndex is the
// value it would have in a sorted array. Return that value
// (the "pivot value").
//
// Work on a copy. Call nth_element at pivotIndex and return
// copy[pivotIndex].
// ------------------------------------------------------------
int partitionAround(std::vector<int> vec, int pivotIndex) {
    // YOUR CODE HERE
    return 0;
}

// ============================================================
int main() {
    std::cout << "=== std::nth_element() ===\n";

    test::section("medianValue");
    test::check("median of 5 elements",    medianValue({3,1,4,1,5})     == 3);
    test::check("median of 3 elements",    medianValue({7,2,9})          == 7);
    test::check("already sorted — median", medianValue({1,2,3,4,5})     == 3);
    test::check("reverse sorted — median", medianValue({5,4,3,2,1})     == 3);
    test::check("single element",          medianValue({42})             == 42);
    test::check("duplicates — median",     medianValue({2,2,2,2,2})     == 2);

    test::section("kthSmallest");
    test::check("1st smallest (minimum)",  kthSmallest({3,1,4,1,5,9}, 1) == 1);
    test::check("2nd smallest",            kthSmallest({3,1,4,1,5,9}, 2) == 1);
    test::check("3rd smallest",            kthSmallest({3,1,4,1,5,9}, 3) == 3);
    test::check("last (maximum)",          kthSmallest({3,1,4,1,5,9}, 6) == 9);
    test::check("single element k=1",      kthSmallest({7}, 1)           == 7);
    test::check("two elements — smaller",  kthSmallest({8,3}, 1)         == 3);

    test::section("partitionAround");
    // In sorted order {1,2,3,4,5,6}, pivotIndex 0 => 1, 2 => 3, 5 => 6
    test::check("pivot at index 0 => min",  partitionAround({4,2,6,1,5,3}, 0) == 1);
    test::check("pivot at index 2 => 3rd",  partitionAround({4,2,6,1,5,3}, 2) == 3);
    test::check("pivot at index 5 => max",  partitionAround({4,2,6,1,5,3}, 5) == 6);
    test::check("single element",           partitionAround({99}, 0)           == 99);
    test::check("two elements — first",     partitionAround({7,3}, 0)          == 3);
    test::check("two elements — second",    partitionAround({7,3}, 1)          == 7);

    return test::summary();
}
