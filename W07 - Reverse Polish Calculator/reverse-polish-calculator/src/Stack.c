/*
 * Stack.c
 *
 * Array-based Stack implementation.
 *
 */

#include "Stack.h"

#include <stdlib.h>

#ifdef DYNAMIC

Stack* new_Stack() {
    Stack* this = malloc(sizeof(Stack));
    this->capacity = MAX_CAPACITY;
    this->array = malloc(this->capacity * sizeof(float));
    this->top = -1;
    return this;
}

#else

Stack new_Stack() {
    Stack this;
    return this;
}

#endif


bool Stack_push(Stack* this, float element) {
    if (Stack_size(this) == this->capacity)
        return false;
    this->array[++this->top] = element;
    return true;
}

bool Stack_pop(Stack* this, float* retval) {
    if (Stack_isEmpty(this))
        return false;
    *retval = this->array[this->top--];
    return true;
}

int Stack_size(Stack* this) {
    return this->top + 1;
}

bool Stack_isEmpty(Stack* this) {
	return Stack_size(this) == 0;
}

void Stack_clear(Stack* this) {
    this->top = -1;
}

void Stack_destroy(Stack* this) {
    Stack_clear(this);
    // Free array before struct to remove possibility of memory leaks
    free(this->array);
    free(this);
}
