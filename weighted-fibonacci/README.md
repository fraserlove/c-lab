# Weighted Fibonacci

Recursive and iterative implementations of the weighted fibonacci sequence. The sequence starts with 0, 1 and then each successive term is defined as follows: $x_n = x_{n-1} + 2 * x_{n-2}$. Safe maths has been implemented so as to output `Overflow` and exist the program if the latest number in the sequence is too large to store in a `long long` type.

## Usage
Both the recursive and iterative implementations can be built using `make`. This produces two builds named `recursive` and `iterative` under the `build` directory which can then be executed as follows.
```bash
./build/recursive
```
or 
```bash
./build/iterative
```
All the included build files can be removed with a simple `make clean`.