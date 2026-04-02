// ============================================================
// REVIEW: std::count() and std::count_if()
// ============================================================
// You covered count() and count_if() in Section 1:
//   01_searching/06_count.cpp
//   01_searching/07_count_if.cpp
//
// Here are two short tasks that combine those algorithms with
// the comparing ideas from this section. Revisit Section 1 if
// you need a refresher before attempting these.
//
// Quick syntax reminder:
//   std::count(first, last, value)
//     — counts elements equal to value
//
//   std::count_if(first, last, predicate)
//     — counts elements for which predicate returns true
// ============================================================

#include <algorithm>
#include <vector>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: countMatching
// Given two equal-length vectors<int>, count how many index
// positions have the same value in both vectors.
// Example: {1,5,3,4} vs {1,2,3,9} → 2  (index 0 and index 2)
//
// Hint: use a simple index loop, or capture an index in a
// lambda passed to count_if, or use std::mismatch repeatedly.
// There is no single perfect STL call for this — think about
// what combination works cleanly.
// ------------------------------------------------------------
int countMatching(const std::vector<int>& a, const std::vector<int>& b) {
    // YOUR CODE HERE
    return 0;
}

// ------------------------------------------------------------
// TASK 2: frequencyDominates
// Given two vectors<int> a and b, return true if there exists
// ANY value v such that v appears more times in a than in b.
//
// For each distinct value in a, compare:
//   std::count(a, v)  vs  std::count(b, v)
// If any value has a higher count in a, return true.
// Return false if b has equal-or-higher counts for every value.
//
// Hint: iterate through a, use count() on both vectors, and
// short-circuit as soon as you find a dominant value.
// (Duplicates in a will re-check the same value — that is OK.)
// ------------------------------------------------------------
bool frequencyDominates(const std::vector<int>& a, const std::vector<int>& b) {
    // YOUR CODE HERE
    return false;
}

// ============================================================
int main() {
    std::cout << "=== count() / count_if() review ===\n";

    test::section("countMatching");
    test::check("two positions match",    countMatching({1,5,3,4}, {1,2,3,9})  == 2);
    test::check("all positions match",    countMatching({1,2,3},   {1,2,3})    == 3);
    test::check("no positions match",     countMatching({1,2,3},   {4,5,6})    == 0);
    test::check("empty vectors — 0",      countMatching({},         {})         == 0);
    test::check("single element match",   countMatching({7},        {7})        == 1);

    test::section("frequencyDominates");
    test::check("a has extra 1",          frequencyDominates({1,1,2}, {1,2,3})  == true);
    test::check("b has more of everything",frequencyDominates({1},    {1,1,2})  == false);
    test::check("equal frequencies — false", frequencyDominates({1,2,3}, {3,2,1}) == false);
    test::check("a has unique value",     frequencyDominates({5,5,5}, {1,2,3})  == true);
    test::check("both empty — false",     frequencyDominates({},      {})       == false);

    return test::summary();
}
