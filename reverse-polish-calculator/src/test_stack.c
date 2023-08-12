/*
 * test_stack.c
 *
 * Very simple unit test file for Stack functionality.
 *
 */

#include <stdio.h>
#include "stack.h"
#include "myassert.h"



/*
 * The stack to use during tests
 */
static Stack* stack;

#ifndef DYNAMIC // if we're not using dynamic memory allocation in our stack implementation, we need an actual stack struct in addition to the pointer to the stack
static Stack stack_s;
#endif


/*
 * The number of tests that succeeded
 */
static int success_count = 0;

/*
 * The total number of tests run
 */
static int total_count = 0;


/*
 * Setup function to run prior to each test
 */
#ifdef DYNAMIC // if we are using dynamic memory allocation in our Stack implementation

void setup() {
    stack = new_Stack();
}

#else // we are not using dynamic memory allocation so initialise "Stack* stack" to contain the pointer to the stack struct

void setup() {
    stack_s = new_Stack();
    stack = &stack_s;
}

#endif


/*
 * Teardown function to run after each test
 */
void teardown(){
    Stack_destroy(stack);
}

/*
 * This function is called multiple times from main for each user-defined test function
 */
void runTest(int (*testFunction)()) {
    total_count++;
    setup();

    if (testFunction()) success_count++;

    teardown();
}


/*
 * Two sample user-defined tests included below.
 * You will have to write many more tests.
 *
 * Each test function should return TEST_SUCCESS at the end.
 * Test functions can contain more than one assertion.
 *
 * If any assertion fails, the function name and line number
 * will be printed and the test will return a failure value.
 *
 * You will have to call runTest on your test functions in main below.
 */


/*
 * Checks that the Stack constructor returns a non-NULL pointer.
 */
int newStackIsNotNull() {
    assert(stack != NULL);
    return TEST_SUCCESS;
}

/*
 * Checks that the size of an empty stack is 0.
 */
int newStackSizeZero() {
    assert(Stack_size(stack) == 0);
    return TEST_SUCCESS;
}

/*
 * Checks if an element has been pushed onto the stack.
 */
int pushOneElement() {
    assert(Stack_push(stack, 0));
    assert(Stack_size(stack) == 1);
    return TEST_SUCCESS;
}

/*
 * Checks if multiple elements can be pushed onto the stack, up to the max capacity.
 */
int pushMultipleElements() {
    for (int i = 0; i < stack->capacity; i++) {
        assert(Stack_push(stack, i));
        assert(Stack_size(stack) == i + 1);
    }
    return TEST_SUCCESS;
}

/*
 * Checks if an element can be popped from the stack and that the popped value is correct.
 */
int popOneElement() {
    float retval;
    assert(pushOneElement());
    assert(Stack_pop(stack, &retval));
    assert(retval == 0);
    assert(Stack_size(stack) == 0);
    return TEST_SUCCESS;
}

/*
 * Checks if multiple elements can be popped from the stack and that all popped values are correct.
 */
int popMultipleElements() {
    float retval;
    for (int i = 0; i < stack->capacity; i++) {
        assert(Stack_push(stack, i));
        assert(Stack_size(stack) == i + 1);
    }
    for (int i = stack->capacity - 1; i > 0; i--) {
        assert(Stack_pop(stack, &retval));
        assert(retval == i);
        assert(Stack_size(stack) == i);
    }
    return TEST_SUCCESS;
}

/*
 * Checks if you are unable to push onto a stack at maximum capacity.
 */
int pushFullStack() {
    for (int i = 0; i < stack->capacity; i++) {
        assert(Stack_push(stack, i));
    }
    assert(!Stack_push(stack, 0));
    return TEST_SUCCESS;
}

/*
 * Checks if you are unable to pop from an empty stack.
 */
int popEmptyStack() {
    float retval;
    assert(!Stack_pop(stack, &retval));
    return TEST_SUCCESS;
}

/*
 * Checks if the stack is empty after a push and a pop.
 */
int isStackEmpty() {
    float retval;
    assert(Stack_push(stack, 0));
    assert(!Stack_isEmpty(stack));
    assert(Stack_pop(stack, &retval));
    assert(Stack_isEmpty(stack));
    return TEST_SUCCESS;
}

/*
 * Checks if the stack is empty after it has been cleared.
 */
int hasStackCleared() {
    assert(Stack_push(stack, 0));
    Stack_clear(stack);
    assert(Stack_isEmpty(stack));
    return TEST_SUCCESS;
}

/*
 * Main function for the Stack tests which will run each user-defined test in turn.
 */
int main() {
    runTest(newStackIsNotNull);
    runTest(newStackSizeZero);
    runTest(pushOneElement);
    runTest(pushMultipleElements);
    runTest(popOneElement);
    runTest(popMultipleElements);
    runTest(pushFullStack);
    runTest(popEmptyStack);
    runTest(isStackEmpty);
    runTest(hasStackCleared);

    printf("Stack Tests complete: %d / %d tests successful.\n----------------\n", success_count, total_count);

}
