//
// Created by Yohann Marguier on 13/04/2025.
//

#include "../include/input_buffer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

input_buffer_t *initInputBuffer(int dataSize){
    input_buffer_t *inputBuffer = malloc(sizeof(inputBuffer));
    if(!inputBuffer){
        fprintf(stderr, "lsh : malloc failed");
        return NULL;
    }
    inputBuffer->cursor = 0;
    inputBuffer->size = 0;
    inputBuffer->data = malloc(dataSize);
    if(!inputBuffer->data){
        free(inputBuffer);
        fprintf("lsh : malloc failed");
        return NULL;
    }
    inputBuffer->capacity = dataSize;
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

int isInputBufferEmpty(input_buffer_t inputBuffer){
    return inputBuffer.size == 0;
}

int addToInputBuffer(input_buffer_t *inputBuffer, char c){
    char *data = inputBuffer->data;
    int size = inputBuffer->size;
    if(size == inputBuffer->capacity){

    }
    int cursor = inputBuffer->cursor;
    if(cursor != size){
        memmove(data+cursor+1, data + cursor, size - cursor);
    }
    data[cursor] = c;

    return 0;
}

int shiftRigthInputBuffer(input_buffer_t *inputBuffer){
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


