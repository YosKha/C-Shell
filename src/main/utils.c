//
// Created by Yohann Marguier on 10/04/2025.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/utils.h"
#include <string.h>

const int LSH_HISTORY_BUFSIZE = 1024;

cmd_history_t initCmdHistory(){
    cmd_history_t history;
    history.cursor = -1;
    history.length = 0;
    history.commands = malloc(sizeof(char*) * LSH_HISTORY_BUFSIZE);
    return history;
}

void freeHistory(cmd_history_t *history){
    if(history->commands){
        free(history->commands);
    }
    freeInitialCommand(history);
}

void freeInitialCommand(cmd_history_t *history) {
    if (history && history->initial_command) {
        free(history->initial_command);
        history->initial_command = NULL;
    }
}

void setInitialCommand(cmd_history_t *history, char *initCommand, int initCommandSize){
    if(history == NULL || initCommand == NULL){
        fprintf(stderr, "lsh : Invalid arguments in setInitialCommand");
        return;
    }

    history->initial_command = malloc(initCommandSize);
    if(!history->initial_command){
        perror("lsh");
        return;
    }
    memcpy(history->initial_command, initCommand, initCommandSize);
}

int pushToHistory(cmd_history_t *history, char *cmd){
    if(!history){
        fprintf(stderr, "Invalid arguments, null pointer in pushToHistory");
        return -1;
    }

    // should manage a buffer overflow with realloc
    history->commands[history->length] = strdup(cmd);
    history->cursor = history->length;
    history->length++;
    return 1;
}

char* getCmdFromHistory(cmd_history_t history, int index){
    return history.commands[index];
}

int isHistoryEmpty(cmd_history_t history){
    return history.length == 0;
}

