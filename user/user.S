# user.S file
# Running in user mode, this code makes syscalls to the kernel to print 'A' repeatedly.
    .section .text
    .global user_start

user_start:
    li a7, 1   # syscall write char
    li a0, 'A'
    ecall
    j user_start

# What does this show?
# This shows that the user mode, syscalls, trap handling, and register saving/restoring works and sret returns back correctly

