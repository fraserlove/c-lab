/*
 * calculator.h
 *
 * Module interface for Calculator implementation.
 *
 */

#include "stack.h"

#ifndef CALCULATOR_H
#define CALCULATOR_H

#define MAX_EXPR_SIZE 100

#endif

typedef struct Calculator Calculator;

/* Holds the attributes of an RPN Calculator. Including the stack struct used for computation. */
struct Calculator {
    Stack* stack;
    char* expr;
    float result;
};

/*
 * Creates/initialises a RPN Calculator. Returns a valid Calculator struct by value.
 */
Calculator newCalculator(char* expr);

/*
 * Destroys the Calculator by clearing any stack data (and freeing the memory if you are using dynamic memory allocation).
 */
void destroyCalculator(Calculator calculator);

/*
 * Evaluates the given expression held within the Calculator struct and returns the result as a float.
 */
float evaluateExpression(Calculator calculator);