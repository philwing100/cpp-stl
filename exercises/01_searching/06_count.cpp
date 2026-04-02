// ============================================================
// EXERCISE 6: std::count()
// ============================================================
// std::count() counts how many elements in a range are EQUAL
// to a given value (using operator==).
//
// Syntax:
//   auto n = std::count(first, last, value);
//
// Returns a std::ptrdiff_t (treat it as an int for these exercises).
//
// Example:
//   std::vector<int> v = {1, 2, 2, 3, 2};
//   std::count(v.begin(), v.end(), 2); // returns 3
//
// Works on ANY equality-comparable type: int, char, string, etc.
//
// NOTE: For SORTED ranges, upper_bound - lower_bound is faster
// (O(log n) vs O(n)), but count() works on unsorted data too.
// ============================================================

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: gradeCount
// Given a list of letter grades ('A','B','C','D','F') and a
// specific grade, return how many students received that grade.
//
// Use std::count().
// ------------------------------------------------------------
int gradeCount(const std::vector<char>& grades, char grade) {
    // YOUR CODE HERE
    return 0;
}

// ------------------------------------------------------------
// TASK 2: wordFrequency
// Given a vector of words, return how many times `word` appears.
//
// Use std::count().
// ------------------------------------------------------------
int wordFrequency(const std::vector<std::string>& words,
                  const std::string& word) {
    // YOUR CODE HERE
    return 0;
}

// ------------------------------------------------------------
// TASK 3: majority
// Return true if value appears MORE THAN half the time in vec.
// (i.e., count(value) > vec.size() / 2)
//
// Use std::count().
// ------------------------------------------------------------
bool majority(const std::vector<int>& vec, int value) {
    // YOUR CODE HERE
    return false;
}

// ============================================================
int main() {
    std::cout << "=== std::count() ===\n";

    test::section("gradeCount");
    test::check("counts A grades",     gradeCount({'A','B','A','C','A'}, 'A') == 3);
    test::check("counts zero grades",  gradeCount({'A','B','C'}, 'F')          == 0);
    test::check("empty list — 0",      gradeCount({}, 'A')                    == 0);
    test::check("all same grade",      gradeCount({'B','B','B'}, 'B')         == 3);
    test::check("single element match",gradeCount({'D'}, 'D')                 == 1);
    test::check("single no match",     gradeCount({'D'}, 'A')                 == 0);

    test::section("wordFrequency");
    test::check("word appears 3 times",  wordFrequency({"the","cat","sat","on","the","mat","the"}, "the") == 3);
    test::check("word appears once",     wordFrequency({"hello","world"}, "world") == 1);
    test::check("word absent — 0",       wordFrequency({"hello","world"}, "foo")   == 0);
    test::check("empty list — 0",        wordFrequency({}, "x") == 0);
    test::check("case sensitive",        wordFrequency({"Hello","hello"}, "hello") == 1);

    test::section("majority");
    test::check("clear majority",         majority({1,1,1,2,3}, 1) == true);
    test::check("exactly half — false",   majority({1,1,2,2}, 1)   == false);
    test::check("no majority — false",    majority({1,2,3,4,5}, 1) == false);
    test::check("single element — true",  majority({7}, 7)         == true);
    test::check("all same — true",        majority({3,3,3}, 3)     == true);

    return test::summary();
}
