// ============================================================
// EXERCISE 5: std::is_sorted() and std::is_sorted_until()
// ============================================================
// std::is_sorted() checks whether an entire range is sorted
// in non-descending order (or by a custom comparator).
//
// std::is_sorted_until() returns an iterator to the FIRST
// element that breaks the sorted order. If the range is fully
// sorted, it returns the end iterator.
//
// Syntax:
//   bool ok  = std::is_sorted(first, last);
//   bool ok  = std::is_sorted(first, last, comparator);
//   auto it  = std::is_sorted_until(first, last);
//   auto it  = std::is_sorted_until(first, last, comparator);
//
// Example:
//   std::vector<int> v = {1, 3, 2, 4};
//   std::is_sorted(v.begin(), v.end());          // false
//   auto it = std::is_sorted_until(v.begin(), v.end());
//   // *it == 2  (first element out of order)
//   // std::distance(v.begin(), it) == 2  → sorted prefix length is 2
//
// KEY IDEAS:
//   - is_sorted returns true for empty and single-element ranges.
//   - is_sorted_until returns end() for a fully sorted range.
//   - Combine is_sorted_until in a loop to count sorted segments.
//   - Both accept a custom comparator, so you can check
//     descending order too.
// ============================================================

#include <algorithm>
#include <vector>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: checkSorted
// Return true if the vector is sorted in non-descending
// (ascending) order, false otherwise.
//
// Use std::is_sorted().
// ------------------------------------------------------------
bool checkSorted(const std::vector<int>& vec) {
    // YOUR CODE HERE
    return false;
}

// ------------------------------------------------------------
// TASK 2: sortedPrefix
// Return the LENGTH of the longest sorted (non-descending)
// prefix of the vector.
// For example: {1,3,5,2,4} → prefix {1,3,5} → length 3.
//
// Use std::is_sorted_until() and std::distance().
// ------------------------------------------------------------
int sortedPrefix(const std::vector<int>& vec) {
    // YOUR CODE HERE
    return 0;
}

// ------------------------------------------------------------
// TASK 3: howManySortedSegments
// Count how many contiguous sorted (non-descending) segments
// the vector contains.
// Example: {1,3,2,4,6,5,7} → {1,3}, {2,4,6}, {5,7} → 3
// Example: {1,2,3}         → {1,2,3}          → 1
// Example: {}              → 0
//
// Strategy: walk through the vector using is_sorted_until
// repeatedly. Each call finds the end of the current sorted
// segment; advance the start to that point and count.
// ------------------------------------------------------------
int howManySortedSegments(const std::vector<int>& vec) {
    // YOUR CODE HERE
    return 0;
}

// ============================================================
int main() {
    std::cout << "=== std::is_sorted() and std::is_sorted_until() ===\n";

    test::section("checkSorted");
    test::check("sorted ascending",       checkSorted({1,2,3,4,5})  == true);
    test::check("not sorted",             checkSorted({1,3,2,4,5})  == false);
    test::check("single element",         checkSorted({7})           == true);
    test::check("empty vector",           checkSorted({})            == true);
    test::check("all equal (non-desc)",   checkSorted({4,4,4,4})    == true);
    test::check("descending is false",    checkSorted({5,4,3,2,1})  == false);

    test::section("sortedPrefix");
    test::check("prefix of 3",            sortedPrefix({1,3,5,2,4})   == 3);
    test::check("fully sorted",           sortedPrefix({1,2,3,4,5})   == 5);
    test::check("no sorted prefix >1",    sortedPrefix({5,4,3,2,1})   == 1);
    test::check("single element",         sortedPrefix({9})            == 1);
    test::check("empty vector",           sortedPrefix({})             == 0);
    test::check("break at second element",sortedPrefix({3,1,2,4,5})   == 1);

    test::section("howManySortedSegments");
    test::check("3 segments",             howManySortedSegments({1,3,2,4,6,5,7})  == 3);
    test::check("fully sorted — 1",       howManySortedSegments({1,2,3,4,5})      == 1);
    test::check("all descending",         howManySortedSegments({5,4,3,2,1})      == 5);
    test::check("2 segments",             howManySortedSegments({1,2,5,3,4})      == 2);
    test::check("single element — 1",     howManySortedSegments({42})             == 1);
    test::check("empty vector — 0",       howManySortedSegments({})               == 0);

    return test::summary();
}
