// ============================================================
// EXERCISE 1: std::find()
// ============================================================
// std::find() searches a range for a value and returns an
// iterator to the FIRST match. If no match is found, it
// returns the end iterator.
//
// Syntax:
//   auto it = std::find(first, last, value);
//
// Example:
//   std::vector<int> v = {10, 20, 30, 40};
//   auto it = std::find(v.begin(), v.end(), 30);
//   // *it == 30,  std::distance(v.begin(), it) == 2
//
// KEY IDEA: Compare the returned iterator to v.end() to
// check if the element was actually found.
// ============================================================

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: findIndex
// Given a vector of integers and a target value, return the
// 0-based index of the FIRST occurrence of target.
// Return -1 if target is not present.
//
// Use std::find() — do not write a manual loop.
// ------------------------------------------------------------
int findIndex(const std::vector<int>& vec, int target) {
    auto it = std::find(vec.begin(), vec.end(), target);
    if(it == vec.end()){
        return -1;
    }else{
        return it-vec.begin();
    }
}

// ------------------------------------------------------------
// TASK 2: containsWord
// Given a vector of strings and a word, return true if the
// word appears anywhere in the vector, false otherwise.
//
// Use std::find().
// ------------------------------------------------------------
bool containsWord(const std::vector<std::string>& words, const std::string& word) {
    if(std::find(words.begin(), words.end(), word) != words.end()){
        return true;
    }

    return false;
}

// ------------------------------------------------------------
// TASK 3: firstAfter
// Given a vector of ints and a target, return the element
// that comes IMMEDIATELY AFTER the first occurrence of target.
// If target is not found or is the last element, return -1.
//
// Use std::find().
// ------------------------------------------------------------
int firstAfter(const std::vector<int>& vec, int target) {
        auto it = std::find(vec.begin(), vec.end(), target);
    if(it == vec.end() || (it - vec.begin()) + 1 >= vec.size() || std::next(it) == vec.end()){
        return -1;
    }else{
        return vec[(it-vec.begin())+1];
    }
}//lesson learned was that std::next(iterator) will return the next element vruhhh

//These also exist

/*
int firstAfter(const std::vector<int>& vec, int target) {
    const int* begin = vec.data();
    const int* end = begin + vec.size();

    for (const int* p = begin; p != end; ++p) {
        if (*p == target) {
            if (p + 1 == end) return -1;
            return *(p + 1);
        }
    }
    return -1;
}
*/

// ============================================================
int main() {
    std::cout << "=== std::find() ===\n";

    test::section("findIndex");
    test::check("finds at start",          findIndex({1,2,3,4,5}, 1) == 0);
    test::check("finds in middle",         findIndex({1,2,3,4,5}, 3) == 2);
    test::check("finds at end",            findIndex({1,2,3,4,5}, 5) == 4);
    test::check("not found returns -1",    findIndex({1,2,3,4,5}, 9) == -1);
    test::check("empty vector returns -1", findIndex({}, 7) == -1);
    test::check("first of duplicates",     findIndex({4,4,4,1}, 4) == 0);

    test::section("containsWord");
    test::check("word present",              containsWord({"hello","world","foo"}, "world") == true);
    test::check("word absent",               containsWord({"hello","world","foo"}, "bar")   == false);
    test::check("empty vector is false",     containsWord({}, "x")                          == false);
    test::check("single element match",      containsWord({"only"}, "only")                 == true);
    test::check("single element no match",   containsWord({"only"}, "other")                == false);
    test::check("case sensitive — no match", containsWord({"Hello"}, "hello")               == false);

    test::section("firstAfter");
    test::check("element after middle",     firstAfter({10,20,30,40}, 20) == 30);
    test::check("element after first",      firstAfter({1,2,3}, 1) == 2);
    test::check("target is last — return -1", firstAfter({1,2,3}, 3) == -1);
    test::check("target not found — return -1", firstAfter({1,2,3}, 9) == -1);
    test::check("duplicate — uses first occurrence", firstAfter({5,5,9}, 5) == 5);

    return test::summary();
}
