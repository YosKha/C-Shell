//
// Created by Yohann Marguier on 11/04/2025.
//

#ifndef SHELL_SHELL_H
#define SHELL_SHELL_H

#include "../include/utils.h"

char *lsh_read_line(void);
args_t lsh_parse(char *);
int lsh_launch(args_t);
int lsh_execute(args_t);

void lsh_loop(void);

#endif //SHELL_SHELL_H
