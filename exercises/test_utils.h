#pragma once
#include <iostream>
#include <string>
#include <functional>

// Lightweight test framework for STL exercises
namespace test {

static int passed = 0;
static int failed = 0;

inline void check(const std::string& name, bool condition) {
    if (condition) {
        std::cout << "  [PASS] " << name << "\n";
        ++passed;
    } else {
        std::cout << "  [FAIL] " << name << "\n";
        ++failed;
    }
}

inline void section(const std::string& title) {
    std::cout << "\n--- " << title << " ---\n";
}

inline int summary() {
    std::cout << "\n==============================\n";
    std::cout << "Results: " << passed << "/" << (passed + failed) << " tests passed\n";
    if (failed == 0)
        std::cout << "All tests passed! Great work.\n";
    else
        std::cout << failed << " test(s) still failing — keep going!\n";
    std::cout << "==============================\n";
    return failed > 0 ? 1 : 0;
}

} // namespace test
