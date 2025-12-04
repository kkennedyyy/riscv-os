// uart.c file
// This writes characters to the UART memory-mapped I/O
#define UART0 0x10000000L

// Outputs a single character
void uart_putc(char c) {
    *(volatile char*)UART0 = c;
}

// Prints a whole C string
void uart_print(const char* s) {
    while (*s) uart_putc(*s++);
}

// Currently empty, but sets baud rate and configures UART
void uart_init() {}

// This file is important because it's how the kernal and syscalls print text (aka console driver)

