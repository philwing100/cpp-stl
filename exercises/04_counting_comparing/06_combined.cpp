// ============================================================
// EXERCISE 6: Combined Counting & Comparing
// ============================================================
// Scenario: Grading multiple-choice answer sheets
//
// In this exercise you will apply all the algorithms from
// Section 4 together in a realistic scenario.
//
// Answer sheets and answer keys are represented as
// std::vector<char>, e.g. {'A','B','C','D','A'}.
//
// Algorithms you will need:
//   std::equal()                  — check if two sheets are identical
//   std::mismatch()               — locate the first wrong answer
//   std::is_permutation()         — check if letters are the same set
//   std::count() / std::count_if()— score a paper (matching positions)
//   std::sort() with a comparator — rank sheets by score
//
// KEY IDEA: Choosing the right algorithm matters. equal() needs
// same order; is_permutation() ignores order; mismatch() tells
// you WHERE things go wrong; count_if() lets you count pairs
// that satisfy a condition.
// ============================================================

#include <algorithm>
#include <vector>
#include <numeric>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: gradePaper
// Count how many answers in `answers` match the corresponding
// position in `key`. Return that count as the score.
// Example: answers={'A','B','C'}, key={'A','X','C'} → 2
//
// HINT: equal() won't work here — it only returns true/false.
// Think about count_if() with an index, or a simple loop
// using iterators into both vectors simultaneously.
// ------------------------------------------------------------
int gradePaper(const std::vector<char>& answers,
               const std::vector<char>& key) {
    // YOUR CODE HERE
    return 0;
}

// ------------------------------------------------------------
// TASK 2: firstMistake
// Return the 1-based question number of the first wrong answer.
// Return 0 if the paper is perfect (all answers match key).
//
// HINT: Use std::mismatch(). Convert the returned iterator
// to a 1-based index with std::distance + 1.
// ------------------------------------------------------------
int firstMistake(const std::vector<char>& answers,
                 const std::vector<char>& key) {
    // YOUR CODE HERE
    return 0;
}

// ------------------------------------------------------------
// TASK 3: isPlagiarized
// Return true if two answer sheets are completely identical
// (same answer at every position).
//
// HINT: Use std::equal().
// ------------------------------------------------------------
bool isPlagiarized(const std::vector<char>& a,
                   const std::vector<char>& b) {
    // YOUR CODE HERE
    return false;
}

// ------------------------------------------------------------
// TASK 4: isScrambledVersion
// Return true if the answers contain the same characters as
// the key with the same frequencies (but possibly scrambled).
// This is NOT the same as being a correct answer sheet —
// it only checks that no letters were swapped for different ones.
//
// HINT: Use std::is_permutation().
// ------------------------------------------------------------
bool isScrambledVersion(const std::vector<char>& answers,
                        const std::vector<char>& key) {
    // YOUR CODE HERE
    return false;
}

// ------------------------------------------------------------
// TASK 5: rankSheets
// Given a vector of answer sheets and a key, return the
// 0-based indices of the sheets sorted by score DESCENDING
// (highest score first). Ties can appear in any order.
//
// Example: sheets = {sheet0, sheet1, sheet2}, key = key
//   if scores are {3, 5, 1}, return {1, 0, 2}
//
// HINT: Build an index vector {0, 1, 2, ...} and sort it
// using a lambda comparator that computes gradePaper for each
// index and compares scores.
// ------------------------------------------------------------
std::vector<int> rankSheets(const std::vector<std::vector<char>>& sheets,
                             const std::vector<char>& key) {
    // YOUR CODE HERE
    return {};
}

// ============================================================
int main() {
    std::cout << "=== Combined: Answer Sheet Grader ===\n";

    const std::vector<char> key = {'A','B','C','D','A'};

    test::section("gradePaper");
    test::check("perfect score",
        gradePaper({'A','B','C','D','A'}, key) == 5);
    test::check("all wrong",
        gradePaper({'B','C','D','A','B'}, key) == 0);
    test::check("two correct",
        gradePaper({'A','X','C','X','X'}, key) == 2);
    test::check("one correct",
        gradePaper({'X','B','X','X','X'}, key) == 1);
    test::check("empty sheet and key — 0",
        gradePaper({}, {}) == 0);
    test::check("four correct",
        gradePaper({'A','B','C','D','B'}, key) == 4);

    test::section("firstMistake");
    test::check("perfect paper — 0",
        firstMistake({'A','B','C','D','A'}, key) == 0);
    test::check("wrong on Q1",
        firstMistake({'X','B','C','D','A'}, key) == 1);
    test::check("wrong on Q3",
        firstMistake({'A','B','X','D','A'}, key) == 3);
    test::check("wrong on Q5",
        firstMistake({'A','B','C','D','X'}, key) == 5);
    test::check("wrong on Q2",
        firstMistake({'A','X','C','D','A'}, key) == 2);
    test::check("empty sheet — 0",
        firstMistake({}, {}) == 0);

    test::section("isPlagiarized");
    test::check("identical sheets — true",
        isPlagiarized({'A','B','C'}, {'A','B','C'}) == true);
    test::check("one char differs — false",
        isPlagiarized({'A','B','C'}, {'A','B','D'}) == false);
    test::check("completely different — false",
        isPlagiarized({'A','A','A'}, {'B','B','B'}) == false);
    test::check("both empty — true",
        isPlagiarized({}, {}) == true);
    test::check("different lengths — false",
        isPlagiarized({'A','B'}, {'A','B','C'}) == false);

    test::section("isScrambledVersion");
    test::check("scrambled version — true",
        isScrambledVersion({'B','A','D','C','A'}, key) == true);
    test::check("exact same order — true",
        isScrambledVersion({'A','B','C','D','A'}, key) == true);
    test::check("wrong letter frequencies",
        isScrambledVersion({'A','A','C','D','A'}, key) == false);
    test::check("completely different letters",
        isScrambledVersion({'X','X','X','X','X'}, key) == false);
    test::check("empty — true",
        isScrambledVersion({}, {}) == true);

    test::section("rankSheets");
    {
        std::vector<std::vector<char>> sheets = {
            {'A','B','C','D','A'},   // score 5 — perfect
            {'B','C','D','A','B'},   // score 0 — all wrong
            {'A','B','C','D','B'},   // score 4
        };
        auto ranked = rankSheets(sheets, key);
        test::check("best sheet is index 0", ranked[0] == 0);
        test::check("second best is index 2", ranked[1] == 2);
        test::check("worst is index 1", ranked[2] == 1);
    }
    {
        std::vector<std::vector<char>> sheets = {
            {'X','X','X','X','X'},   // score 0
            {'A','X','X','X','X'},   // score 1
        };
        auto ranked = rankSheets(sheets, key);
        test::check("higher score first", ranked[0] == 1);
        test::check("lower score last",   ranked[1] == 0);
    }
    {
        std::vector<std::vector<char>> sheets = {
            {'A','B','C','D','A'},
        };
        auto ranked = rankSheets(sheets, key);
        test::check("single sheet — index 0", ranked[0] == 0);
    }

    return test::summary();
}
