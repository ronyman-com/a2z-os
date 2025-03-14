void main() {
    char* video_memory = (char*) 0xb8000; // Video memory address for text mode
    *video_memory = 'A';                  // Print 'A'
    video_memory += 2;
    *video_memory = '2';                  // Print '2'
    video_memory += 2;
    *video_memory = 'Z';                  // Print 'Z'
}




void print_string(char* str) {
    char* video_memory = (char*) 0xb8000;
    while (*str) {
        *video_memory = *str;
        video_memory += 2;
        str++;
    }
}

void main() {
    print_string("Welcome to A2Z Operator System!");
}
