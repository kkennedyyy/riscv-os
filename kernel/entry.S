# entry.S - The first code that runs after the bootloader jumps into the kernel.
# It sets up the stack pointer, installs the trap handler address into stvecc
# Jumps into C code (kernel_main())
.section .text
.global _start

_start:
    # Set up the stack pointer
    la sp, stack_top

    # Jumps to trap handler if an exception occurs
    la t0, trap_handler
    csrw stvec, t0

    # Jump into main kernel function to kernel_main()
    call kernel_main

# Infinite loop to prevent falling off
1:  j 1b

.section .bss
.align 4
.space 4096
stack_top:
