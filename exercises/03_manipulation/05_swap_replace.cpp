// ============================================================
// EXERCISE 5: std::swap() + std::replace() + std::replace_if()
// ============================================================
// std::swap(a, b)
//   Exchanges the values of two variables in place.
//   Works on individual elements, containers, or any swappable type.
//
// std::replace(first, last, old_val, new_val)
//   Replaces every element equal to old_val with new_val.
//
// std::replace_if(first, last, predicate, new_val)
//   Replaces every element for which pred(elem) is true with new_val.
//
// Syntax:
//   std::swap(x, y);
//   std::replace(v.begin(), v.end(), old_val, new_val);
//   std::replace_if(v.begin(), v.end(), pred, new_val);
//
// Example:
//   int a = 3, b = 7;
//   std::swap(a, b);  // a == 7, b == 3
//
//   std::vector<int> v = {1, 2, 3, 2, 1};
//   std::replace(v.begin(), v.end(), 2, 99);
//   // v == {1, 99, 3, 99, 1}
//
// KEY IDEA: replace and replace_if modify the range IN PLACE
// and return void — they do not create a new container.
// ============================================================

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: swapMinMax
// Given a vector<int>, find the positions of the minimum and
// maximum elements, then swap them in place using std::swap.
// Return the modified vector.
//
// Use std::min_element and std::max_element to locate the
// iterators, then std::swap the values they point to.
// If min and max are the same element (all values equal),
// the vector is unchanged.
// ------------------------------------------------------------
std::vector<int> swapMinMax(std::vector<int> v) {
    // YOUR CODE HERE
    return v;
}

// ------------------------------------------------------------
// TASK 2: censorScore
// Given a vector<int> of scores and an integer `threshold`,
// replace every score that is strictly less than `threshold`
// with 0. Return the modified vector.
//
// Use std::replace_if with a capturing lambda.
// ------------------------------------------------------------
std::vector<int> censorScore(std::vector<int> scores, int threshold) {
    // YOUR CODE HERE
    return scores;
}

// ------------------------------------------------------------
// TASK 3: normalizeGrades
// Given a vector<char> of letter grades, replace every 'E'
// with 'F' (some grading systems use E where others use F).
// Return the modified vector.
//
// Use std::replace.
// ------------------------------------------------------------
std::vector<char> normalizeGrades(std::vector<char> grades) {
    // YOUR CODE HERE
    return grades;
}

// ============================================================
int main() {
    std::cout << "=== std::swap() + std::replace() + std::replace_if() ===\n";

    test::section("swapMinMax");
    test::check("basic swap",          swapMinMax({3,1,4,1,5,9,2}) == std::vector<int>({3,9,4,1,5,1,2}));
    test::check("min at start",        swapMinMax({1,5,3})          == std::vector<int>({5,1,3}));
    test::check("max at start",        swapMinMax({9,2,5})          == std::vector<int>({2,9,5}));
    test::check("two elements",        swapMinMax({7,3})            == std::vector<int>({3,7}));
    test::check("all equal unchanged", swapMinMax({4,4,4})          == std::vector<int>({4,4,4}));
    test::check("already ordered",     swapMinMax({1,2,3})          == std::vector<int>({3,2,1}));

    test::section("censorScore");
    test::check("threshold 50",        censorScore({80,45,90,30,70}, 50) == std::vector<int>({80,0,90,0,70}));
    test::check("all above threshold", censorScore({60,70,80}, 50)       == std::vector<int>({60,70,80}));
    test::check("all below threshold", censorScore({10,20,30}, 50)       == std::vector<int>({0,0,0}));
    test::check("exact threshold kept",censorScore({50,49,51}, 50)       == std::vector<int>({50,0,51}));
    test::check("empty vector",        censorScore({}, 50)               == std::vector<int>({}));
    test::check("threshold 0",         censorScore({-1,0,1}, 0)          == std::vector<int>({0,0,1}));

    test::section("normalizeGrades");
    test::check("E replaced with F",   normalizeGrades({'A','E','B','E','C'}) == std::vector<char>({'A','F','B','F','C'}));
    test::check("no E in input",       normalizeGrades({'A','B','C','D','F'}) == std::vector<char>({'A','B','C','D','F'}));
    test::check("all E",               normalizeGrades({'E','E','E'})         == std::vector<char>({'F','F','F'}));
    test::check("single E",            normalizeGrades({'E'})                 == std::vector<char>({'F'}));
    test::check("empty input",         normalizeGrades({})                    == std::vector<char>({}));
    test::check("mixed grades",        normalizeGrades({'A','E','D','E','F'}) == std::vector<char>({'A','F','D','F','F'}));

    return test::summary();
}
