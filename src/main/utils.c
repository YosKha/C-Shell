//
// Created by Yohann Marguier on 10/04/2025.
//

#include <termios.h>
#include <unistd.h>

void enableRawMode(void){
    struct termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // disable canonic mode
    newt.c_lflag &= ~(ICANON | ECHO);

    // enable changes
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}