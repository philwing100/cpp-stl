// ============================================================
// EXERCISE 6: std::remove() and std::unique()
// ============================================================
// std::remove(first, last, value)
//   Moves all elements NOT equal to `value` to the front of
//   the range, preserving relative order. Returns an iterator
//   to the new logical end. The elements after that iterator
//   are left in a valid-but-unspecified state.
//   The container is NOT resized — you must call erase() after.
//
// std::unique(first, last)
//   Removes CONSECUTIVE duplicates (similar spirit to remove).
//   Returns an iterator to the new logical end. Typically used
//   after sorting to deduplicate a container.
//
// Syntax:
//   auto new_end = std::remove(v.begin(), v.end(), value);
//   v.erase(new_end, v.end());
//
//   std::sort(v.begin(), v.end());
//   auto new_end = std::unique(v.begin(), v.end());
//   v.erase(new_end, v.end());
//
// Example:
//   std::vector<int> v = {1, 2, 3, 2, 4};
//   auto it = std::remove(v.begin(), v.end(), 2);
//   v.erase(it, v.end());
//   // v == {1, 3, 4}
//
// KEY IDEA: std::remove does NOT actually delete elements from
// the container. Always follow it with vec.erase(it, vec.end())
// to truly shrink the vector — this is the "erase-remove idiom".
// ============================================================

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: removeValue
// Given a vector<int> and a target value, remove all
// occurrences of that value and return the cleaned vector.
//
// Use the erase-remove idiom:
//   v.erase(std::remove(...), v.end());
// ------------------------------------------------------------
std::vector<int> removeValue(std::vector<int> v, int value) {
    // YOUR CODE HERE
    return v;
}

// ------------------------------------------------------------
// TASK 2: removeZeros
// Given a vector<int>, remove all zeros and return the result.
//
// Use the erase-remove idiom.
// ------------------------------------------------------------
std::vector<int> removeZeros(std::vector<int> v) {
    // YOUR CODE HERE
    return v;
}

// ------------------------------------------------------------
// TASK 3: removeDuplicates
// Given a SORTED vector<int>, remove consecutive duplicates
// so that each value appears exactly once. Return the result.
//
// Use std::unique + erase (the canonical sorted-deduplication
// idiom). std::unique is analogous to std::remove but targets
// consecutive equal elements rather than a fixed value.
// ------------------------------------------------------------
std::vector<int> removeDuplicates(std::vector<int> v) {
    // YOUR CODE HERE
    return v;
}

// ============================================================
int main() {
    std::cout << "=== std::remove() ===\n";

    test::section("removeValue");
    test::check("remove middle value",    removeValue({1,2,3,2,4}, 2)     == std::vector<int>({1,3,4}));
    test::check("remove first element",   removeValue({5,1,2,3}, 5)       == std::vector<int>({1,2,3}));
    test::check("remove last element",    removeValue({1,2,3,9}, 9)       == std::vector<int>({1,2,3}));
    test::check("value not present",      removeValue({1,2,3}, 7)         == std::vector<int>({1,2,3}));
    test::check("remove all occurrences", removeValue({4,4,4,4}, 4)       == std::vector<int>({}));
    test::check("empty vector",           removeValue({}, 1)              == std::vector<int>({}));

    test::section("removeZeros");
    test::check("mixed zeros",            removeZeros({1,0,2,0,3})        == std::vector<int>({1,2,3}));
    test::check("leading zeros",          removeZeros({0,0,1,2})          == std::vector<int>({1,2}));
    test::check("trailing zeros",         removeZeros({3,4,0,0})          == std::vector<int>({3,4}));
    test::check("no zeros",               removeZeros({1,2,3})            == std::vector<int>({1,2,3}));
    test::check("all zeros",              removeZeros({0,0,0})            == std::vector<int>({}));
    test::check("empty input",            removeZeros({})                 == std::vector<int>({}));

    test::section("removeDuplicates");
    test::check("consecutive dupes",      removeDuplicates({1,1,2,3,3,3,4}) == std::vector<int>({1,2,3,4}));
    test::check("no duplicates",          removeDuplicates({1,2,3,4,5})     == std::vector<int>({1,2,3,4,5}));
    test::check("all same",               removeDuplicates({7,7,7,7})       == std::vector<int>({7}));
    test::check("empty input",            removeDuplicates({})              == std::vector<int>({}));
    test::check("single element",         removeDuplicates({3})             == std::vector<int>({3}));
    test::check("two distinct values",    removeDuplicates({1,1,2,2})       == std::vector<int>({1,2}));

    return test::summary();
}
