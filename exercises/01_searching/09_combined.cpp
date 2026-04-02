// ============================================================
// COMBINED EXERCISE — Section 1: Searching Algorithms
// ============================================================
// This exercise requires you to use MULTIPLE searching algorithms
// together to solve a realistic problem.
//
// ALGORITHMS TO USE (you decide which fits each sub-task):
//   std::find()          std::find_if()
//   std::binary_search() std::lower_bound()   std::upper_bound()
//   std::count()         std::count_if()      std::find_end()
//
// SCENARIO: Student Score Analyzer
// ---------------------------------
// You are building a tool to analyze student exam scores.
// A class has taken two exams. You are given:
//   - `scores`       : unsorted list of exam 1 scores (0–100)
//   - `sortedScores` : sorted version of the same scores
//   - `exam2`        : another list of scores (exam 2)
//
// Implement the six functions below. Each one has a hint
// indicating which STL algorithm is the key tool to reach for.
// ============================================================

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// 1. hasPerfectScore
// Return true if any student scored exactly 100 in `scores`.
// HINT: binary_search on sortedScores, OR find on scores.
// ------------------------------------------------------------
bool hasPerfectScore(const std::vector<int>& sortedScores) {
    // YOUR CODE HERE
    return false;
}

// ------------------------------------------------------------
// 2. firstPassingIndex
// Return the index (in the UNSORTED `scores` vector) of the
// first score that is >= passingGrade.
// Return -1 if no one passed.
// HINT: find_if
// ------------------------------------------------------------
int firstPassingIndex(const std::vector<int>& scores, int passingGrade) {
    // YOUR CODE HERE
    return -1;
}

// ------------------------------------------------------------
// 3. passingCount
// Return how many students scored >= passingGrade in `scores`.
// HINT: count_if
// ------------------------------------------------------------
int passingCount(const std::vector<int>& scores, int passingGrade) {
    // YOUR CODE HERE
    return 0;
}

// ------------------------------------------------------------
// 4. scoresBetween
// Return how many students in `sortedScores` scored in the
// inclusive range [lo, hi].
// HINT: lower_bound + upper_bound (O(log n) solution)
// ------------------------------------------------------------
int scoresBetween(const std::vector<int>& sortedScores, int lo, int hi) {
    // YOUR CODE HERE
    return 0;
}

// ------------------------------------------------------------
// 5. exactScoreCount
// Return how many students in `scores` scored exactly `target`.
// HINT: count
// ------------------------------------------------------------
int exactScoreCount(const std::vector<int>& scores, int target) {
    // YOUR CODE HERE
    return 0;
}

// ------------------------------------------------------------
// 6. improvedStudents
// Two exam score lists are given in the same student order.
// Return the count of students whose exam2 score is strictly
// GREATER than their exam1 score.
// HINT: Use count_if with an index, OR iterate with find_if
//       repeatedly. A lambda with a captured index works well.
//
// Note: both vectors have the same length.
// ------------------------------------------------------------
int improvedStudents(const std::vector<int>& exam1,
                     const std::vector<int>& exam2) {
    // YOUR CODE HERE
    return 0;
}

// ============================================================
int main() {
    std::cout << "=== Combined: Searching Algorithms ===\n";

    std::vector<int> scores       = {72, 45, 91, 60, 55, 100, 83, 60, 77, 38};
    std::vector<int> sortedScores = {38, 45, 55, 60, 60, 72, 77, 83, 91, 100};

    test::section("hasPerfectScore");
    test::check("perfect score present",  hasPerfectScore(sortedScores) == true);
    test::check("no perfect score",       hasPerfectScore({50,60,70,80,90}) == false);
    test::check("empty list",             hasPerfectScore({}) == false);

    test::section("firstPassingIndex (passing = 60)");
    test::check("first passing in class", firstPassingIndex(scores, 60) == 0);
    test::check("none passing",           firstPassingIndex({10,20,30}, 60) == -1);
    test::check("first at end",           firstPassingIndex({10,20,65}, 60) == 2);
    test::check("all pass, first index",  firstPassingIndex({70,80,90}, 60) == 0);

    test::section("passingCount (passing = 60)");
    test::check("class data",             passingCount(scores, 60) == 7);
    test::check("none passing",           passingCount({10,20,30}, 60) == 0);
    test::check("all passing",            passingCount({60,70,80}, 60) == 3);
    test::check("exact threshold counts", passingCount({59,60,61}, 60) == 2);

    test::section("scoresBetween");
    test::check("range 60–80 in class",   scoresBetween(sortedScores, 60, 80) == 4);
    test::check("full range",             scoresBetween(sortedScores, 0, 100) == 10);
    test::check("no match range",         scoresBetween(sortedScores, 93, 99) == 0);
    test::check("single value",           scoresBetween(sortedScores, 60, 60) == 2);

    test::section("exactScoreCount");
    test::check("score 60 appears twice", exactScoreCount(scores, 60) == 2);
    test::check("score 100 appears once", exactScoreCount(scores, 100) == 1);
    test::check("score 50 not present",   exactScoreCount(scores, 50)  == 0);

    test::section("improvedStudents");
    std::vector<int> e1 = {50, 70, 90, 60, 80};
    std::vector<int> e2 = {55, 65, 95, 55, 80};
    test::check("two improved",           improvedStudents(e1, e2) == 2);
    test::check("none improved",          improvedStudents({80,90},{70,80}) == 0);
    test::check("all improved",           improvedStudents({10,20},{30,40}) == 2);
    test::check("empty — 0",              improvedStudents({}, {}) == 0);

    return test::summary();
}
