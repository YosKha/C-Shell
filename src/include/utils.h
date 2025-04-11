//
// Created by Yohann Marguier on 11/04/2025.
//

#ifndef SHELL_UTILS_H
#define SHELL_UTILS_H

#define LSH_HISTORY_BUFSIZE 1024;

typedef struct args {
    int argc;
    char **argv;
} args_t;

typedef struct cmd_history{
    int cursor;
    int length;
    args_t history[];
} cmd_history_t;

void enableRawMode(void);
char *catchUserInput(void);

int pushToHistory(cmd_history_t history, args_t cmd);
args_t getCommandeFromHistory(cmd_history_t history, int index);


#endif //SHELL_UTILS_H
