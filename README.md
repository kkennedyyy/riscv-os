## Program 2:
Group Members: Kennedy Poag

This project implements a minimal operating system for the RISC-V architecture, written in C and RISC-V assembly. It runs on QEMU's virtual machine using OpenSBI, handles syscalls, switches between kernel and user mode, and prints to the console through UART.

## Features
Kernel Boot Process
- Boots at _start in machine/supervisor mode
- Sets up a kernel stack
- Installs a trap handler via stvec
- Jumps into kernel_main()

Kernel Functionality
- Initializes UART driver
- Prints boot messages
- Sets SPP flag to return in user mode
- Transfers control to a user program

User Mode Execution
- User program executes in U-mode
- Makes syscalls using ecall
- Syscall number passed in register a7
- Arguments passed in a0, a1, ...

Trap & Syscall Handling
- trap.S saves all registers and advances sepc
- Calls into kernel_trap.c
- Processes syscalls (currently: print character)
- Restores registers and returns to user mode using sret

## Project Structure Overview
- entry.S: First code executed; sets stack, trap vector, and jumps to kernel
- trap.S: Full trap handler: saves/restore registers, advances PC, calls C trap logic
- uart.c / uart.h: UART driver used for printing characters and strings
- kernel.c: Main kernel: UART init, trap setup, switch to user mode
- kernel_trap.c: Handles syscalls (based on values in a7/a0)
user.S	User-mode program making syscalls via ecall
- linker.ld: Defines memory layout for kernel and symbol placements
- Makefile: Builds ELF → binary, links script, runs QEMU

## Running the OS
run the command's in the following order:
1. make clean
2. make
3. qemu-system-riscv64 -machine virt -nographic -kernel kernel.bin


## Some prompts given to ChatGPT
- "Create an operating system that runs on  a RISC-V computer that supports being able to load separate programs, running multiple programs simultaneously, synchronization, protection, file system, how to create/load new programs, etc."
- “How do I set up the trap handler and stack?”
- “Why is ‘a’ continuously printing in the output?”
- “Why does my OS freeze immediately after QEMU starts?”
- "Which QEMU package do I need and how would I download it?”
- “Provide the commands needed to test my OS”
- “How do I add a syscall that prints a full string?”
- “Why is UART not printing anything?”
- "This is an operating system that can run on a RISC-V computer  can you explain each file in detail so I'll have a better understanding of what each file does and its purpose. "
