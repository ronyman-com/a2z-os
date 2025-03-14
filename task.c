#include <stdint.h>

struct task {
    uint32_t esp;
    uint32_t eip;
};

struct task tasks[10];
uint8_t current_task = 0;

void task_switch() {
    // Save the current task's state
    asm volatile("mov %%esp, %0" : "=r"(tasks[current_task].esp));
    asm volatile("mov %%eip, %0" : "=r"(tasks[current_task].eip));

    // Switch to the next task
    current_task = (current_task + 1) % 10;
    asm volatile("mov %0, %%esp" : : "r"(tasks[current_task].esp));
    asm volatile("mov %0, %%eip" : : "r"(tasks[current_task].eip));
}
