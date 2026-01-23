#!/bin/bash

# Push_swap Comprehensive Test Suite
# Make this file executable: chmod +x test_push_swap.sh

PUSH_SWAP="./push_swap"
CHECKER="./checker"  # Optional: if you have a checker program

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

test_count=0
pass_count=0
fail_count=0

# Function to run a test
run_test() {
    local test_name="$1"
    shift
    local should_error=""

    # Check if last argument is "error"
    if [ "${@: -1}" = "error" ]; then
        should_error="error"
        set -- "${@:1:$(($#-1))}"  # Remove last argument
    fi

    ((test_count++))

    if [ "$should_error" = "error" ]; then
        output=$($PUSH_SWAP "$@" 2>&1)
        exit_code=$?
        if echo "$output" | grep -q "Error"; then
            echo -e "${GREEN}✓${NC} Test $test_count: $test_name"
            ((pass_count++))
        else
            echo -e "${RED}✗${NC} Test $test_count: $test_name - Expected error, got exit $exit_code: '$output'"
            ((fail_count++))
        fi
    else
        output=$($PUSH_SWAP "$@" 2>&1)
        exit_code=$?
        if echo "$output" | grep -q "Error"; then
            echo -e "${RED}✗${NC} Test $test_count: $test_name - Got error (exit $exit_code): $output"
            ((fail_count++))
        else
            echo -e "${GREEN}✓${NC} Test $test_count: $test_name"
            ((pass_count++))
        fi
    fi
}

echo "======================================"
echo "  PUSH_SWAP COMPREHENSIVE TEST SUITE"
echo "======================================"
echo ""

# ==========================================
# 1. BASIC VALID INPUTS
# ==========================================
echo -e "${YELLOW}[1] Basic Valid Inputs${NC}"

run_test "Single number" "42"
run_test "Two numbers sorted" "1 2"
run_test "Two numbers unsorted" "2 1"
run_test "Three numbers sorted" "1 2 3"
run_test "Three numbers reverse" "3 2 1"
run_test "Five numbers" "5 4 3 2 1"
run_test "Negative numbers" "-1 -2 -3"
run_test "Mixed positive/negative" "-5 3 -1 0 2"
run_test "Zero in middle" "-5 0 5"
run_test "All zeros invalid" "0 0 0" "error"

# ==========================================
# 2. EMPTY AND NO INPUT
# ==========================================
echo -e "\n${YELLOW}[2] Empty and No Input${NC}"

# No arguments test needs special handling
((test_count++))
output=$($PUSH_SWAP 2>&1)
if [ -z "$output" ] && [ $? -eq 0 ]; then
    echo -e "${GREEN}✓${NC} Test $test_count: No arguments"
    ((pass_count++))
else
    echo -e "${RED}✗${NC} Test $test_count: No arguments - Expected silent exit, got: '$output'"
    ((fail_count++))
fi

run_test "Empty string" ""
run_test "Single space" " "
run_test "Multiple spaces" "   "
run_test "Tab character" "	"

# ==========================================
# 3. ALREADY SORTED
# ==========================================
echo -e "\n${YELLOW}[3] Already Sorted (Should output nothing or empty)${NC}"

run_test "2 sorted" "1 2"
run_test "3 sorted" "1 2 3"
run_test "5 sorted" "1 2 3 4 5"
run_test "100 sorted" "$(seq 1 100)"
run_test "Negative sorted" "-5 -3 -1 0 2 4"

# ==========================================
# 4. DUPLICATE NUMBERS
# ==========================================
echo -e "\n${YELLOW}[4] Duplicate Numbers (Should error)${NC}"

run_test "Two same numbers" "5 5" "error"
run_test "Duplicates in middle" "1 2 2 3" "error"
run_test "Duplicates at ends" "5 1 2 3 5" "error"
run_test "All same" "7 7 7 7" "error"
run_test "Negative duplicates" "-3 -3" "error"
run_test "Zero duplicates" "0 1 0" "error"

# ==========================================
# 5. INVALID NUMBER FORMATS
# ==========================================
echo -e "\n${YELLOW}[5] Invalid Number Formats (Should error)${NC}"

run_test "Letter in input" "1 2 a 3" "error"
run_test "Special characters" "1 @ 3" "error"
run_test "Float number" "1.5 2" "error"
run_test "Plus sign only" "+" "error"
run_test "Minus sign only" "-" "error"
run_test "Double sign" "++5" "error"
run_test "Number with letters" "123abc" "error"
run_test "Hexadecimal" "0x10" "error"
run_test "Empty between numbers" "1  2" # Should work
run_test "Leading zeros" "01 02 03" # Should work

# ==========================================
# 6. INT OVERFLOW/UNDERFLOW
# ==========================================
echo -e "\n${YELLOW}[6] INT Overflow/Underflow (Should error)${NC}"

run_test "Greater than INT_MAX" "2147483648" "error"
run_test "Less than INT_MIN" "-2147483649" "error"
run_test "Way over INT_MAX" "999999999999999999" "error"
run_test "INT_MAX valid" "2147483647"
run_test "INT_MIN valid" "-2147483648"
run_test "INT_MAX and INT_MIN" "2147483647 -2147483648"

# ==========================================
# 7. EDGE CASES WITH SIGNS
# ==========================================
echo -e "\n${YELLOW}[7] Edge Cases with Signs${NC}"

run_test "Plus sign" "+5 +3 +1"
run_test "Mixed signs" "+5 -3 +1"
run_test "Double plus" "++5" "error"
run_test "Plus minus" "+-5" "error"
run_test "Minus plus" "-+5" "error"
run_test "Sign at end" "5+" "error"
run_test "Multiple minuses" "---5" "error"

# ==========================================
# 8. WHITESPACE VARIATIONS
# ==========================================
echo -e "\n${YELLOW}[8] Whitespace Variations${NC}"

run_test "Extra spaces between" "1  2  3"
run_test "Leading spaces" " 1 2 3"
run_test "Trailing spaces" "1 2 3 "
run_test "Tabs between" "1	2	3"
run_test "Mixed whitespace" "  1   2	3  "

# ==========================================
# 9. SINGLE ARGUMENT vs MULTIPLE
# ==========================================
echo -e "\n${YELLOW}[9] Single Argument vs Multiple Arguments${NC}"

run_test "Single arg: 3 numbers" "5 3 1"
run_test "Multiple args: 3 numbers" 5 3 1
run_test "Single arg: sorted" "1 2 3"
run_test "Multiple args: sorted" 1 2 3
run_test "Single arg: with duplicates" "5 5" error
run_test "Multiple args: with duplicates" 5 5 error

# ==========================================
# 10. SMALL SETS (2-5 numbers)
# ==========================================
echo -e "\n${YELLOW}[10] Small Sets (2-5 numbers) - Various Permutations${NC}"

# 2 numbers
run_test "2 nums: sorted" "1 2"
run_test "2 nums: reverse" "2 1"

# 3 numbers (6 permutations)
run_test "3 nums: 1 2 3" "1 2 3"
run_test "3 nums: 1 3 2" "1 3 2"
run_test "3 nums: 2 1 3" "2 1 3"
run_test "3 nums: 2 3 1" "2 3 1"
run_test "3 nums: 3 1 2" "3 1 2"
run_test "3 nums: 3 2 1" "3 2 1"

# 5 numbers
run_test "5 nums: reverse sorted" "5 4 3 2 1"
run_test "5 nums: random" "3 1 5 2 4"
run_test "5 nums: mostly sorted" "1 2 4 3 5"

# ==========================================
# 11. MEDIUM SETS (100 numbers)
# ==========================================
echo -e "\n${YELLOW}[11] Medium Sets (100 numbers)${NC}"

run_test "100 nums: sorted" "$(seq 1 100)"
run_test "100 nums: reverse" "$(seq 100 -1 1)"
run_test "100 nums: random" "$(shuf -i 1-100 -n 100 | tr '\n' ' ')"

# ==========================================
# 12. LARGE SETS (500 numbers)
# ==========================================
echo -e "\n${YELLOW}[12] Large Sets (500 numbers)${NC}"

run_test "500 nums: sorted" "$(seq 1 500)"
run_test "500 nums: reverse" "$(seq 500 -1 1)"
run_test "500 nums: random" "$(shuf -i 1-500 -n 500 | tr '\n' ' ')"

# ==========================================
# 13. SPECIAL NUMERIC PATTERNS
# ==========================================
echo -e "\n${YELLOW}[13] Special Numeric Patterns${NC}"

run_test "All negative" "-5 -4 -3 -2 -1"
run_test "Large gaps" "1 1000 2000 3000"
run_test "Consecutive with gap" "1 2 3 5 6"
run_test "Single large number" "999999"
run_test "Alternating" "1 -1 2 -2 3 -3"

# ==========================================
# 14. BONUS: CHECKER INTEGRATION (if available)
# ==========================================
if [ -f "$CHECKER" ]; then
    echo -e "\n${YELLOW}[14] Checker Integration Tests${NC}"

    # Test if output actually sorts correctly
    test_with_checker() {
        local test_name="$1"
        local input="$2"

        ((test_count++))

        output=$($PUSH_SWAP $input 2>&1)
        if echo "$output" | grep -q "Error"; then
            echo -e "${RED}✗${NC} Checker $test_count: $test_name - Got error from push_swap"
            ((fail_count++))
            return
        fi

        result=$(echo "$output" | $CHECKER $input)
        if [ "$result" = "OK" ]; then
            echo -e "${GREEN}✓${NC} Checker $test_count: $test_name - Sorts correctly"
            ((pass_count++))
        else
            echo -e "${RED}✗${NC} Checker $test_count: $test_name - Does not sort correctly"
            ((fail_count++))
        fi
    }

    test_with_checker "5 random numbers" "$(shuf -i 1-100 -n 5 | tr '\n' ' ')"
    test_with_checker "100 random numbers" "$(shuf -i 1-500 -n 100 | tr '\n' ' ')"
    test_with_checker "Reverse sorted 50" "$(seq 50 -1 1)"
fi

# ==========================================
# SUMMARY
# ==========================================
echo ""
echo "======================================"
echo "           TEST SUMMARY"
echo "======================================"
echo -e "Total tests: $test_count"
echo -e "${GREEN}Passed: $pass_count${NC}"
echo -e "${RED}Failed: $fail_count${NC}"
echo ""

if [ $fail_count -eq 0 ]; then
    echo -e "${GREEN}All tests passed! 🎉${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed. Please review.${NC}"
    exit 1
fi
