# Multi Process Pipeline
An implementation of a data processing pipeline consisting of a number of processing stages, connected in series, using pipes for inter-process communication (IPC) and allowing for an arbitrary number of stages. Included are five tests, all of which make use of the implemented pipeline. A description of each of these five tests is given below:

- `send_int.c` - A basic test of inter-process communication, sending an integer from one process to another.
- `double_int.c` - Similar to `send_int.c` except that another process is used in between to double the integers value.
- `sum_squares.c` - Consists of three processes. One to generate an array of integers up to $n$, another to square each of the integers in the array, and final process to add up all the values in this array.
- `prime_sieve.c` - Uses the sieve of Eratosthenes algorithm for finding the first $m$ prime numbers up to the value of $n$, with $m + 1$ processes being invoked.
- `fibonacci_sequence.c` - Calculates the first $n$ terms in the fibonacci sequence using $n + 1$ processes. 

## Usage
The test files can be built using `make`. This produces five executables, `send_int`, `double_int`, `fibonacci_sequence`, `prime_sieve` and `sum_squares` under the `build` directory. An example of running the test file `send_int` is given below:
```bash
./build/send_int
```
All the included build files can be removed with a simple `make clean`.
