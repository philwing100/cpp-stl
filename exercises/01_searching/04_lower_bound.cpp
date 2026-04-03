// ============================================================
// EXERCISE 4: std::lower_bound()
// ============================================================
// std::lower_bound() searches a SORTED range and returns an
// iterator to the FIRST element that is NOT LESS THAN (>=)
// the given value — i.e., the first element >= value.
//
// Syntax:
//   auto it = std::lower_bound(first, last, value);
//
// Example:
//   std::vector<int> v = {10, 20, 20, 30, 40};
//   auto it = std::lower_bound(v.begin(), v.end(), 20);
//   // Points to the FIRST 20 (index 1)
//   auto it2 = std::lower_bound(v.begin(), v.end(), 25);
//   // Points to 30 (first element >= 25, index 3)
//
// If all elements are less than value, returns end().
//
// USE CASES:
//   - Find the insertion point for a value in a sorted sequence
//   - Find the first element >= a threshold
//   - Efficient O(log n) lookup in sorted containers
// ============================================================

#include <algorithm>
#include <vector>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: insertionIndex
// Given a sorted vector and a value, return the index at which
// value should be inserted to keep the vector sorted.
// (If value already exists, return the index of its first
// occurrence — lower_bound does exactly this.)
//
// Use std::lower_bound().
// ------------------------------------------------------------
int insertionIndex(const std::vector<int>& sorted, int value) {
    auto it = std::lower_bound(sorted.begin(), sorted.end(), value);
    return it - sorted.begin();
}

// ------------------------------------------------------------
// TASK 2: countLessThan
// Given a sorted vector, return how many elements are strictly
// less than `value`.
//
// Hint: lower_bound points to the first element >= value,
// so everything before it is < value.
// Use std::lower_bound() and std::distance().
// ------------------------------------------------------------
int countLessThan(const std::vector<int>& sorted, int value) {
    auto it = std::lower_bound(sorted.begin(),sorted.end(), value);
    return it-sorted.begin();
}

// ------------------------------------------------------------
// TASK 3: lowerPrice
// A ticket pricing system stores sorted price tiers.
// Given a budget, return the highest price tier that is
// still AT OR BELOW the budget (i.e., the largest value <= budget).
// Return -1 if the budget is below all tiers.
//
// Hint: lower_bound gives the first element >= budget+1, so
// the element just before it (if it exists) is <= budget.
// ------------------------------------------------------------
int lowerPrice(const std::vector<int>& priceTiers, int budget) {
    if (priceTiers.empty()) return -1;

    //Horribly written problem should just use upperbound.
    auto it = std::upper_bound(priceTiers.begin(), priceTiers.end(), budget);
    if (it == priceTiers.begin()) return -1;
    --it;
    return *it;
}

// ============================================================
int main() {
    std::cout << "=== std::lower_bound() ===\n";

    test::section("insertionIndex");
    test::check("insert before first",    insertionIndex({10,20,30}, 5)  == 0);
    test::check("insert after last",      insertionIndex({10,20,30}, 35) == 3);
    test::check("insert in middle",       insertionIndex({10,20,30}, 25) == 2);
    test::check("value already present",  insertionIndex({10,20,30}, 20) == 1);
    test::check("duplicate — first pos",  insertionIndex({5,10,10,15}, 10) == 1);
    test::check("empty vector",           insertionIndex({}, 5) == 0);

    test::section("countLessThan");
    test::check("none less than min",     countLessThan({1,2,3,4,5}, 1) == 0);
    test::check("all less than max+1",    countLessThan({1,2,3,4,5}, 6) == 5);
    test::check("three less than 4",      countLessThan({1,2,3,4,5}, 4) == 3);
    test::check("empty vector — 0",       countLessThan({}, 5) == 0);
    test::check("duplicates handled",     countLessThan({2,2,2,5}, 3) == 3);

    test::section("lowerPrice");
    test::check("exact match",            lowerPrice({50,100,150,200}, 100) == 100);
    test::check("between tiers",          lowerPrice({50,100,150,200}, 120) == 100);
    test::check("below all tiers — -1",   lowerPrice({50,100,150}, 30)  == -1);
    test::check("above all tiers",        lowerPrice({50,100,150}, 999) == 150);
    test::check("single tier match",      lowerPrice({75}, 75)  == 75);
    test::check("single tier too high",   lowerPrice({75}, 50)  == -1);

    return test::summary();
}
