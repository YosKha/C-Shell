//
// Created by Yohann Marguier on 10/04/2025.
//
#include "../include/builtins.h"
#include <unistd.h>
#include <stdio.h>


cmd_t builtins_list[] = {
        {"cd", &lsh_cd},
        {"help", &lsh_help},
        {"exit", &lsh_exit}
};

int nb_builtins = sizeof(builtins_list) / sizeof(cmd_t);

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

    for (i = 0; i < nb_builtins; i++) {
        cmd_t cmd = builtins_list[i];
        printf("  %s\n", cmd.func);
    }

    printf("Use the man builtins for information on other programs.\n");
    return 1;
}

int lsh_exit(char **args){
    return 0;


}