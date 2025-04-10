//
// Created by Yohann Marguier on 10/04/2025.
//

#ifndef C_SHELL_COMMAND_C_H
#define C_SHELL_COMMAND_C_H

typedef int(*cmd_func_t) (char**);

typedef struct command{
    const char* name;
    cmd_func_t func;
}cmd_t;


extern int nb_commands;
extern cmd_t command_list[];


/*Commands declaration*/
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);

#endif //C_SHELL_COMMAND_C_H
