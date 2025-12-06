// uart.c file - UART driver for QEMU virt machine.
#define UART0 0x10000000L

void uart_putc(char c) {
    *(volatile char*)UART0 = c;
}

void uart_print(const char* s) {
    while (*s) uart_putc(*s++);
}

// UART initialization 
void uart_init() {}

