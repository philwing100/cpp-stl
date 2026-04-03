// ============================================================
// EXERCISE 7: std::count_if()
// ============================================================
// std::count_if() counts how many elements in a range satisfy
// a predicate (a function that returns true/false).
//
// Syntax:
//   auto n = std::count_if(first, last, predicate);
//
// Example:
//   std::vector<int> v = {1, 2, 3, 4, 5, 6};
//   auto evens = std::count_if(v.begin(), v.end(),
//                              [](int x){ return x % 2 == 0; });
//   // evens == 3
//
// count_if vs count:
//   count()    → equality check  (one fixed value)
//   count_if() → any condition   (much more flexible)
//
// You can pass any callable as the predicate:
//   - Lambda:           [](int x){ return x > 0; }
//   - Function pointer: bool isPositive(int x) { return x > 0; }
//   - std::function, functor, etc.
// ============================================================

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: countPassing
// Given a list of exam scores (0–100) and a passing threshold,
// return how many students passed (score >= threshold).
//
// Use std::count_if().
// ------------------------------------------------------------
int countPassing(const std::vector<int>& scores, int threshold) {
    
    return std::count_if(scores.begin(),scores.end(), [threshold](int x) {return x >= threshold; });
}

// ------------------------------------------------------------
// TASK 2: countShortWords
// Given a list of words, count how many have length <= maxLen.
//
// Use std::count_if().
// ------------------------------------------------------------
int countShortWords(const std::vector<std::string>& words, int maxLen) {
   return std::count_if(words.begin(),words.end(), [maxLen](std::string str){return str.size() <= maxLen;});
}

// ------------------------------------------------------------
// TASK 3: countInBand
// Given a list of integers, count how many values fall in the
// inclusive range [lo, hi].
//
// Use std::count_if() with a lambda that captures lo and hi.
// ------------------------------------------------------------
int countInBand(const std::vector<int>& vec, int lo, int hi) {
    return std::count_if(vec.begin(),vec.end(), [lo, hi](int x){ return ((hi>= x) &&   (x>= lo)) ? true : false;});
}

// ============================================================
int main() {
    std::cout << "=== std::count_if() ===\n";

    test::section("countPassing");
    test::check("some passing",          countPassing({55,60,72,80,40}, 60) == 3);
    test::check("all passing",           countPassing({70,80,90}, 60)        == 3);
    test::check("none passing",          countPassing({30,40,50}, 60)        == 0);
    test::check("threshold is 0",        countPassing({0,1,2}, 0)            == 3);
    test::check("empty list — 0",        countPassing({}, 60)                == 0);
    test::check("exact threshold counts",countPassing({60,59,61}, 60)        == 2);

    test::section("countShortWords");
    test::check("mixed lengths",        countShortWords({"hi","hello","hey","world"}, 3) == 2);
    test::check("all short",            countShortWords({"a","bb","ccc"}, 5)             == 3);
    test::check("none short",           countShortWords({"hello","world"}, 2)            == 0);
    test::check("empty list — 0",       countShortWords({}, 3)                           == 0);
    test::check("exact length counts",  countShortWords({"abc","abcd"}, 3)               == 1);

    test::section("countInBand");
    test::check("three in band",        countInBand({1,3,5,7,9}, 3, 7)  == 3);
    test::check("all in band",          countInBand({2,3,4}, 1, 10)     == 3);
    test::check("none in band",         countInBand({1,2,3}, 10, 20)    == 0);
    test::check("single value band",    countInBand({1,5,10}, 5, 5)     == 1);
    test::check("negative range",       countInBand({-5,-3,-1,0,2}, -4, -1) == 2);
    test::check("empty — 0",            countInBand({}, 0, 100)         == 0);

    return test::summary();
}
