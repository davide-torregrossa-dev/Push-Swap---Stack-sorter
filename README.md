# Push-Swap - Stack Sorter

*This project has been created as part of the 42 curriculum by dtorregr.*

## Description

**Push-Swap** is a sorting algorithm implementation project that focuses on sorting numbers using two stacks with a limited set of operations. The goal is to sort a list of integers using only specific stack manipulations while minimizing the total number of operations performed.

### Project Goal

Given a list of random integers, the program must sort them in ascending order using two stacks (`a` and `b`) and a predefined set of operations. The challenge lies in finding the most efficient sequence of operations to achieve the sorted result, making this an excellent exploration of algorithm optimization and complexity analysis.

### Key Features

- **Multiple Sorting Strategies**: Implements three main sorting algorithms with varying complexities:
  - Simple O(n²) approach
  - Medium O(n√n) bucket sort variant
  - Complex O(n log n) radix sort algorithm
  
- **Adaptive Strategy**: Automatically selects the best sorting strategy based on input disorder analysis
- **Performance Benchmarking**: Built-in benchmarking mode to measure and display operation counts
- **Command-Line Interface**: Flexible CLI with strategy selection and benchmark options

---

## Instructions

### Compilation

To compile the project, navigate to the repository root and run:

```bash
make
```

This will compile all source files and generate the `push_swap` executable using GCC with strict compilation flags (`-Wall -Wextra -Werror`).

To clean object files:
```bash
make clean
```

To remove both object files and the executable:
```bash
make fclean
```

To recompile from scratch:
```bash
make re
```

### Execution

#### Basic Usage

```bash
./push_swap <number1> <number2> <number3> ... <numberN>
```

Example:
```bash
./push_swap 4 2 8 1 9
```

The program will output the sequence of operations needed to sort the stack in ascending order.

#### With Space-Separated Input

You can also pass numbers as a single string with spaces:

```bash
./push_swap "4 2 8 1 9"
```

#### Selecting a Sorting Strategy

```bash
./push_swap --simple 4 2 8 1 9          # Use simple O(n²) algorithm
./push_swap --medium 4 2 8 1 9          # Use bucket sort O(n√n)
./push_swap --complex 4 2 8 1 9         # Use radix sort O(n log n)
./push_swap --adaptive 4 2 8 1 9        # Adaptive (default behavior)
```

The default behavior is adaptive, which automatically chooses the best strategy based on input disorder.

#### Benchmarking Mode

To see detailed statistics about operations performed:

```bash
./push_swap --bench 4 2 8 1 9
./push_swap --bench --simple 4 2 8 1 9
```

Benchmark output includes:
- Input disorder percentage
- Selected sorting strategy
- Total operations performed
- Breakdown of individual operations (push, swap, rotate, reverse rotate)

### Stack Operations

The program uses the following stack operations:

- **`pa`** - Push first element from stack `b` to stack `a`
- **`pb`** - Push first element from stack `a` to stack `b`
- **`sa`** - Swap the first two elements of stack `a`
- **`sb`** - Swap the first two elements of stack `b`
- **`ss`** - Swap simultaneously in both stacks
- **`ra`** - Rotate stack `a` upward (first element goes to end)
- **`rb`** - Rotate stack `b` upward
- **`rr`** - Rotate both stacks upward
- **`rra`** - Reverse rotate stack `a` (last element comes to top)
- **`rrb`** - Reverse rotate stack `b`
- **`rrr`** - Reverse rotate both stacks

---

## Algorithms

### Algorithm Selection and Justification

This project implements three distinct sorting strategies, each selected based on input characteristics and complexity requirements:

#### 1. **Simple Minmax Algorithm - O(n²)**

**Implementation**: `sort_alg_minmax_functions.c`

**How It Works**:
- Repeatedly finds the minimum and maximum elements in the source stack
- Uses a smart routing algorithm to determine the optimal path to access these elements
- Pushes extracted elements to the second stack in alternating order
- Finally, pours all elements back to the first stack in sorted order

**Complexity Analysis**:
- Time Complexity: O(n²) - For each element (n iterations), finding min/max takes O(n)
- Space Complexity: O(n) - Uses two stacks to store elements
- Operation Count: Generally 5n to 8n operations for average inputs

**When to Use**:
- Small datasets (n < 50)
- When simplicity is preferred over efficiency
- Educational purposes to understand basic stack manipulation

**Justification**:
The minmax approach is straightforward and easy to understand. It demonstrates fundamental stack operations and serves as a baseline for comparison. For small inputs where the constant factor dominates, it can actually perform comparably to more complex algorithms due to lower overhead.

---

#### 2. **Bucket Sort Algorithm - O(n√n)**

**Implementation**: `sort_alg_bucket_functions_00.c`, `sort_alg_bucket_functions_01.c`

**How It Works**:
- Divides the input range into buckets (typically √n buckets)
- Distributes elements across buckets based on their values
- Sorts elements within each bucket using a simpler algorithm
- Processes buckets in order to achieve final sorted result

**Complexity Analysis**:
- Time Complexity: O(n√n) - √n buckets with n/√n elements each
- Space Complexity: O(n) - All elements stored across buckets
- Operation Count: Generally 3n to 5n operations for average inputs

**When to Use**:
- Medium datasets (50 ≤ n ≤ 200)
- When balanced performance is needed
- Good general-purpose choice for moderate input sizes

**Justification**:
Bucket sort provides an excellent middle ground between simplicity and efficiency. It avoids the O(n²) worst-case of simple algorithms while being less complex than radix sort. The √n bucket factor creates a sweet spot for medium-sized inputs where the overhead of radix sort isn't justified.

---

#### 3. **Radix Sort Algorithm - O(n log n)**

**Implementation**: `sort_alg_radix_functions.c`

**How It Works**:
- Sorts elements by processing them digit by digit (in binary representation)
- For each bit position, separates elements into two groups: bit = 0 and bit = 1
- Uses stack operations to rearrange elements based on bit values
- Iterates through all bit positions (typically 32 for 32-bit integers)

**Complexity Analysis**:
- Time Complexity: O(n log n) - log n bit positions × n elements
- Space Complexity: O(n) - Two stacks for elements
- Operation Count: Generally 2n to 3.5n operations for large inputs

**When to Use**:
- Large datasets (n > 200)
- When worst-case performance matters
- When input size is unpredictable
- Production environments requiring consistent performance

**Justification**:
Radix sort is the most efficient algorithm implemented for large datasets. Although it processes more bit positions, each pass through the data is linear (O(n)), resulting in better overall complexity. The overhead of maintaining bit-level operations is amortized across the dataset size, making it optimal for large inputs.

---

### Adaptive Strategy

**Implementation**: `main.c`, `bench_functions.c`

The program includes an **Adaptive Strategy** that automatically selects the best algorithm based on:

1. **Input Disorder Analysis** - Measures how unsorted the input is (values closer to 0 = more sorted)
2. **Input Size**:
   - n ≤ 5: Custom optimized solution (minimal operations)
   - 5 < n ≤ 50: Simple minmax algorithm
   - 50 < n ≤ 200: Bucket sort algorithm
   - n > 200: Radix sort algorithm

**Justification for Adaptive Approach**:
- Different input sizes have different optimal algorithms
- The overhead of complex algorithms isn't justified for small inputs
- Large inputs benefit significantly from O(n log n) approaches
- This approach provides near-optimal performance across all input ranges
- Already-sorted inputs are detected and handled with no operations

---

### Routing Algorithm

**Implementation**: `router.c`

The program includes an intelligent **Routing Algorithm** used to find the most efficient path to access specific elements in the stack:

**How It Works**:
- Calculates the cost of reaching each element (considering both forward and backward rotation)
- For operations requiring multiple elements, generates all permutations of access orders
- Evaluates total cost of each permutation
- Selects the permutation with minimum cost

**Complexity**: O(k! × n) where k is the number of elements to access and n is stack size

**Justification**:
When accessing multiple elements (like min and max), the order matters. This algorithm prevents wasteful rotations by planning the most efficient access pattern. It demonstrates the importance of planning ahead in stack-based algorithms.

---

## Resources

### Classic References

- **r/C_Programming** - Community discussions on C programming practices and sorting algorithms
- **Stack Overflow** - Practical solutions and algorithm implementation examples
- **Linux man pages** - Documentation for system calls and C library functions
- **Peer implementations** - Learning from other students' approaches and code reviews

### AI Usage

AI was used in the following capacities for this project:

**Documentation and Code Comments**:
- Generated clear, structured documentation explaining algorithm choices
- Assisted in writing comprehensive README sections
- Created detailed algorithm justification and complexity analysis sections

**Algorithm Explanation**:
- Helped articulate the logic behind each sorting strategy
- Clarified the complexity analysis for each algorithm
- Explained the adaptive strategy selection rationale

**Code Review and Best Practices**:
- Suggested improvements for code clarity and organization
- Assisted with identifying optimization opportunities
- Helped validate algorithmic correctness

**Not Used For**:
- Core algorithm implementation (all algorithms hand-coded)
- Bug fixing or debugging
- Major architectural decisions

---

## Technical Choices

### Why Two Stacks?

The use of two stacks constrains the problem in a way that makes algorithm optimization meaningful. With unlimited operations, sorting becomes trivial; the constraint forces exploration of efficient element manipulation strategies.

### Error Handling

The program validates:
- All inputs are valid integers within INT_MIN and INT_MAX
- No duplicate values exist in the input
- At least one integer is provided

Invalid inputs trigger an "Error" message and exit with code 1.

### Memory Management

All dynamic memory allocations are properly freed:
- Stack content arrays are allocated once and freed at program termination
- Temporary arrays (buckets, routing arrays) are freed immediately after use
- No memory leaks in normal operation

### Compilation Flags

```
-Wall -Wextra -Werror -g
```

- **-Wall**: Enable all standard warnings
- **-Wextra**: Enable extra warnings
- **-Werror**: Treat all warnings as errors (ensures code quality)
- **-g**: Include debugging symbols

---

## Performance Benchmarks

Example output with benchmarking enabled:

```
./push_swap --bench --simple 5 4 3 2 1
[bench] disorder: 100.00%
[bench] strategy: Forced O(n2)
[bench] total_ops: 38
[bench] sa: 0 sb: 0 ss: 0 pa: 2 pb: 2
[bench] ra: 0 rb: 8 rr: 0 rra: 4 rrb: 22 rrr: 0
3 2 1 5 4
```

The benchmark output shows how the chosen strategy performs with detailed operation breakdown.

---

## Project Structure

```
├── main.c                              # Entry point and main sorting dispatch
├── push_swap.h                         # Header file with type definitions
│
├── Input Handling
│   ├── input_handling_functions_00.c   # CLI parsing and stack initialization
│   └── input_handling_functions_01.c   # Strategy selection logic
│
├── Sorting Algorithms
│   ├── sort_alg_minmax_functions.c     # O(n²) simple algorithm
│   ├── sort_alg_bucket_functions_00.c  # O(n√n) bucket sort (part 1)
│   ├── sort_alg_bucket_functions_01.c  # O(n√n) bucket sort (part 2)
│   └── sort_alg_radix_functions.c      # O(n log n) radix sort
│
├── Stack Operations
│   ├── stack_low_manip_functions_00.c  # Basic stack operations
│   ├── stack_low_manip_functions_01.c  # Stack manipulation utilities
│   ├── stack_key_manip_functions.c     # Key manipulation routines
│   └── stack_adv_manip_functions.c     # Advanced stack operations
│
├── Utilities
│   ├── array_functions_00.c            # Array utilities (part 1)
│   ├── array_functions_01.c            # Array utilities (part 2)
│   ├── array_functions_02.c            # Array utilities (part 3)
│   ├── string_functions_00.c           # String utilities (part 1)
│   ├── string_functions_01.c           # String utilities (part 2)
│   ├── char_functions.c                # Character utilities
│   ├── math_functions.c                # Math utilities
│   └── router.c                        # Intelligent routing algorithm
│
├── Benchmarking
│   ├── bench_functions.c               # Benchmark initialization
│   └── bench_printing_functions.c      # Benchmark output formatting
│
├── Printf Implementation
│   ├── ft_printf.c                     # Custom printf implementation
│   ├── ft_printf_chars_printer.c       # Character printing
│   ├── ft_printf_digits_printer.c      # Number printing
│   └── ft_printf_hex_printer.c         # Hexadecimal printing
│
├── Parsing Utilities
│   └── ft_split.c                      # String splitting utility
│
├── Makefile                            # Build configuration
└── README.md                           # This file
```

---

## Conclusion

Push-Swap is a comprehensive exploration of sorting algorithms, stack manipulation, and algorithm optimization. By implementing multiple strategies with varying complexities and an adaptive selection mechanism, the project demonstrates how different algorithms excel in different scenarios. The adaptive approach ensures optimal performance across all input ranges, making it a practical solution that balances simplicity with efficiency.

The project showcases deep understanding of:
- Algorithm complexity analysis and Big O notation
- Stack-based data manipulation
- Adaptive algorithm selection
- Performance optimization and benchmarking
- Clean code organization and memory management
