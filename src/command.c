//
// Created by Yohann Marguier on 10/04/2025.
//
#include "command.h"
#include <unistd.h>
#include <stdio.h>


cmd_t command_list[] = {
        {"cd", &lsh_cd},
        {"help", &lsh_help},
        {"exit", &lsh_exit}
};

int nb_commands = sizeof(command_list)/sizeof(cmd_t);

int lsh_cd(char** args){
    if(args[1] == NULL){
        fprintf(stderr, "lsh : expected argument to \"cd\"\n");
    }else{
        if (chdir(args[1]) == -1){
            perror("lsh");
        }
    }
    return 1;
}

int lsh_help(char **args){
    int i;
    printf("Yohann Marguier's LSH\n");
    printf("Type program names and arguments, and hit enter.\n");
    printf("The following are built in:\n");

    for (i = 0; i < nb_commands; i++) {
        cmd_t cmd = command_list[i];
        printf("  %s\n", cmd.func);
    }

    printf("Use the man command for information on other programs.\n");
    return 1;
}

int lsh_exit(char **args){
    return 0;


}