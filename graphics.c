void put_pixel(int x, int y, uint8_t color) {
    uint8_t* video_memory = (uint8_t*) 0xA0000;
    video_memory[y * 320 + x] = color;
}


void draw_window(int x, int y, int width, int height, uint8_t color) {
    for (int i = x; i < x + width; i++) {
        for (int j = y; j < y + height; j++) {
            put_pixel(i, j, color);
        }
    }
}


void draw_button(int x, int y, int width, int height, char* label) {
    draw_window(x, y, width, height, 0x07); // Gray background
    draw_text(x + 5, y + 5, label, 0x00); // Black text
}
