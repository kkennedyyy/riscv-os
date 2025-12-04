// kernel_trap.c file
// After the assembly trap handler saves registers, this file processes the syscall
#include "uart.h"

// Called from trap.S when an ECALL happens
void kernel_trap() {
    long syscall_num, arg0;

    // Extract registers the trap.S saved
    asm volatile("mv %0, a7" : "=r"(syscall_num));
    asm volatile("mv %0, a0" : "=r"(arg0));

    if (syscall_num == 1) {
        // Write character syscall
        uart_putc((char)arg0);
    }
}

// This file is important because its where the OS can be exapnded:
// If I wanted to add more file system calls, process control, timers, and memory allocation I would do it here.
