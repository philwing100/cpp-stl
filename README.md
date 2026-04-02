# C++ STL Algorithm Exercises

CodingBat-style exercises for learning the C++ Standard Library algorithms. Each exercise has:
- A detailed explanation of the algorithm (syntax, example, key ideas)
- 2-3 function stubs for you to implement
- Automated test cases that run immediately

**No manual grading. No setup beyond a C++ compiler.**

---

## Requirements

- g++ with C++17 support (`g++ --version`)
- Already installed in this devcontainer

---

## How to Work Through the Exercises

### Run a single exercise
```bash
./run.sh 01_find          # partial name match
./run.sh binary_search    # keyword match
./run.sh combined         # all combined exercises
```

### Run a full section
```bash
make section1    # Searching Algorithms
make section2    # Sorting & Rearranging
make section3    # Manipulation Algorithms
make section4    # Counting & Comparing
```

### Run everything
```bash
make run_all
```

### Compile manually (if you prefer)
```bash
g++ -std=c++17 -I exercises exercises/01_searching/01_find.cpp -o /tmp/ex && /tmp/ex
```

---

## Exercise Map

### Section 1 — Searching Algorithms
| File | Algorithm | Key Concept |
|------|-----------|-------------|
| [01_find.cpp](exercises/01_searching/01_find.cpp) | `std::find` | Returns iterator to first match |
| [02_find_if.cpp](exercises/01_searching/02_find_if.cpp) | `std::find_if` | First element satisfying a predicate |
| [03_binary_search.cpp](exercises/01_searching/03_binary_search.cpp) | `std::binary_search` | O(log n) existence check on sorted range |
| [04_lower_bound.cpp](exercises/01_searching/04_lower_bound.cpp) | `std::lower_bound` | First element >= value |
| [05_upper_bound.cpp](exercises/01_searching/05_upper_bound.cpp) | `std::upper_bound` | First element > value |
| [06_count.cpp](exercises/01_searching/06_count.cpp) | `std::count` | Count occurrences of a value |
| [07_count_if.cpp](exercises/01_searching/07_count_if.cpp) | `std::count_if` | Count elements matching a predicate |
| [08_find_end.cpp](exercises/01_searching/08_find_end.cpp) | `std::find_end` | Last occurrence of a subsequence |
| **[09_combined.cpp](exercises/01_searching/09_combined.cpp)** | **All of above** | **Student score analyzer** |

### Section 2 — Sorting & Rearranging
| File | Algorithm | Key Concept |
|------|-----------|-------------|
| [01_sort.cpp](exercises/02_sorting/01_sort.cpp) | `std::sort` | Ascending/descending/custom comparator |
| [02_stable_sort.cpp](exercises/02_sorting/02_stable_sort.cpp) | `std::stable_sort` | Preserves relative order of equal elements |
| [03_partial_sort.cpp](exercises/02_sorting/03_partial_sort.cpp) | `std::partial_sort` | Sort only the first N elements |
| [04_nth_element.cpp](exercises/02_sorting/04_nth_element.cpp) | `std::nth_element` | Partition around kth element in O(n) |
| [05_is_sorted.cpp](exercises/02_sorting/05_is_sorted.cpp) | `std::is_sorted` / `is_sorted_until` | Check sortedness / find breakpoint |
| **[06_combined.cpp](exercises/02_sorting/06_combined.cpp)** | **All of above** | **Game leaderboard system** |

### Section 3 — Manipulation Algorithms
| File | Algorithm | Key Concept |
|------|-----------|-------------|
| [01_copy.cpp](exercises/03_manipulation/01_copy.cpp) | `std::copy` | Copy range to destination |
| [02_copy_if.cpp](exercises/03_manipulation/02_copy_if.cpp) | `std::copy_if` | Copy only elements matching predicate |
| [03_copy_n.cpp](exercises/03_manipulation/03_copy_n.cpp) | `std::copy_n` | Copy exactly N elements |
| [04_move.cpp](exercises/03_manipulation/04_move.cpp) | `std::move` (algorithm) | Transfer ownership of elements |
| [05_swap_replace.cpp](exercises/03_manipulation/05_swap_replace.cpp) | `std::swap` / `replace` / `replace_if` | Exchange values; replace by value or condition |
| [06_remove.cpp](exercises/03_manipulation/06_remove.cpp) | `std::remove` | Erase-remove idiom |
| [07_fill.cpp](exercises/03_manipulation/07_fill.cpp) | `std::fill` | Set all elements to a value |
| [08_transform.cpp](exercises/03_manipulation/08_transform.cpp) | `std::transform` | Apply function to each element |
| [09_generate.cpp](exercises/03_manipulation/09_generate.cpp) | `std::generate` | Fill range from a generator function |
| [10_shuffle.cpp](exercises/03_manipulation/10_shuffle.cpp) | `std::shuffle` | Random permutation |
| **[11_combined.cpp](exercises/03_manipulation/11_combined.cpp)** | **All of above** | **Text processing pipeline** |

### Section 4 — Counting & Comparing
| File | Algorithm | Key Concept |
|------|-----------|-------------|
| [01_equal.cpp](exercises/04_counting_comparing/01_equal.cpp) | `std::equal` | Are two ranges identical? |
| [02_mismatch.cpp](exercises/04_counting_comparing/02_mismatch.cpp) | `std::mismatch` | First position where ranges differ |
| [03_lexicographical_compare.cpp](exercises/04_counting_comparing/03_lexicographical_compare.cpp) | `std::lexicographical_compare` | Dictionary order comparison |
| [04_is_permutation.cpp](exercises/04_counting_comparing/04_is_permutation.cpp) | `std::is_permutation` | Same elements, any order? |
| [05_count_review.cpp](exercises/04_counting_comparing/05_count_review.cpp) | `std::count` / `count_if` | Review with comparison context |
| **[06_combined.cpp](exercises/04_counting_comparing/06_combined.cpp)** | **All of above** | **Quiz answer sheet grader** |

---

## Workflow Tips

1. **Read the header comment** in each file before writing any code — it has the syntax, a worked example, and pointers to what makes the algorithm tick.
2. **Run tests immediately** after each function you implement so you get fast feedback.
3. **Stuck?** The task comment tells you which algorithm to use. Check cppreference.com for the exact signature.
4. **Passing all tests?** Move on — don't over-engineer.
5. **Combined exercises** are meant to be hard. You'll need to pick the right algorithm for each sub-task.

---

## Algorithm Quick Reference

```
SEARCHING           SORTING              MANIPULATION         COMPARING
──────────────────  ───────────────────  ───────────────────  ──────────────────
find                sort                 copy / copy_if/n     equal
find_if             stable_sort          copy_backward        mismatch
binary_search       partial_sort         move (algorithm)     lexicographical_compare
lower_bound         nth_element          swap                 is_permutation
upper_bound         is_sorted            replace / replace_if count / count_if
count               is_sorted_until      remove
count_if                                 fill
find_end                                 transform
                                         generate
                                         shuffle
```
