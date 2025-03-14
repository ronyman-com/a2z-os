#include "idt.h"
#include "keyboard.h"
#include "paging.h"
#include "fs.h"
#include "task.h"


void main() {
    idt_install();
    keyboard_install();
    paging_install();
    task_switch(); // Example of task switching
    fs_init();
    fs_create_file("test.txt", 10, "Hello A2Z");
    asm volatile("sti"); // Enable interrupts
    print_string("A2Z OS: Keyboard interrupt handling enabled!");
}

