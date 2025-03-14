#include "idt.h"
#include "keyboard.h"

void main() {
    idt_install();
    keyboard_install();
    asm volatile("sti"); // Enable interrupts
    print_string("A2Z OS: Keyboard interrupt handling enabled!");
}
