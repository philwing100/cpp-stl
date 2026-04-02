CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -I exercises

# Discover all exercise source files
SOURCES  := $(shell find exercises -name '*.cpp')
BINARIES := $(SOURCES:.cpp=.out)

.PHONY: all clean run_all section1 section2 section3 section4

all: $(BINARIES)

# Pattern rule: compile any exercise .cpp -> .out
%.out: %.cpp exercises/test_utils.h
	@$(CXX) $(CXXFLAGS) $< -o $@

# Run all compiled binaries, report pass/fail per file
run_all: all
	@echo ""; \
	total_pass=0; total_fail=0; \
	for bin in $(sort $(BINARIES)); do \
	    name=$$(echo $$bin | sed 's|exercises/||;s|\.out||'); \
	    echo "============================================================"; \
	    echo "  $$name"; \
	    echo "============================================================"; \
	    $$bin; \
	    code=$$?; \
	    if [ $$code -eq 0 ]; then total_pass=$$((total_pass+1)); \
	    else total_fail=$$((total_fail+1)); fi; \
	    echo ""; \
	done; \
	echo "============================================================"; \
	echo "  OVERALL: $$total_pass exercises fully passing,"; \
	echo "           $$total_fail exercise(s) have failing tests"; \
	echo "============================================================"

section1: $(shell find exercises/01_searching -name '*.cpp' | sed 's/\.cpp/.out/')
	@for bin in $(sort $(shell find exercises/01_searching -name '*.cpp' | sed 's/\.cpp/.out/')); do \
	    echo "--- $$(basename $$bin .out) ---"; $$bin; echo ""; done

section2: $(shell find exercises/02_sorting -name '*.cpp' | sed 's/\.cpp/.out/')
	@for bin in $(sort $(shell find exercises/02_sorting -name '*.cpp' | sed 's/\.cpp/.out/')); do \
	    echo "--- $$(basename $$bin .out) ---"; $$bin; echo ""; done

section3: $(shell find exercises/03_manipulation -name '*.cpp' | sed 's/\.cpp/.out/')
	@for bin in $(sort $(shell find exercises/03_manipulation -name '*.cpp' | sed 's/\.cpp/.out/')); do \
	    echo "--- $$(basename $$bin .out) ---"; $$bin; echo ""; done

section4: $(shell find exercises/04_counting_comparing -name '*.cpp' | sed 's/\.cpp/.out/')
	@for bin in $(sort $(shell find exercises/04_counting_comparing -name '*.cpp' | sed 's/\.cpp/.out/')); do \
	    echo "--- $$(basename $$bin .out) ---"; $$bin; echo ""; done

clean:
	find exercises -name '*.out' -delete
