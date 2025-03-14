#include <stdint.h>
#include "string.h"

void shell_execute(char* command) {

    if (strncmp(command, "resolution ", 11) == 0) {
            uint32_t width = atoi(command + 11);
            uint32_t height = atoi(command + 15);
            set_resolution(width, height);
        }
    if (strcmp(command, "help") == 0) {
        print_string("Available commands: help, clear, echo");
    } else if (strcmp(command, "clear") == 0) {
        clear_screen();
    } else if (strncmp(command, "echo ", 5) == 0) {
        print_string(command + 5); // Print everything after "echo "
    } else {
        print_string("Unknown command. Type 'help' for a list of commands.");
    }
    
}

void shell_run() {
    char input[100];
    while (1) {
        print_string("A2Z> ");
        read_input(input);
        shell_execute(input);
    }
}

