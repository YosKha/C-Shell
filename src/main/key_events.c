//
// Created by Yohann Marguier on 12/04/2025.
//

#include <stdio.h>
#include "../include/key_events.h"
#include "../include/utils.h"

#define RESET_LINE "\033[2K\033[G"
#define MOVE_RIGHT_CURSOR "\033[C"
#define MOVE_LEFT_CURSOR "\033[D"
#define ESC 27
#define OPEN_BRACKET 91
#define UP_ARROW 65
#define DOWN_ARROW 66
#define RIGHT_ARROW 67
#define LEFT_ARROW 68


/**
 * @brief executes actions caused by key events
 *
 * @param c is the first char we want to check its an ANSI Escape
 * @param buffer stores the current command line typed by the user
 * @param history stocks all old commands executed by the shell
 * @return 1 is an event is handled, else 0
 */
int keyEventHandler(int c, cmd_history_t history, char* buffer, int bufsize){
    if(c == ESC){
        c = getchar();
        if(c == OPEN_BRACKET){
            c = getchar();
            switch (c) {
                case UP_ARROW:
                    upArrowEvent(&history, buffer, bufsize);
                    return 1;
                case DOWN_ARROW:
                    downArrowEvent( &history, buffer,bufsize);
                    return 1;
                case RIGHT_ARROW:
                    rightArrowEvent();
                    return 1;
                case LEFT_ARROW:
                    leftArrowEvent();
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
void upArrowEvent(cmd_history_t *history, char *buffer, int bufsize){
    int cursor = history->cursor;

    // checks limits of the history
    if(cursor >= 0) {
        // memorizes the input of the user
        if(cursor == 0){
            setInitialCommand(history, buffer, bufsize);
        }

        // gets the targeted command
        const char* cmd = history->commands[cursor];
        // modifies the buffer to match the targeted command
        snprintf(buffer, 1024, "%s", cmd);
        // displays the targeted command
        printf("%s> ", RESET_LINE);
        printf("%s", buffer);
        fflush(stdout);
        // updates the cursor
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
void downArrowEvent(cmd_history_t *history, char *buffer, int bufsize){
    int cursor = history->cursor;

    // checks the limits of the history
    if(cursor < history->length) {
        // updates the cursor
        if(cursor < history->length - 1){
            history->cursor++;
        }
        //gets the targeted command
        const char* cmd = history->commands[cursor];
        //modifies the buffer to match the targeted command
        snprintf(buffer, 1024, "%s", cmd);
        //displays the targeted command
        printf("%s> ", RESET_LINE);
        printf("%s", buffer);
        fflush(stdout);
    }
}


void rightArrowEvent(){
    printf("%s", MOVE_RIGHT_CURSOR);
}

void leftArrowEvent(){
    printf("%s", MOVE_LEFT_CURSOR);
}