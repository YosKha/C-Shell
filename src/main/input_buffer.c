//
// Created by Yohann Marguier on 13/04/2025.
//

#include "../include/input_buffer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INPUT_BUFSIZE 1024

input_buffer_t *initInputBuffer(){
    input_buffer_t *inputBuffer = malloc(sizeof(inputBuffer));
    if(!inputBuffer){
        fprintf(stderr, "lsh : malloc failed");
        return NULL;
    }
    inputBuffer->cursor = 0;
    inputBuffer->size = 0;
    inputBuffer->data = malloc(INPUT_BUFSIZE);
    if(!inputBuffer->data){
        free(inputBuffer);
        fprintf(stderr, "lsh : malloc failed");
        return NULL;
    }
    inputBuffer->capacity = INPUT_BUFSIZE;
    return inputBuffer;
}

void freeInputBuffer(input_buffer_t *inputBuffer){
    if(inputBuffer->data){
        free(inputBuffer->data);
    }
    if(inputBuffer){
        free(inputBuffer);
    }
}

void reallocInputBuffer(input_buffer_t *inputBuffer){
    int newCapacity = inputBuffer->capacity + INPUT_BUFSIZE;
    inputBuffer = realloc(inputBuffer, newCapacity);
    if(!inputBuffer){
        fprintf(stderr, "lsh : realloc failed\n");
        return;
    }
    inputBuffer->capacity = inputBuffer->capacity + INPUT_BUFSIZE;
}


void loadIntoInitBuffer(input_buffer_t * inputBuffer, char *data, int dataSize){
    while(dataSize > inputBuffer->capacity){
        reallocInputBuffer(inputBuffer);
    }

    memcpy(inputBuffer->data, data, dataSize);
    inputBuffer->size = dataSize;
    inputBuffer->cursor = dataSize;
}


int isInputBufferEmpty(input_buffer_t inputBuffer){
    return inputBuffer.size == 0;
}

int addToInputBuffer(input_buffer_t *inputBuffer, char c){
    char *data = inputBuffer->data;
    int size = inputBuffer->size;

    // update the buffer if it is full
    if(size == inputBuffer->capacity){
        reallocInputBuffer(inputBuffer);
    }

    // add the new char in the correct address
    int cursor = inputBuffer->cursor;
    if(cursor != size){
        memmove(data+cursor+1, data + cursor, size - cursor);
    }
    data[cursor] = c;

    return 0;
}

int removeFromInputBuffer(input_buffer_t *inputBuffer){
    char *data = inputBuffer->data;
    int size = inputBuffer->size;
    int cursor = inputBuffer->cursor;

    // add the new char in the correct address
    if(cursor != size){
        memmove(data+cursor-1, data + cursor, size - cursor);
    }

    return 0;
}


void printInputBuffer(input_buffer_t inputBuffer){
    fwrite(inputBuffer.data, sizeof(char), inputBuffer.size, stdout);
    fflush(stdout);
}

int shiftRightInputBuffer(input_buffer_t *inputBuffer){
    if(inputBuffer->cursor < inputBuffer->size){
        inputBuffer->cursor++;
        return 1;
    }
    return 0;
}

int shiftLeftInputBuffer(input_buffer_t *inputBuffer){
    if(inputBuffer->cursor > 0){
        inputBuffer->cursor--;
        return 1;
    }
    return 0;
}


