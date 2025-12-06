# user.S file
# Running in user mode, this code makes syscalls to the kernel to print 'A' repeatedly.
    .section .text
    .global user_start

user_start:
    li a7, 1  
    la a0, msg
    ecall

    li a7, 2
    ecall
1: j 1b

.section .rodata
msg:
    .asciz "Hello from user mode!\n"
# What does this show?
# This shows that the user mode, syscalls, trap handling, and register saving/restoring works and sret returns back correctly

