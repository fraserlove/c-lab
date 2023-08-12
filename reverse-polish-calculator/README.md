# Reverse Polish Calculator
Evaluates mathematical expressions in reverse polish notation (RPN) using a custom stack data structure.

## Usage
The calculator can be built using `make`. This produces two executables, `test_stack` and `calculator` under the `build` directory. The purpose of the `test_stack` executable is simply to test the stack implementation and can be ran using `./build/test_stack`. The calculator can be ran with
```bash
./build/calculator
```
Then simply enter an expression in reverse polish notation and the program will automatically evaluate it for you. The expression must have spaces between each operator and each operand. An example of a valid expression is the following `2 3 4 2 - + *`. If an invalid expression is provided the program will output `Bad expression`. There are numerous tests for the calculator under the `tests` directory. Running a test is as simple as sending the test file to standard input as follows:

```bash
./build/calculator < tests/add-exp.in
```
All the included build files can be removed with a simple `make clean`.
