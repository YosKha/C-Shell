//
// Created by Yohann Marguier on 10/04/2025.
//

#include "stdlib.h"
#include <string.h>
#include "../include/utils.h"

const int LSH_HISTORY_BUFSIZE = 1024;

cmd_history_t initCmdHistory(){
    cmd_history_t history;
    history.cursor = 0;
    history.length = 0;
    history.buffer = malloc(sizeof(char*) * LSH_HISTORY_BUFSIZE);
    return history;
}

void freeHistory(cmd_history_t history){
    free(history.buffer);
}

int pushToHistory(cmd_history_t *history, char *cmd){
    history->buffer[history->length] = strdup(cmd);
    history->cursor = history->length;
    history->length++;
    return 1;
}

char* getCmdFromHistory(cmd_history_t history, int index){
    return history.buffer[index];
}

int isHistoryEmpty(cmd_history_t history){
    return history.length == 0;
}

void resetHistoryCursor(cmd_history_t *history){
    if(isHistoryEmpty(*history)){
        history->cursor = 0;
    }else{
        history->cursor = history->length-1;
    }
}

