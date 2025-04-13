//
// Created by Yohann Marguier on 12/04/2025.
//

#ifndef SHELL_KEY_EVENTS_H
#define SHELL_KEY_EVENTS_H

#include "../include/utils.h"

int keyEventHandler(int, char *, cmd_history_t);

void upArrowEvent(char*, cmd_history_t*);
void downArrowEvent(char*, cmd_history_t*);


#endif //SHELL_KEY_EVENTS_H
