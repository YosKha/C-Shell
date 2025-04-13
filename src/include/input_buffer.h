//
// Created by Yohann Marguier on 13/04/2025.
//

#ifndef SHELL_INPUT_BUFFER_H
#define SHELL_INPUT_BUFFER_H

typedef struct input_buffer{
    int cursor;
    char *data;
    int size;
    int capacity;
} input_buffer_t;

input_buffer_t *initInputBuffer(int dataSize);
void freeInputBuffer(input_buffer_t *);

int isInputBufferEmpty(input_buffer_t);

int addToInputBuffer(input_buffer_t *, char);
int removeFromInputBuffer(input_buffer_t*);
int clearInputBuffer(input_buffer_t *);

void printInputBuffer(input_buffer_t);
char * getDataFromInputBuffer(input_buffer_t);

int shiftRigthInputBuffer(input_buffer_t*);
int shiftLefthInputBuffer(input_buffer_t*);

#endif //SHELL_INPUT_BUFFER_H
