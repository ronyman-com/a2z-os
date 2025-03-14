#include "idt.h"
#include "keyboard.h"
#include "paging.h"

void main() {
    idt_install();
    keyboard_install();
     paging_install();
    asm volatile("sti"); // Enable interrupts
    print_string("A2Z OS: Keyboard interrupt handling enabled!");
}

