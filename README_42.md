*This project has been created as part of the 42 curriculum by fomanca.*

# Push_swap

## Description

**Push_swap** is a 42 school algorithmic project where we must sort a given list of random numbers with a limited set of operations, using the lowest possible number of actions.

The goal is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed, one has to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

### The Rules
- You have two stacks named `a` and `b`.
- At the beginning:
  - The stack `a` contains a random amount of negative and/or positive numbers which cannot be duplicated.
  - The stack `b` is empty.
- The goal is to sort in ascending order numbers into stack `a`.

## Instructions

### Compilation

The project uses a `Makefile` to compile the source files. You can use the following commands:

```bash
# Compile the mandatory part (push_swap)
make

# Compile the bonus part (checker)
make bonus

# Remove object files
make clean

# Remove object files and executables
make fclean

# Recompile everything
make re

```

### Usage & testing

 - ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

 - ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

 - ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')"); ./push_swap $ARG | ./checker $ARG

 - ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')"); ./push_swap $ARG | wc -l

## Execution

This project implements a variation of the Turk **Algorithm**

1. ***Push to B***: Elements are pushed from Stack A to Stack B. An optimization is applied here:    the code calculates the average value of Stack A, and if the pushed element is below the          average, Stack B is rotated. This optimizes the structure of Stack B for the return phase.

2. ***Sort 3***: When only 3 elements remain in Stack A, they are sorted using a simple hardcoded    logic.

3. ***Calculate Costs***: For every element in Stack B, the algorithm calculates the "cost"          (number of operations) to move it back to its correct position in Stack A.

4. ***Cheapest Move***: The element with the lowest cost is moved from B to A.

5. ***Final Rotation***: StaOptimization: Implementing the "average value check" logic during the initial push phase, which reduced the total operation count significantly (from ~6000 to ~4700 for 500 numbers).ck A is rotated to ensure the smallest number is at the top.

## Resources

### References

 - Push_swap Tutorial - by A. Yigit (The Turk Algorithm concept).
 - 42 Docs - for general understanding of stacks.
 - Oceano youtube Channel to know where should i start

### AI Usage

 - ***Norminette Compliance***: Assisting in splitting functions that exceeded the 25-line limit    and formatting code to adhere to the 42 Norm.

 - ***Optimization***: Implementing the "average value check" logic during the initial push phase,  which reduced the total operation count significantly (from ~6000 to ~4700 for 500 numbers).
