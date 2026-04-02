// ============================================================
// EXERCISE 5: std::upper_bound()
// ============================================================
// std::upper_bound() searches a SORTED range and returns an
// iterator to the FIRST element that is GREATER THAN (>)
// the given value.
//
// Syntax:
//   auto it = std::upper_bound(first, last, value);
//
// Example:
//   std::vector<int> v = {10, 20, 20, 30, 40};
//   auto it = std::upper_bound(v.begin(), v.end(), 20);
//   // Points to 30 (first element strictly > 20, index 3)
//
// LOWER vs UPPER BOUND:
//   lower_bound(v, x) → first element >= x
//   upper_bound(v, x) → first element >  x
//
//   Together they define the range of equal elements:
//   [lower_bound(x), upper_bound(x))
//   This is exactly what std::equal_range() returns!
//
// USE CASES:
//   - Count duplicates: upper_bound(x) - lower_bound(x)
//   - Find the last element <= x (the element before upper_bound)
//   - Determine insertion point AFTER existing copies
// ============================================================

#include <algorithm>
#include <vector>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: countInRange
// Given a sorted vector, count how many elements fall in the
// inclusive range [lo, hi].
//
// Hint: upper_bound(hi) - lower_bound(lo) gives the count.
// ------------------------------------------------------------
int countInRange(const std::vector<int>& sorted, int lo, int hi) {
    // YOUR CODE HERE
    return 0;
}

// ------------------------------------------------------------
// TASK 2: countDuplicates
// Given a sorted vector and a value, return how many times
// that value appears.
//
// Hint: upper_bound(x) - lower_bound(x) counts occurrences.
// ------------------------------------------------------------
int countDuplicates(const std::vector<int>& sorted, int value) {
    // YOUR CODE HERE
    return 0;
}

// ------------------------------------------------------------
// TASK 3: nextAvailableSlot
// A sorted list of already-taken seat numbers is given.
// After inserting a new reservation for `seat`, you want the
// seat number that comes IMMEDIATELY AFTER `seat` in the list
// (i.e., the first taken seat strictly greater than `seat`).
// Return -1 if no such seat exists.
//
// Use std::upper_bound().
// ------------------------------------------------------------
int nextTakenSeat(const std::vector<int>& takenSeats, int seat) {
    // YOUR CODE HERE
    return -1;
}

// ============================================================
int main() {
    std::cout << "=== std::upper_bound() ===\n";

    test::section("countInRange");
    test::check("full range",             countInRange({1,2,3,4,5}, 1, 5) == 5);
    test::check("partial range",          countInRange({1,2,3,4,5}, 2, 4) == 3);
    test::check("single value range",     countInRange({1,2,3,4,5}, 3, 3) == 1);
    test::check("range with no matches",  countInRange({1,2,5,6}, 3, 4)   == 0);
    test::check("duplicates in range",    countInRange({1,2,2,2,3}, 2, 2) == 3);
    test::check("empty vector — 0",       countInRange({}, 1, 5)          == 0);

    test::section("countDuplicates");
    test::check("three copies",           countDuplicates({1,2,2,2,3}, 2) == 3);
    test::check("one copy",               countDuplicates({1,2,3}, 2)     == 1);
    test::check("not present — 0",        countDuplicates({1,3,5}, 2)     == 0);
    test::check("all same value",         countDuplicates({4,4,4,4}, 4)   == 4);
    test::check("empty vector — 0",       countDuplicates({}, 5)          == 0);

    test::section("nextTakenSeat");
    test::check("next seat in middle",    nextTakenSeat({2,5,8,11}, 5)  == 8);
    test::check("seat before first taken",nextTakenSeat({2,5,8,11}, 1)  == 2);
    test::check("seat is last — -1",      nextTakenSeat({2,5,8,11}, 11) == -1);
    test::check("seat after all — -1",    nextTakenSeat({2,5,8}, 99)    == -1);
    test::check("empty list — -1",        nextTakenSeat({}, 5)           == -1);
    test::check("exact match seat",       nextTakenSeat({3,7,12}, 3)    == 7);

    return test::summary();
}
