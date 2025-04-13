//
// Created by Yohann Marguier on 12/04/2025.
//

#include <stdio.h>
#include "../include/key_events.h"
#include "../include/utils.h"

#define RESET_LINE "\033[2K\033[G"
#define ESC 27
#define OPEN_BRACKET 91
#define UP_ARROW 65
#define DOWN_ARROW 66


/**
 * @brief executes actions caused by key events
 *
 * @param c is the first char we want to check its an ANSI Escape
 * @param buffer stores the current command line typed by the user
 * @param history stocks all old commands executed by the shell
 * @return 1 is an event is handled, else 0
 */
int keyEventHandler(int c, char* buffer, cmd_history_t history){
    if(c == ESC){
        c = getchar();
        if(c == OPEN_BRACKET){
            c = getchar();
            switch (c) {
                case UP_ARROW:
                    upArrowEvent(buffer, &history);
                    return 1;
                case DOWN_ARROW:
                    downArrowEvent(buffer, &history);
                    return 1;
            }
        }
    }
    return 0;
}

/**
 * @brief scroll up in the commands history of the shell and displays the correct command
 *
 * @param buffer stores the current command line typed by the user
 * @param history stocks all old commands executed by the shell
 */
void upArrowEvent(char *buffer, cmd_history_t *history){
    int cursor = history->cursor;

    if(cursor >= 0 && history->length != 0) {
        const char* cmd = history->buffer[cursor];
        printf("%s> ", RESET_LINE);
        snprintf(buffer, 1024, "%s", cmd);
        printf("%s", buffer);
        fflush(stdout);
        if(cursor > 0){
            history->cursor--;
        }
    }
}

/**
 * @brief scroll down in the commands history of shell and displays the correct command
 *
 * @param buffer stores the current command line typed by the user
 * @param history stocks all old commands executed by the shell
 */
void downArrowEvent(char *buffer, cmd_history_t *history){
    int cursor = history->cursor;

    if(cursor < history->length && history->length != 0) {
        const char* cmd = history->buffer[cursor];
        printf("%s> ", RESET_LINE);
        snprintf(buffer, 1024, "%s", cmd);
        printf("%s", buffer);
        fflush(stdout);
        if(cursor < history->length - 1){
            history->cursor++;
        }
    }
}