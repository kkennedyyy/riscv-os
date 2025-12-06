// kernel_trap.c file C-level trap handler logic.
// After the assembly trap handler saves registers, this file processes the syscall
#include "uart.h"

// Called from trap.S when an ECALL happens
void kernel_trap() {
    long syscall_num, arg0;

    // Retrieve syscall number and argument from registers
    asm volatile("mv %0, a7" : "=r"(syscall_num));
    asm volatile("mv %0, a0" : "=r"(arg0));

    // Syscall 1: print string
    if (syscall_num == 1) {
        char* p = (char*)arg0;
        while (*p) uart_putc(*p++);
    }

    // Syscall 2: exit program
    if (syscall_num == 2) {
        uart_print("[kernel] program exited\n");
        uart_print("[kernel] halting CPU...\n");
        // Halt the CPU
        while (1) {}
}
}
