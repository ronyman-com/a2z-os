#include <stdint.h>

uint32_t page_directory[1024] __attribute__((aligned(4096)));
uint32_t first_page_table[1024] __attribute__((aligned(4096)));

void paging_install() {
    // Map the first 4MB of memory
    for (int i = 0; i < 1024; i++) {
        first_page_table[i] = (i * 0x1000) | 3; // Mark as present and writable
    }

    page_directory[0] = ((uint32_t)first_page_table) | 3;

    // Load the page directory
    asm volatile("mov %0, %%cr3" : : "r"(page_directory));
    asm volatile("mov %cr0, %eax; or $0x80000000, %eax; mov %eax, %cr0"); // Enable paging
}
