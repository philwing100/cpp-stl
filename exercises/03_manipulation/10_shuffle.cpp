// ============================================================
// EXERCISE 10: std::shuffle()
// ============================================================
// std::shuffle() randomly rearranges the elements in a range
// using a provided uniform random number engine. Each call
// produces a different ordering, so tests must verify
// *invariant properties* rather than exact values.
//
// Syntax:
//   #include <random>
//   std::mt19937 rng(std::random_device{}());
//   std::shuffle(first, last, rng);
//
// Example:
//   std::vector<int> v = {1, 2, 3, 4, 5};
//   std::mt19937 rng(42);
//   std::shuffle(v.begin(), v.end(), rng);
//   // v is some permutation of {1, 2, 3, 4, 5}
//
// KEY IDEA: After shuffling, every element still exists —
// only the order changes. Verify correctness by checking
// that the result is a permutation of the original, or that
// invariants like min, max, and sum are preserved.
// ============================================================

#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <string>
#include <iostream>
#include "../test_utils.h"

// ------------------------------------------------------------
// TASK 1: isPermutationAfterShuffle
// Shuffle a COPY of the given vector and return true if the
// shuffled copy is a permutation of the original.
// (This should always be true — the test verifies you called
// std::shuffle correctly rather than corrupting data.)
//
// Use std::is_permutation to compare.
// ------------------------------------------------------------
bool isPermutationAfterShuffle(const std::vector<int>& original) {
    // YOUR CODE HERE
    return false;
}

// ------------------------------------------------------------
// TASK 2: shuffleNonTrivial
// Given a vector of 20+ distinct integers, shuffle it 5 times.
// After each shuffle, verify the result is a permutation of
// the original. Return true if ALL 5 shuffles pass.
//
// Use a fresh std::mt19937 engine seeded with std::random_device.
// Use std::is_permutation after each shuffle.
// ------------------------------------------------------------
bool shuffleNonTrivial(std::vector<int> v) {
    // YOUR CODE HERE
    return false;
}

// ------------------------------------------------------------
// TASK 3: shuffledStats
// Shuffle a COPY of the given vector<int> and verify that the
// min, max, and sum are identical to those of the original.
// Return true if all three match.
//
// Use std::min_element, std::max_element, and std::accumulate.
// ------------------------------------------------------------
bool shuffledStats(const std::vector<int>& original) {
    // YOUR CODE HERE
    return false;
}

// ============================================================
int main() {
    std::cout << "=== std::shuffle() ===\n";

    // Helper: a vector of 25 distinct integers for task 2
    std::vector<int> big(25);
    std::iota(big.begin(), big.end(), 1);  // {1, 2, ..., 25}

    test::section("isPermutationAfterShuffle");
    test::check("5 elements is permutation",  isPermutationAfterShuffle({1,2,3,4,5}));
    test::check("10 elements is permutation", isPermutationAfterShuffle({10,20,30,40,50,60,70,80,90,100}));
    test::check("single element",             isPermutationAfterShuffle({42}));
    test::check("two elements",               isPermutationAfterShuffle({7,3}));
    test::check("with duplicates",            isPermutationAfterShuffle({1,1,2,2,3}));

    test::section("shuffleNonTrivial");
    test::check("25 integers, 5 shuffles all permutations", shuffleNonTrivial(big));
    test::check("different 25-element range",
        shuffleNonTrivial([](){
            std::vector<int> v(25);
            std::iota(v.begin(), v.end(), 100);
            return v;
        }()));
    test::check("shuffled twice still valid",
        shuffleNonTrivial([](){
            std::vector<int> v(30);
            std::iota(v.begin(), v.end(), -15);
            return v;
        }()));

    test::section("shuffledStats");
    test::check("min max sum preserved 5 elems",   shuffledStats({3,1,4,1,5}));
    test::check("min max sum preserved 10 elems",  shuffledStats({10,20,30,40,50,60,70,80,90,100}));
    test::check("negative values",                 shuffledStats({-5,-3,-1,0,2,4}));
    test::check("single element",                  shuffledStats({99}));
    test::check("all same value",                  shuffledStats({7,7,7,7,7}));

    return test::summary();
}
