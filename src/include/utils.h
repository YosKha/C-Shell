//
// Created by Yohann Marguier on 11/04/2025.
//

#ifndef SHELL_UTILS_H
#define SHELL_UTILS_H

extern const int LSH_HISTORY_BUFSIZE;

typedef struct args {
    int argc;
    char **argv;
} args_t;

typedef struct cmd_history{
    int cursor;
    int length;
    char **commands;
    char *initial_command;
} cmd_history_t;


cmd_history_t initCmdHistory();
void freeHistory(cmd_history_t *);
void freeInitialCommand(cmd_history_t *);
void setInitialCommand(cmd_history_t*, char*, int);
int pushToHistory(cmd_history_t *history, char *cmd);
char* getCmdFromHistory(cmd_history_t history, int index);
int isHistoryEmpty(cmd_history_t);
void resetHistoryCursor(cmd_history_t*);


#endif //SHELL_UTILS_H
