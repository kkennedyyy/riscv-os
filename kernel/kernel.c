// kernel.c file
// This file initalizes UART, sets up the trap handler, and jumps to user mode to run user code
#include "uart.h"

extern void user_start();
extern void trap_handler();

void enter_user_mode(unsigned long pc) {
    unsigned long sstatus;

    // Set SPP = 0 (return to user mode)
    asm volatile("csrr %0, sstatus" : "=r"(sstatus));
    sstatus &= ~(1 << 8);
    asm volatile("csrw sstatus, %0" :: "r"(sstatus));

    // Set return PC for sret
    asm volatile("csrw sepc, %0" :: "r"(pc));

    asm volatile("sret");
}

void kernel_main() {
    uart_init();
    uart_print("Booting minimal RISC-V OS...\n");

    // Installs trap handler (Chat said this was redundant, however without it the syscalls do not work)
    asm volatile("la t0, trap_handler");
    asm volatile("csrw stvec, t0");

    uart_print("Jumping to user program...\n");
    enter_user_mode((unsigned long)user_start);

    while (1) {}
}
