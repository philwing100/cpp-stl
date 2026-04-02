// ============================================================
// EXERCISE 1: std::sort()
// ============================================================
// std::sort() rearranges elements in a range into ascending
// order by default (using operator<). You can pass a custom
// comparator to sort in any order you like.
//
// Syntax:
//   std::sort(first, last);
//   std::sort(first, last, comparator);
//
// Example:
//   std::vector<int> v = {3, 1, 4, 1, 5};
//   std::sort(v.begin(), v.end());
//   // v is now {1, 1, 3, 4, 5}
//
//   std::sort(v.begin(), v.end(), [](int a, int b){ return a > b; });
//   // v is now {5, 4, 3, 1, 1}
//
// KEY IDEAS:
//   - std::sort() is NOT stable — equal elements may be reordered.
//   - Average complexity: O(n log n).
//   - The comparator must be a strict weak ordering:
//     comp(a, b) returns true if a should come BEFORE b.
//   - To sort descending, use std::greater<T>{} or a lambda
//     returning a > b.
// ============================================================

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: sortAscending
// Given a vector of ints, sort it in ascending order and
// return the sorted vector.
//
// Use std::sort() with no comparator (default ascending).
// ------------------------------------------------------------
std::vector<int> sortAscending(std::vector<int> vec) {
    // YOUR CODE HERE
    return vec;
}

// ------------------------------------------------------------
// TASK 2: sortDescending
// Given a vector of ints, sort it in descending order and
// return the sorted vector.
//
// Use std::sort() with a comparator lambda that returns a > b.
// ------------------------------------------------------------
std::vector<int> sortDescending(std::vector<int> vec) {
    // YOUR CODE HERE
    return vec;
}

// ------------------------------------------------------------
// TASK 3: sortByLength
// Given a vector of strings, sort it so that shorter strings
// come first. Ties (equal length) may remain in any order.
// Return the sorted vector.
//
// Use std::sort() with a comparator lambda that compares
// string lengths.
// ------------------------------------------------------------
std::vector<std::string> sortByLength(std::vector<std::string> vec) {
    // YOUR CODE HERE
    return vec;
}

// ============================================================
int main() {
    std::cout << "=== std::sort() ===\n";

    test::section("sortAscending");
    test::check("already sorted",          sortAscending({1,2,3,4,5})    == std::vector<int>({1,2,3,4,5}));
    test::check("reverse order",           sortAscending({5,4,3,2,1})    == std::vector<int>({1,2,3,4,5}));
    test::check("mixed order",             sortAscending({3,1,4,1,5,9})  == std::vector<int>({1,1,3,4,5,9}));
    test::check("single element",          sortAscending({42})            == std::vector<int>({42}));
    test::check("empty vector",            sortAscending({})              == std::vector<int>({}));
    test::check("duplicates sorted",       sortAscending({2,2,1,1,3,3})  == std::vector<int>({1,1,2,2,3,3}));

    test::section("sortDescending");
    test::check("already descending",      sortDescending({5,4,3,2,1})   == std::vector<int>({5,4,3,2,1}));
    test::check("ascending input",         sortDescending({1,2,3,4,5})   == std::vector<int>({5,4,3,2,1}));
    test::check("mixed order",             sortDescending({3,1,4,1,5,9}) == std::vector<int>({9,5,4,3,1,1}));
    test::check("single element",          sortDescending({7})            == std::vector<int>({7}));
    test::check("empty vector",            sortDescending({})             == std::vector<int>({}));
    test::check("all equal",               sortDescending({4,4,4})        == std::vector<int>({4,4,4}));

    test::section("sortByLength");
    std::vector<std::string> r1 = sortByLength({"banana","fig","kiwi","plum"});
    test::check("shortest first",          r1[0] == "fig");
    test::check("longest last",            r1.back() == "banana");

    std::vector<std::string> r2 = sortByLength({"hi","bye","ok","no"});
    test::check("two-char strings first",  r2[0].size() == 2 && r2[1].size() == 2);
    test::check("three-char string last",  r2.back().size() == 3);

    test::check("single element",          sortByLength({"hello"}) == std::vector<std::string>({"hello"}));
    test::check("empty vector",            sortByLength({}) == std::vector<std::string>({}));

    return test::summary();
}
