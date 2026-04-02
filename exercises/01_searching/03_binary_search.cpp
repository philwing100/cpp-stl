// ============================================================
// EXERCISE 3: std::binary_search()
// ============================================================
// std::binary_search() checks whether a value exists in a
// SORTED range. It returns true if found, false otherwise.
//
// Syntax:
//   bool found = std::binary_search(first, last, value);
//
// Example:
//   std::vector<int> v = {1, 3, 5, 7, 9};   // must be sorted!
//   std::binary_search(v.begin(), v.end(), 5); // true
//   std::binary_search(v.begin(), v.end(), 4); // false
//
// CRITICAL: The range MUST be sorted (ascending by default,
// or by the same comparator you pass in). Calling binary_search
// on an unsorted range gives undefined behaviour.
//
// WHY USE IT over std::find()?
//   find() is O(n) — it checks every element.
//   binary_search() is O(log n) — far faster for large sorted data.
// ============================================================

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: inStock
// A sorted list of product IDs represents the warehouse
// inventory. Return true if productId is in stock.
//
// Use std::binary_search(). The vector is guaranteed sorted.
// ------------------------------------------------------------
bool inStock(const std::vector<int>& sortedIds, int productId) {
    // YOUR CODE HERE
    return false;
}

// ------------------------------------------------------------
// TASK 2: allPresent
// Given a sorted master list and a smaller list of items to
// check, return true ONLY IF every item in `items` is present
// in `sortedMaster`.
//
// Use std::binary_search() inside a loop.
// ------------------------------------------------------------
bool allPresent(const std::vector<int>& sortedMaster,
                const std::vector<int>& items) {
    // YOUR CODE HERE
    return false;
}

// ------------------------------------------------------------
// TASK 3: hasWordCaseInsensitive
// Given a sorted (case-insensitive order) vector of lowercase
// words, return true if `word` (already lowercase) is present.
// Use std::binary_search() — it already works here since the
// vector contains lowercase words and word is also lowercase.
// ------------------------------------------------------------
bool hasWord(const std::vector<std::string>& sortedWords,
             const std::string& word) {
    // YOUR CODE HERE
    return false;
}

// ============================================================
int main() {
    std::cout << "=== std::binary_search() ===\n";

    test::section("inStock");
    test::check("product found",             inStock({101,203,305,407,509}, 305) == true);
    test::check("product at start",          inStock({101,203,305}, 101) == true);
    test::check("product at end",            inStock({101,203,305}, 305) == true);
    test::check("product not found",         inStock({101,203,305,407}, 200) == false);
    test::check("empty inventory — false",   inStock({}, 1) == false);
    test::check("single element match",      inStock({42}, 42) == true);
    test::check("single element no match",   inStock({42}, 43) == false);

    test::section("allPresent");
    test::check("all present",              allPresent({1,2,3,4,5}, {2,4}) == true);
    test::check("one missing",              allPresent({1,2,4,5}, {2,3}) == false);
    test::check("empty items — true",       allPresent({1,2,3}, {}) == true);
    test::check("empty master — false",     allPresent({}, {1}) == false);
    test::check("both empty — true",        allPresent({}, {}) == true);
    test::check("single item present",      allPresent({5,10,15}, {10}) == true);

    test::section("hasWord");
    test::check("word present",             hasWord({"apple","banana","cherry"}, "banana") == true);
    test::check("word at start",            hasWord({"apple","banana","cherry"}, "apple")  == true);
    test::check("word at end",              hasWord({"apple","banana","cherry"}, "cherry") == true);
    test::check("word absent",              hasWord({"apple","banana","cherry"}, "grape")  == false);
    test::check("empty list — false",       hasWord({}, "apple") == false);

    return test::summary();
}
