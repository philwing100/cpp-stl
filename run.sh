#!/usr/bin/env bash
# Quick helper: compile and run a single exercise by partial name
# Usage: ./run.sh 01_find
#        ./run.sh binary_search
#        ./run.sh combined   (runs all combined exercises)

set -e

EXERCISE_DIR="exercises"
QUERY="${1:-}"

if [ -z "$QUERY" ]; then
    echo "Usage: $0 <exercise_name_or_partial>"
    echo "       $0 all"
    echo ""
    echo "Examples:"
    echo "  $0 01_find"
    echo "  $0 binary_search"
    echo "  $0 combined"
    echo "  $0 all"
    exit 1
fi

if [ "$QUERY" = "all" ]; then
    make run_all
    exit $?
fi

# Find matching source file
MATCH=$(find "$EXERCISE_DIR" -name "*.cpp" | grep -i "$QUERY" | head -1)

if [ -z "$MATCH" ]; then
    echo "No exercise found matching: $QUERY"
    echo ""
    echo "Available exercises:"
    find "$EXERCISE_DIR" -name "*.cpp" | sort | sed 's|exercises/||;s|\.cpp||'
    exit 1
fi

OUT="${MATCH%.cpp}.out"
echo "Compiling: $MATCH"
g++ -std=c++17 -Wall -Wextra -I exercises "$MATCH" -o "$OUT"
echo "Running: $OUT"
echo ""
"$OUT"
