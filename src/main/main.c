//
// Created by Yohann Marguier on 09/04/2025.
//

#include "../include/shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char * argv[]) {
    if (!isatty(STDIN_FILENO)) {
        fprintf(stderr, "Warning: the terminal is not interactive. Some commands could does not work correctly\n");
    }

    // load config file , if any exists in the future
    lsh_loop();
    //perform any shutdown or cleanup

    return EXIT_SUCCESS;
}
