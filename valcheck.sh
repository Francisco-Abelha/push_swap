#!/bin/bash
PASS=0; FAIL=0
run() {
    valgrind --leak-check=full --show-leak-kinds=all \
             --track-origins=yes --error-exitcode=42 \
             ./push_swap "$@" > /dev/null 2>/tmp/vg_out
    if [ $? -eq 42 ]; then
        echo "LEAK: ./push_swap $*"
        grep -E "(LEAK|ERROR)" /tmp/vg_out
        FAIL=$((FAIL + 1))
    else
        echo "OK:   ./push_swap $*"
        PASS=$((PASS + 1))
    fi
}

run ""
run "   "
run abc
run +
run -
run 1 2 abc
run 2147483648
run -2147483649
run 1 1
run 1 2 1
run 42
run 2 1
run 1 2
run 1 2 3
run 1 3 2
run 2 1 3
run 2 3 1
run 3 1 2
run 3 2 1
run 4 3 2 1
run 5 4 3 2 1
run 6 5 4 3 2 1
run "3 2 1"
run "3 2" 1
run "1 2 abc"
run 2147483647
run -2147483648
run +1 +2 +3
run -3 -2 -1
run $(seq 100 -1 1 | tr '\n' ' ')

echo "PASSED: $PASS / FAILED: $FAIL"
