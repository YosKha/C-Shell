//
// Created by Yohann Marguier on 12/04/2025.
//

#ifndef SHELL_KEY_EVENTS_H
#define SHELL_KEY_EVENTS_H

#include "../include/utils.h"

int keyEventHandler(int c, cmd_history_t history, char *buffer, int);

void upArrowEvent(cmd_history_t*, char*, int);
void downArrowEvent(cmd_history_t*, char*, int);
void leftArrowEvent(void);
void rightArrowEvent(void);


#endif //SHELL_KEY_EVENTS_H
