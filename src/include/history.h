//
// Created by Yohann Marguier on 16/04/2025.
//

#ifndef SHELL_HISTORY_H
#define SHELL_HISTORY_H

typedef struct history{
    char **commands;
    int size;
    int capacity;
    int cursor;
}history_t;


history_t *initHistory();
void freeHistory(history_t *history);
void reallocHistory(history_t *);
history_t *getCopyOfHistory(history_t*);

int isHistoryEmpty(const history_t *);

int pushIntoHistory(history_t *, char *); // should not add empty sequences: ""
char *getPreviousCommand(history_t *);
char *getNextCommand(history_t*);


#endif //SHELL_HISTORY_H
