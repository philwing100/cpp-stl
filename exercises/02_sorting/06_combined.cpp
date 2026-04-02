// ============================================================
// COMBINED EXERCISE — Section 2: Sorting and Rearranging
// ============================================================
// This exercise requires you to use MULTIPLE sorting algorithms
// together to solve a realistic problem.
//
// ALGORITHMS TO USE (you decide which fits each sub-task):
//   std::sort()           std::stable_sort()
//   std::partial_sort()   std::nth_element()
//   std::is_sorted()      std::is_sorted_until()
//
// SCENARIO: Game Leaderboard System
// ----------------------------------
// You are building a leaderboard for an online game.
// Players are represented as pair<string, int>:
//   .first  = player name
//   .second = score
//
// Implement the five functions below. Each hint tells you
// which STL algorithm is the best fit.
// ============================================================

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// 1. sortLeaderboard
// Sort players by score DESCENDING. Break ties alphabetically
// by name ASCENDING (so "Alice" beats "Bob" in a tie).
// Return the sorted vector.
// HINT: std::sort() with a comparator that checks score first,
//       then name on a tie.
// ------------------------------------------------------------
std::vector<std::pair<std::string,int>> sortLeaderboard(
    std::vector<std::pair<std::string,int>> players) {
    // YOUR CODE HERE
    return players;
}

// ------------------------------------------------------------
// 2. topKPlayers
// Return the names of the top k players by score (highest
// first). If multiple players share the kth score boundary,
// any valid selection is acceptable.
// HINT: std::partial_sort() on the players vector (by score
//       descending), then collect the first k names.
// ------------------------------------------------------------
std::vector<std::string> topKPlayers(
    std::vector<std::pair<std::string,int>> players, int k) {
    // YOUR CODE HERE
    return {};
}

// ------------------------------------------------------------
// 3. medianScore
// Given a non-empty vector of integer scores, return the
// median score. Assume the vector has odd length so the median
// is a single unambiguous value.
// HINT: std::nth_element() at position size/2 on a copy.
// ------------------------------------------------------------
int medianScore(std::vector<int> scores) {
    // YOUR CODE HERE
    return 0;
}

// ------------------------------------------------------------
// 4. isTournamentBracketValid
// A tournament bracket is "valid" if scores are in
// non-increasing order (each round's top score is >= the next).
// Return true if scores are non-increasing, false otherwise.
// HINT: std::is_sorted() with a comparator for >= (i.e. a >= b,
//       which means NOT (a < b), so use std::greater<int>{}).
// ------------------------------------------------------------
bool isTournamentBracketValid(const std::vector<int>& scores) {
    // YOUR CODE HERE
    return false;
}

// ------------------------------------------------------------
// 5. longestSortedRun
// Return the length of the longest contiguous NON-DECREASING
// subarray (run) within scores.
// Example: {3, 5, 2, 4, 6, 1, 7} →
//           runs: {3,5}, {2,4,6}, {1,7} → longest = 3
// HINT: Use std::is_sorted_until() in a loop to find each
//       run's end, then track the maximum run length.
// ------------------------------------------------------------
int longestSortedRun(const std::vector<int>& scores) {
    // YOUR CODE HERE
    return 0;
}

// ============================================================
int main() {
    std::cout << "=== Combined: Sorting and Rearranging ===\n";

    test::section("sortLeaderboard");
    std::vector<std::pair<std::string,int>> lb1 = {
        {"Dave",1200}, {"Alice",1500}, {"Bob",1500}, {"Carol",900}
    };
    auto r1 = sortLeaderboard(lb1);
    test::check("highest score first",          r1[0].second == 1500);
    test::check("tied scores: Alice before Bob",r1[0].first == "Alice" && r1[1].first == "Bob");
    test::check("lowest score last",            r1[3].first == "Carol");
    test::check("descending scores overall",    r1[2].second >= r1[3].second);

    auto r2 = sortLeaderboard({{"Zara",800},{"Yuki",800},{"Xena",800}});
    test::check("all tied — alphabetical order",
        r2[0].first == "Xena" && r2[1].first == "Yuki" && r2[2].first == "Zara");

    test::section("topKPlayers");
    std::vector<std::pair<std::string,int>> lb2 = {
        {"Eve",700}, {"Frank",950}, {"Grace",850}, {"Heidi",950}, {"Ivan",600}
    };
    auto names = topKPlayers(lb2, 3);
    test::check("returns 3 players",            (int)names.size() == 3);
    // Frank and Heidi both 950 — both should appear in top-3
    bool hasFrank = std::find(names.begin(), names.end(), "Frank") != names.end();
    bool hasHeidi = std::find(names.begin(), names.end(), "Heidi") != names.end();
    test::check("top scorer Frank in results",  hasFrank);
    test::check("top scorer Heidi in results",  hasHeidi);

    auto names1 = topKPlayers({{"Solo",500}}, 1);
    test::check("k == 1 single player",         names1.size() == 1 && names1[0] == "Solo");

    auto names0 = topKPlayers(lb2, 0);
    test::check("k == 0 returns empty",         names0.empty());

    test::section("medianScore");
    test::check("median of 5",                  medianScore({300,500,400,200,100}) == 300);
    test::check("median of 3",                  medianScore({90,70,80})            == 80);
    test::check("single score",                 medianScore({42})                  == 42);
    test::check("already sorted — median",      medianScore({10,20,30,40,50})      == 30);
    test::check("duplicates — median",          medianScore({5,5,5,5,5})           == 5);

    test::section("isTournamentBracketValid");
    test::check("valid non-increasing",         isTournamentBracketValid({100,90,90,75,50}) == true);
    test::check("invalid — dip then rise",      isTournamentBracketValid({100,80,85,70})    == false);
    test::check("single round — always valid",  isTournamentBracketValid({42})              == true);
    test::check("empty — valid",                isTournamentBracketValid({})                == true);
    test::check("all equal — valid",            isTournamentBracketValid({60,60,60})        == true);
    test::check("strictly increasing — invalid",isTournamentBracketValid({10,20,30})        == false);

    test::section("longestSortedRun");
    test::check("run of 3 in middle",           longestSortedRun({3,5,2,4,6,1,7})   == 3);
    test::check("entire array is one run",      longestSortedRun({1,2,3,4,5})        == 5);
    test::check("all descending — runs of 1",   longestSortedRun({5,4,3,2,1})        == 1);
    test::check("two equal runs of 2",          longestSortedRun({1,3,2,4})          == 2);
    test::check("single element",               longestSortedRun({9})                == 1);
    test::check("empty vector",                 longestSortedRun({})                 == 0);

    return test::summary();
}
