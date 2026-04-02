// ============================================================
// EXERCISE 8: std::find_end()
// ============================================================
// std::find_end() searches for the LAST occurrence of a
// subsequence within a range. It's like std::search() (which
// finds the FIRST occurrence) but finds the LAST one instead.
//
// Syntax:
//   auto it = std::find_end(first1, last1, first2, last2);
//   // Returns iterator to start of last match in [first1,last1)
//   // Returns last1 if not found.
//
// Example:
//   std::vector<int> text  = {1,2,3,1,2,3,1,2};
//   std::vector<int> pat   = {1,2};
//   auto it = std::find_end(text.begin(), text.end(),
//                           pat.begin(),  pat.end());
//   // Points to index 6 — the LAST occurrence of {1,2}
//
// MENTAL MODEL:
//   std::search()   → find FIRST occurrence of sub-sequence
//   std::find_end() → find LAST  occurrence of sub-sequence
//   (Both return end() if not found)
// ============================================================

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: lastPatternIndex
// Given a vector `data` and a pattern vector, return the
// 0-based index of the START of the LAST occurrence of
// `pattern` in `data`. Return -1 if not found.
//
// Use std::find_end().
// ------------------------------------------------------------
int lastPatternIndex(const std::vector<int>& data,
                     const std::vector<int>& pattern) {
    // YOUR CODE HERE
    return -1;
}

// ------------------------------------------------------------
// TASK 2: lastSubstring
// Given a string `text` (treated as a vector of chars) and a
// substring `sub`, return the starting index of the LAST
// occurrence of sub in text. Return -1 if not found.
//
// Hint: You can use std::find_end on std::string iterators
// since std::string is a range of chars.
// ------------------------------------------------------------
int lastSubstring(const std::string& text, const std::string& sub) {
    // YOUR CODE HERE
    return -1;
}

// ------------------------------------------------------------
// TASK 3: patternCount
// Count how many NON-OVERLAPPING occurrences of `pattern`
// appear in `data`.
//
// Strategy: repeatedly call find_end from the beginning,
// advancing past each found occurrence.
// Alternatively, use find_end from the end and work backward,
// or just use std::search in a forward loop.
// Either approach is acceptable here.
// ------------------------------------------------------------
int patternCount(const std::vector<int>& data,
                 const std::vector<int>& pattern) {
    // YOUR CODE HERE
    return 0;
}

// ============================================================
int main() {
    std::cout << "=== std::find_end() ===\n";

    test::section("lastPatternIndex");
    test::check("last of two occurrences", lastPatternIndex({1,2,3,1,2,3}, {1,2}) == 3);
    test::check("only one occurrence",     lastPatternIndex({1,2,3,4,5},   {3,4}) == 2);
    test::check("pattern at very end",     lastPatternIndex({1,2,3,4,5},   {4,5}) == 3);
    test::check("pattern at start only",   lastPatternIndex({1,2,3,4,5},   {1,2}) == 0);
    test::check("not found — -1",          lastPatternIndex({1,2,3},       {5,6}) == -1);
    test::check("empty pattern — 0",       lastPatternIndex({1,2,3},       {})    == 0);
    test::check("empty data — -1",         lastPatternIndex({},            {1,2}) == -1);
    test::check("three occurrences",       lastPatternIndex({1,2,1,2,1,2}, {1,2}) == 4);

    test::section("lastSubstring");
    test::check("last 'ab' in 'ababab'",   lastSubstring("ababab", "ab") == 4);
    test::check("only occurrence",         lastSubstring("hello", "ell") == 1);
    test::check("at very end",             lastSubstring("foobar", "bar") == 3);
    test::check("not present — -1",        lastSubstring("hello", "xyz") == -1);
    test::check("empty sub — pos 0",       lastSubstring("abc", "") == 0);
    test::check("sub longer than text",    lastSubstring("hi", "hello") == -1);

    test::section("patternCount");
    test::check("two non-overlapping",     patternCount({1,2,1,2,1,2}, {1,2}) == 3);
    test::check("one occurrence",          patternCount({1,2,3,4},     {1,2}) == 1);
    test::check("no occurrence",           patternCount({1,2,3},       {4,5}) == 0);
    test::check("pattern is full data",    patternCount({1,2,3},       {1,2,3}) == 1);
    test::check("empty data — 0",          patternCount({},            {1}) == 0);

    return test::summary();
}
