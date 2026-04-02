// ============================================================
// EXERCISE 11: Combined Manipulation Algorithms
// ============================================================
// This exercise chains multiple manipulation algorithms together
// in realistic mini-pipelines. You will use:
//
//   copy_if   — filter elements by predicate
//   transform — apply a function to every element
//   fill      — overwrite a subrange with a constant
//   replace_if— replace elements matching a predicate in place
//   remove/unique + erase — shrink a container
//   binary transform — element-wise operation on two ranges
//
// Review the individual exercises (02 through 08) if you need
// a refresher on any algorithm's syntax before starting.
// ============================================================

#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <cctype>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: cleanText
// Given a vector<string> of words (some may be empty strings),
// perform a two-step pipeline:
//   1. Use copy_if to remove empty strings.
//   2. Use transform to convert every remaining word to
//      uppercase (all characters).
// Return the resulting vector.
// ------------------------------------------------------------
std::vector<std::string> cleanText(const std::vector<std::string>& words) {
    // YOUR CODE HERE
    return {};
}

// ------------------------------------------------------------
// TASK 2: summarizeScores
// Given a vector<int> of scores and a threshold:
//   1. Use replace_if to set every score BELOW `badThreshold`
//      to 0 (modify a local copy).
//   2. Use std::count_if to count how many scores are non-zero.
// Return the count of non-zero scores.
// ------------------------------------------------------------
int summarizeScores(std::vector<int> scores, int badThreshold) {
    // YOUR CODE HERE
    return 0;
}

// ------------------------------------------------------------
// TASK 3: buildReport
// Given a vector<int> `base` and an integer `multiplier`:
//   1. Use transform to multiply every element by `multiplier`
//      into a new vector.
//   2. Use fill to set the first 2 elements of the result to 0
//      (only if the vector has at least 2 elements).
// Return the final vector.
// ------------------------------------------------------------
std::vector<int> buildReport(const std::vector<int>& base, int multiplier) {
    // YOUR CODE HERE
    return {};
}

// ------------------------------------------------------------
// TASK 4: deduplicateSorted
// Given a SORTED vector<int>, remove all consecutive duplicates
// so each value appears exactly once. Return the result.
//
// Use std::unique + erase.
// ------------------------------------------------------------
std::vector<int> deduplicateSorted(std::vector<int> sorted) {
    // YOUR CODE HERE
    return sorted;
}

// ------------------------------------------------------------
// TASK 5: zipSum
// Given two equal-length vectors<int>, return a new vector
// where each element is the sum of the corresponding elements
// from both inputs.
//
// Use the binary form of std::transform.
// ------------------------------------------------------------
std::vector<int> zipSum(const std::vector<int>& a, const std::vector<int>& b) {
    // YOUR CODE HERE
    return {};
}

// ============================================================
int main() {
    std::cout << "=== Combined Manipulation Algorithms ===\n";

    test::section("cleanText");
    test::check("removes empty, uppercases",
        cleanText({"hello","","world",""}) ==
            std::vector<std::string>({"HELLO","WORLD"}));
    test::check("no empty strings",
        cleanText({"foo","bar"}) ==
            std::vector<std::string>({"FOO","BAR"}));
    test::check("all empty strings",
        cleanText({"","",""}) == std::vector<std::string>({}));
    test::check("single non-empty word",
        cleanText({"cpp"}) == std::vector<std::string>({"CPP"}));
    test::check("empty input",
        cleanText({}) == std::vector<std::string>({}));
    test::check("mixed case input",
        cleanText({"hElLo","","WoRlD"}) ==
            std::vector<std::string>({"HELLO","WORLD"}));

    test::section("summarizeScores");
    test::check("two above threshold",  summarizeScores({80,45,90,30,70}, 50) == 3);
    test::check("all above threshold",  summarizeScores({60,70,80}, 50)       == 3);
    test::check("all below threshold",  summarizeScores({10,20,30}, 50)       == 0);
    test::check("exact threshold kept", summarizeScores({50,49,51}, 50)       == 2);
    test::check("empty vector",         summarizeScores({}, 50)               == 0);
    test::check("threshold 0",          summarizeScores({-1,0,1}, 0)          == 1);

    test::section("buildReport");
    test::check("multiply then zero first 2",
        buildReport({1,2,3,4,5}, 10) == std::vector<int>({0,0,30,40,50}));
    test::check("multiplier 1 identity then zero",
        buildReport({1,2,3}, 1)      == std::vector<int>({0,0,3}));
    test::check("two elements both zeroed",
        buildReport({5,6}, 2)        == std::vector<int>({0,0}));
    test::check("one element not zeroed (< 2 elems)",
        buildReport({4}, 3)          == std::vector<int>({12}));
    test::check("empty base",
        buildReport({}, 5)           == std::vector<int>({}));
    test::check("multiplier 0",
        buildReport({9,8,7}, 0)      == std::vector<int>({0,0,0}));

    test::section("deduplicateSorted");
    test::check("consecutive dupes",
        deduplicateSorted({1,1,2,3,3,3,4}) == std::vector<int>({1,2,3,4}));
    test::check("no duplicates",
        deduplicateSorted({1,2,3,4,5})     == std::vector<int>({1,2,3,4,5}));
    test::check("all same",
        deduplicateSorted({5,5,5,5})       == std::vector<int>({5}));
    test::check("empty input",
        deduplicateSorted({})              == std::vector<int>({}));
    test::check("single element",
        deduplicateSorted({7})             == std::vector<int>({7}));
    test::check("two distinct groups",
        deduplicateSorted({2,2,3,3})       == std::vector<int>({2,3}));

    test::section("zipSum");
    test::check("basic sum",
        zipSum({1,2,3},{4,5,6})    == std::vector<int>({5,7,9}));
    test::check("add zeros",
        zipSum({1,2,3},{0,0,0})    == std::vector<int>({1,2,3}));
    test::check("negatives cancel",
        zipSum({-1,-2},{1,2})      == std::vector<int>({0,0}));
    test::check("single elements",
        zipSum({10},{20})          == std::vector<int>({30}));
    test::check("empty vectors",
        zipSum({},{})              == std::vector<int>({}));
    test::check("longer vectors",
        zipSum({1,1,1,1},{2,2,2,2})== std::vector<int>({3,3,3,3}));

    return test::summary();
}
