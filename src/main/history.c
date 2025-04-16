//
// Created by Yohann Marguier on 16/04/2025.
//
#include "../include/history.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define HISTORY_BUFSIZE 256

history_t *initHistory(){
    history_t *history = malloc(sizeof(history_t));
    if(!history){
        fprintf(stderr, "lsh: malloc failed in initHistory");
        return NULL;
    }

    history->commands = malloc(sizeof (char *) * HISTORY_BUFSIZE);
    if(!history->commands){
        free(history);
        fprintf(stderr, "lsh : malloc failed in initHistory");
        return NULL;
    }
    history->size = 0;
    history->cursor = 0;
    history->capacity = HISTORY_BUFSIZE;
    return history;
}

void freeHistory(history_t *history){
    if(history) {
        if (history->commands) {
            free(history->commands);
        }
        free(history);
    }
}

void reallocHistory(history_t *history){
    if(!history){
        fprintf(stderr, "lsh : invalid argument in reallocHistory, null-pointer");
        return;
    }
    int newCapacity = history->capacity + HISTORY_BUFSIZE;
    realloc(history->commands, newCapacity);
    if(!history->commands){
        fprintf(stderr, "lsh : realloc failed in reallocHistory");
        return;
    }
    history->capacity = newCapacity;
}

history_t *getCopyOfHistory(history_t *history){
    history_t *copiedHistory = malloc(sizeof(history_t));

    copiedHistory->commands = malloc(sizeof(char *) * history->capacity);
    if(!copiedHistory->commands){
        fprintf(stderr, "lsh : malloc failed in getCopyOfHistory");
        return NULL;
    }
    memcpy(copiedHistory->commands, history->commands, history->size);

    copiedHistory->capacity = history->capacity;
    copiedHistory->size = history->size;
    copiedHistory->cursor = history->cursor;
    return copiedHistory;
}


int isHistoryEmpty(const history_t* history){
    return  history->size == 0;
}

int pushIntoHistory(history_t *history, char* newCommand){
    if(!history){
        fprintf(stderr, "invalid argument null-pointer passed");
        return -1;
    }
    if(history->size == history->capacity){
        reallocHistory(history);
    }
    history->commands[history->size] = newCommand;
    return 0;
}

char *getPreviousCommand(history_t *history){
    if(history->cursor == 0){
        return NULL;
    }
    history->cursor--;
    return history->commands[history->cursor];
}

char *getNextCommand(history_t *history){
    if(history->cursor == history->size){
        return NULL;
    }
    history->cursor++;
    return history->commands[history->cursor];
}