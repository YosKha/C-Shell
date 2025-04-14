//
// Created by Yohann Marguier on 12/04/2025.
//

#ifndef SHELL_KEY_EVENTS_H
#define SHELL_KEY_EVENTS_H

#include "../include/utils.h"
#include "../include/input_buffer.h"

int keyEventHandler(int c, cmd_history_t history, input_buffer_t *buffer);

void upArrowEvent(cmd_history_t*, input_buffer_t *);
void downArrowEvent(cmd_history_t*, input_buffer_t *);
void leftArrowEvent(input_buffer_t*);
void rightArrowEvent(input_buffer_t*);


#endif //SHELL_KEY_EVENTS_H
