#include "user.h"'

#define CMD_INPUT_HELLO     strcmp(cmdline, "hello") == 0
#define CMD_INPUT_EXIT      strcmp(cmdline, "exit") == 0
#define CMD_INPUT_READFILE  strcmp(cmdline, "readfile") == 0
#define CMD_INPUT_WRITEFILE strcmp(cmdline, "writefile") == 0

void main(void) {
    while (1) {
        printf("> ");
        char cmdline[128];
        bool cmdline_too_long = false;
        for (int i = 0;; i++) {
            char ch = getchar();
            putchar(ch);
            if (i == sizeof(cmdline) - 1) {
                printf("command line too long\n");
                cmdline_too_long = true;
                break;
            }
            else if (ch == '\r') {
                printf("\n");
                cmdline[i] = '\0';
                break;
            }
            else {
                cmdline[i] = ch;
            }
        }
        if(cmdline_too_long) continue;

        if (CMD_INPUT_HELLO){
            printf("Hello world from shell!\n");
        }
        else if (CMD_INPUT_EXIT) {
            exit();
        }
        else if (CMD_INPUT_READFILE) {
            char buf[128];
            int len = readfile("hello.txt", buf, sizeof(buf));
            buf[len] = '\0';
            printf("%s\n", buf);
        }
        else if (CMD_INPUT_WRITEFILE) {
            writefile("hello.txt", "Hello from shell!\n", 19);
        }
        else {
            printf("unknown command: %s\n", cmdline);
        }
    }
}
