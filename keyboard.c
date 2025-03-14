void keyboard_handler() {
    uint8_t scancode = inb(0x60); // Read from keyboard port
    char c = scancode_to_ascii(scancode); // Convert scancode to ASCII
    print_character(c); // Print the character to the screen
}
