//
// Created by Yohann Marguier on 11/04/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include "../include/builtins.h"
#include "../include/shell.h"
#include "../include/key_events.h"

#define LSH_RL_BUFSIZE 1024
#define LSH_TK_BUFSIZE 64
#define LSH_TK_DELIM " \t\r\n\a"


/**
 * @brief Read line enter in the terminal. It takes charges of key events
 *
 * @return char* of the line read in the terminal
 */
char* lsh_read_line(cmd_history_t history){
    int bufsize = LSH_RL_BUFSIZE;
    char* buffer = malloc(sizeof(char) * bufsize);
    int position = 0;
    int c;

    // check malloc
    if (!buffer) {
        fprintf(stderr, "lsh : malloc failed\n");
        exit(EXIT_FAILURE);
    }

    while(1){
        c = getchar(); // this char is an int because we want to compare it with EOF(int)

        // catch ANSI events (up/down arrow, ...)
        if(keyEventHandler(c, buffer, history)){
            continue;
        }

        printf("%c", c); // in the raw mode of the terminal, char is not automatically displayed;

        if(c == '\n'|| c == EOF){ // EOF = End Of File (int)
            return buffer;
        }else{
            buffer[position] = c;
        }
        position++;

        // realloc buffer is the user input is larger than the buffer;
        if (position >= bufsize) {
            bufsize += LSH_RL_BUFSIZE;

            buffer = realloc(buffer, bufsize);
            if (!buffer) {
                fprintf(stderr, "lsh : realloc failed\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}


/**
 * @brief split different arguments from a line builtins
 *
 * @param[in] the line builtins
 * @return different argument split in an args_t
 */
args_t lsh_parse(char* line){
    int bufsize = LSH_TK_BUFSIZE;
    char **token_buffer = malloc(sizeof(char *) * LSH_TK_BUFSIZE);
    char *token;
    int position = 0;
    args_t res;

    // check malloc
    if (!token_buffer){
        fprintf(stderr, "lsh : malloc failed");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, LSH_TK_DELIM);
    while(token != NULL){
        token_buffer[position] = token;
        position++;

        if(position > bufsize){
            bufsize += LSH_TK_BUFSIZE;
            token_buffer = realloc(token_buffer, bufsize);
            if(!token_buffer){
                fprintf(stderr, "lsh : realloc failed");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, LSH_TK_DELIM);
    }
    token_buffer[position] = NULL;
    res.argv = token_buffer;
    res.argc = position;
    return res;
}


/**
 * @brief execute an external program given by args
 *
 * @param args of the program to execute
 * @return 1
 */
int lsh_launch(args_t args){
    pid_t pid;
    int status;
    char **argv = args.argv;

    /* execute an extern program */
    switch (pid = fork()) {
        case 0 :
            /* Child process */
            if(execvp(argv[0], argv) == -1){
                perror("lsh");
            }
            exit(EXIT_FAILURE);
        case -1 :
            /*Error forking*/
            perror("lsh");
            break;
        default:
            do {
                waitpid(pid, &status, WUNTRACED);
            }while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1; // execute only by the parent process
}


/**
 * @brief execute a builtins line. Either the builtins line is a builtin builtins (cd, help, ....) or
 *        execute external program with lsh_launch
 *
 * @param args of the builtins to execute
 * @return the response on the execution. return 1 to continue continue, 0 to end the shell
 */
int lsh_execute(args_t args){
    char **argv = args.argv;
    if(argv[0] == NULL){
        return 1;
    }

    /* execute specific shell commands */
    for(int i =0; i<nb_builtins; i++){
        cmd_t cmd = builtins_list[i];
        if(strcmp(argv[0], cmd.name) == 0){
            return (cmd.func)(argv);
        }
    }
    return lsh_launch(args);
}


/**
 * @brief start the main loop of the program to read and execute programs and commands.
 */
void lsh_loop(void){
    char *line;
    args_t args;
    int status;
    cmd_history_t shell_history = initCmdHistory();
    pushToHistory(&shell_history, "man man");
    pushToHistory(&shell_history, "gcc -v");
    enableRawMode();

    do {
        printf("> ");
        line = lsh_read_line(shell_history);
        pushToHistory(&shell_history, line);
        args = lsh_parse(line);
        status = lsh_execute(args);
    }while(status);

    freeHistory(shell_history);
}


/**
 * @brief active the Raw Mode Into the terminal : All user input are interpreted instantaneously
 */
void enableRawMode(void){
    struct termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // disable canonic mode
    newt.c_lflag &= ~(ICANON | ECHO);

    // enable changes
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}