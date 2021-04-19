
#ifndef PIPELINE_H_
#define PIPELINE_H_

#include <stdbool.h>

#define MAX_PIPELINE_SIZE 1000

typedef int Pipe[2];

typedef void (*Function)(int input, int output);

typedef struct Pipeline {
    Function* stages;
    Pipe* pipes;
    int size;
} Pipeline;

/*
 * Creates a new empty processing pipeline.
 */
Pipeline* new_Pipeline();

/*
 * Adds the specified function to the pipeline.
 * Returns true on success and false if unable to add the new stage.
 *
 */
bool Pipeline_add(Pipeline* this, Function f);

/*
 * Executes the specified pipeline.
 */
void Pipeline_execute(Pipeline* this);


/*
 * Frees memory associated with the pipeline.
 */
void Pipeline_free(Pipeline* this);

#endif /* PIPELINE_H_ */
