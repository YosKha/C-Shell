//
// Created by Yohann Marguier on 13/04/2025.
//

#include "../include/input_buffer.h"
#include <stdio.h>

int main(){
    input_buffer_t *inputBuffer=initInputBuffer();

    printInputBuffer(inputBuffer);
    printf("VIDE ? :%d\n", isInputBufferEmpty(inputBuffer));
    addToInputBuffer(inputBuffer, 'f');
    printInputBuffer(inputBuffer);
    printf("\n");
    addToInputBuffer(inputBuffer, 'g');
    addToInputBuffer(inputBuffer, 'h');
    addToInputBuffer(inputBuffer, 'a');
    printInputBuffer(inputBuffer);
    printf("\n");

    removeFromInputBuffer(inputBuffer);
    printInputBuffer(inputBuffer);
    printf("\n");
    addToInputBuffer(inputBuffer, 'a');
    printInputBuffer(inputBuffer);
    printf("\n");

    printf("VIDE ? :%d\n", isInputBufferEmpty(inputBuffer));

    shiftLeftInputBuffer(inputBuffer);
    printInputBuffer(inputBuffer);
    printf("\n");

    shiftLeftInputBuffer(inputBuffer);
    shiftLeftInputBuffer(inputBuffer);
    shiftLeftInputBuffer(inputBuffer);
    printInputBuffer(inputBuffer);
    printf("\n");

    addToInputBuffer(inputBuffer, 'a');
    printInputBuffer(inputBuffer);
    printf("\n");
    addToInputBuffer(inputBuffer, 'b');
    printInputBuffer(inputBuffer);
    printf("\n");

    removeFromInputBuffer(inputBuffer);removeFromInputBuffer(inputBuffer);
    printInputBuffer(inputBuffer);
    printf("\n");

    shiftRightInputBuffer(inputBuffer);
    shiftRightInputBuffer(inputBuffer);
    printInputBuffer(inputBuffer);
    printf("\n");

    addToInputBuffer(inputBuffer, '_');
    printInputBuffer(inputBuffer);
    printf("\n");
    removeFromInputBuffer(inputBuffer);
    printInputBuffer(inputBuffer);
    printf("\n");

    freeInputBuffer(inputBuffer);
    return 0;
}