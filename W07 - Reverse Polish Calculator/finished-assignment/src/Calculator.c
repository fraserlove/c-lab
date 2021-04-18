/*
 * Calculator.c
 *
 * Implementation of RPN Calculator to evaluate RPN expressions.
 *
 */

#include "Calculator.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

float addition(float op1, float op2) {
    return op1 + op2;
}

float subtraction(float op1, float op2) {
    return op1 - op2;
}

float multiplication(float op1, float op2) {
    return op1 * op2;
}

float division(float op1, float op2) {
    if (op2 == 0) {
        // Expression is invalid if division by zero is to be performed
        printf("Bad expression\n");
        exit(0);
    }
    return op1 / op2;
}

/*
 * Pops two operands from the stack, performs an operation based on the current operand being evaluated, and returns
 * the result to the top of the stack.
 */
void performOperation(Calculator this) {
    float op1, op2;
    Stack_pop(this.stack, &op2);
    Stack_pop(this.stack, &op1);
    switch(this.expr[0]) {
        case '+': this.result = addition(op1, op2); break;
        case '-': this.result = subtraction(op1, op2); break;
        case '*': this.result = multiplication(op1, op2); break;
        case '/': this.result = division(op1, op2); break;
    }
    Stack_push(this.stack, this.result);
}

/*
 * Checks if a number is valid by looking at its first digit.
 */
bool isNum(char* chr) {
    return isdigit(chr[0]) || (chr[0] == '-' && isdigit(chr[1]));
}

/*
 * If there is still an operator to evaluate but less than two operators left in the stack then two few operands
 * have been supplied.
 */
void checkNotEnoughOperands(Stack* stack) {
    if (Stack_size(stack) < 2) {
        printf("Bad expression\n");
        exit(0);
    }
}

/*
 * If there is more than one operand left in the stack and no operators left then two few operators have been
 * supplied.
 */
void checkNotEnoughOperators(Stack* stack) {
    if (Stack_size(stack) > 1) {
        printf("Bad expression\n");
        exit(0);
    }
}

/*
 * Creates/initialises a RPN Calculator. Returns a valid Calculator struct by value.
 */
Calculator newCalculator(char* expr) {
    Calculator this;
    this.expr = strtok(expr, " ");
    this.result = 0;
    this.stack = new_Stack();
    return this;
}

/*
 * Destroys the Calculator by clearing any stack data (and freeing the memory if you are using dynamic memory allocation).
 */
void destroyCalculator(Calculator this) {
    Stack_destroy(this.stack);
}

/*
 * Evaluates the RPN expression supplied to the calculator by evaluating and solving it using a stack. Returns a
 * float which is the real number that the expression has been evaluated to.
 */
float evaluateExpression(Calculator this) {
    while(this.expr != NULL) {
        if(isNum(this.expr)) {
            Stack_push(this.stack, atof(&this.expr[0]));
        }
        else {
            checkNotEnoughOperands(this.stack);
            performOperation(this);
        }
        this.expr = strtok(NULL, " ");
    }
    checkNotEnoughOperators(this.stack);
    Stack_pop(this.stack, &this.result);
    return this.result;
}