void keyboard_handler() {
    uint8_t scancode = inb(0x60); // Read from keyboard port
    char c = scancode_to_ascii(scancode); // Convert scancode to ASCII
    print_character(c); // Print the character to the screen
}

void read_input(char* buffer) {
    int i = 0;
    while (1) {
        char c = get_char(); // Get a character from keyboard input
        if (c == '\n') {
            buffer[i] = '\0';
            break;
        } else {
            buffer[i++] = c;
        }
    }
}
