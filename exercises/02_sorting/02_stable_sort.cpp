// ============================================================
// EXERCISE 2: std::stable_sort()
// ============================================================
// std::stable_sort() sorts a range just like std::sort(), but
// it GUARANTEES that elements which compare as equal retain
// their original relative order (i.e., the sort is stable).
//
// Syntax:
//   std::stable_sort(first, last);
//   std::stable_sort(first, last, comparator);
//
// Example:
//   struct Item { int key; std::string name; };
//   std::vector<Item> v = {{"b",2}, {"a",1}, {"c",2}};
//   std::stable_sort(v.begin(), v.end(),
//       [](const Item& x, const Item& y){ return x.key < y.key; });
//   // Items with key==2: "b" still comes before "c" (original order)
//
// KEY IDEAS:
//   - Use stable_sort when the original order of equal elements
//     carries meaning (e.g., arrival time, original ranking).
//   - Slightly slower than std::sort in the worst case:
//     O(n log^2 n) without extra memory, O(n log n) with it.
//   - The comparator must be a strict weak ordering, same as sort.
// ============================================================

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "../test_utils.h"

struct Student {
    std::string name;
    int grade;
};

// ------------------------------------------------------------
// TASK 1: stableSortByGrade
// Given a vector of Student (name + grade), sort ascending by
// grade. Students with the same grade must keep their original
// relative order (stable sort).
// Return a vector of student NAMES in the final sorted order.
//
// Use std::stable_sort() with a comparator on .grade.
// ------------------------------------------------------------
std::vector<std::string> stableSortByGrade(std::vector<Student> students) {
    // YOUR CODE HERE
    std::vector<std::string> names;
    for (const auto& s : students) names.push_back(s.name);
    return names;
}

// ------------------------------------------------------------
// TASK 2: stableSortDescending
// Given a vector of pair<int,int> where .first is a value and
// .second is the original index, sort DESCENDING by .first
// while preserving the original relative order of pairs with
// equal .first values.
// Return the sorted vector.
//
// Use std::stable_sort() with a comparator returning a.first > b.first.
// ------------------------------------------------------------
std::vector<std::pair<int,int>> stableSortDescending(
    std::vector<std::pair<int,int>> vec) {
    // YOUR CODE HERE
    return vec;
}

// ------------------------------------------------------------
// TASK 3: stableVsUnstable
// Given a vector of pair<int,string>, sort stably by the int
// key (ascending). For pairs with the same key, the strings
// must remain in their original relative order.
// Return the sorted vector.
//
// Use std::stable_sort() with a comparator on .first.
// ------------------------------------------------------------
std::vector<std::pair<int,std::string>> stableVsUnstable(
    std::vector<std::pair<int,std::string>> vec) {
    // YOUR CODE HERE
    return vec;
}

// ============================================================
int main() {
    std::cout << "=== std::stable_sort() ===\n";

    test::section("stableSortByGrade");
    // Alice(B) then Carol(B) — Alice must still precede Carol after sort
    std::vector<Student> s1 = {{"Alice",85},{"Bob",92},{"Carol",85},{"Dave",78}};
    auto r1 = stableSortByGrade(s1);
    test::check("lowest grade first",       r1[0] == "Dave");
    test::check("tied grade: Alice before Carol", r1[1] == "Alice" && r1[2] == "Carol");
    test::check("highest grade last",       r1[3] == "Bob");

    std::vector<Student> s2 = {{"Zara",70},{"Yuki",70},{"Xena",70}};
    auto r2 = stableSortByGrade(s2);
    test::check("all tied — original order preserved", r2 == std::vector<std::string>({"Zara","Yuki","Xena"}));

    std::vector<Student> s3 = {{"Solo",99}};
    auto r3 = stableSortByGrade(s3);
    test::check("single student",           r3 == std::vector<std::string>({"Solo"}));

    test::section("stableSortDescending");
    // Pairs: (value, original_index)
    std::vector<std::pair<int,int>> v1 = {{5,0},{3,1},{5,2},{1,3},{3,4}};
    auto r4 = stableSortDescending(v1);
    test::check("highest value first",      r4[0].first == 5);
    test::check("tied 5s: original index 0 before 2", r4[0].second == 0 && r4[1].second == 2);
    test::check("tied 3s: original index 1 before 4", r4[2].second == 1 && r4[3].second == 4);
    test::check("lowest value last",        r4[4].first == 1);

    std::vector<std::pair<int,int>> v2 = {{2,0},{2,1},{2,2}};
    auto r5 = stableSortDescending(v2);
    test::check("all equal — indices in original order",
        r5[0].second == 0 && r5[1].second == 1 && r5[2].second == 2);

    test::section("stableVsUnstable");
    std::vector<std::pair<int,std::string>> v3 = {
        {2,"apple"},{1,"mango"},{2,"peach"},{1,"grape"},{3,"plum"}
    };
    auto r6 = stableVsUnstable(v3);
    test::check("key 1 elements first",         r6[0].first == 1 && r6[1].first == 1);
    test::check("key 1: mango before grape",    r6[0].second == "mango" && r6[1].second == "grape");
    test::check("key 2 elements in middle",     r6[2].first == 2 && r6[3].first == 2);
    test::check("key 2: apple before peach",    r6[2].second == "apple" && r6[3].second == "peach");
    test::check("key 3 element last",           r6[4].second == "plum");

    return test::summary();
}
