# push_swap

*This project has been created as part of the 42 curriculum by fgoncal2.*

## Description

**push_swap** is an algorithmic sorting challenge where you must sort integers in a stack using a limited set of operations with the goal of minimizing the number of actions.

### Project Goal
Given a random list of integers, sort them in ascending order in stack `a` while keeping stack `b` empty, using only these operations:
- `sa`, `sb`, `ss` (swap)
- `pa`, `pb` (push between stacks)
- `ra`, `rb`, `rr` (rotate)
- `rra`, `rrb`, `rrr` (reverse rotate)

The challenge is to find an algorithm that produces the **shortest sequence of instructions** to sort any given list of numbers.

### Learning Objectives
- Understanding sorting algorithms and their complexity
- Optimizing for minimal operations rather than simple correctness
- Memory management and stack-based data structures
- Algorithm selection based on input characteristics

## Instructions

### Compilation

```bash
# Clean and rebuild everything
make fclean
make

# Just clean object files
make clean

# Rebuild from scratch
make re
```

The project uses a custom `libft` library that is automatically compiled by the Makefile.

### Running push_swap

```bash
# Sort a list of integers
./push_swap 2 1 3 6 5 8

# With command-line arguments stored in a variable
ARG="4 67 3 87 23"; ./push_swap $ARG

# Count the number of operations
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

# No arguments - displays nothing
./push_swap
```

### Program Output

- **On success:** Prints the sequence of operations, each on a new line
- **On error:** Prints `Error` to stderr and exits with non-zero status

### Error Handling

The program validates input and rejects:
- Non-integer arguments (e.g., `"one"`)
- Integers exceeding INT_MIN or INT_MAX
- Duplicate values in the input
- Empty strings as arguments

### Performance Benchmarks

The implementation uses an optimized **radix sort** algorithm and achieves:
- **100 random numbers:** < 700 operations (optimal: ~500-600)
- **500 random numbers:** < 5500 operations (optimal: ~4000-5000)

## Resources

### Classic Sorting Algorithm References
- [Sorting Algorithms Overview](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Radix Sort Explanation](https://en.wikipedia.org/wiki/Radix_sort)
- [Stack Data Structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Algorithm Complexity (Big O)](https://en.wikipedia.org/wiki/Big_O_notation)

### Push_Swap Specific References
- [42 Network Resources](https://42.fr/)
- Sorting network theory
- Turk algorithm and similar optimization techniques

### AI Usage

AI tools were used in the following ways:
- **Code review and debugging:** Identifying memory leaks and norm violations
- **Algorithm optimization:** Exploring radix sort implementation for minimizing operations
- **Testing strategy:** Designing edge cases and benchmarking approach
- **Documentation:** Structuring this README file

The core algorithm design, implementation, and optimization were developed through manual problem-solving and iterative refinement.

## Technical Details

### Implementation Overview

The project consists of:
- **Stack operations** (`swap.c`, `push.c`, `rotate.c`, `reverse_rotate.c`): Individual operation implementations
- **Sorting algorithms** (`sort.c`, `radix.c`): Different strategies for various input sizes
- **Input parsing** (`parse.c`): Argument validation and stack initialization
- **Utility functions** (`utils.c`, `sort_utils.c`): Helper functions for the sorting process
- **Error handling** (`error.c`): User-friendly error messages

### Algorithm Strategy

1. **1-2 elements:** Return immediately (already sorted)
2. **3 elements:** Use optimal swap/rotate sequence
3. **4-5 elements:** Move smallest to stack B, sort remainder
4. **6+ elements:** Radix sort with bit-wise operations for minimal moves

## Make Rules

| Rule | Function |
|------|----------|
| `make` or `make all` | Compiles the push_swap program |
| `make clean` | Removes object files and temporary files |
| `make fclean` | Removes all generated files (objects, executables, libraries) |
| `make re` | Cleans and rebuilds everything |

## Testing

The project can be tested with various input scenarios:

```bash
# Test with sorted array (minimal operations expected)
./push_swap 1 2 3 4 5

# Test with reverse sorted array
./push_swap 5 4 3 2 1

# Test with random array
./push_swap 42 19 5 88 3 100
```

All operations are human-readable and can be manually verified or tested with external checkers.
