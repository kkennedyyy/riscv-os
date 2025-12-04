CROSS = riscv64-unknown-elf-
CC = $(CROSS)gcc
LD = $(CROSS)ld
OBJCOPY = $(CROSS)objcopy

ARCH = -march=rv64im -mabi=lp64 -mcmodel=medany -ffreestanding -nostdlib -O2

KERNEL_OBJS = kernel/entry.o kernel/kernel.o kernel/uart.o \
              kernel/trap.o kernel/kernel_trap.o
USER_OBJS = user/user.o

all: kernel.elf

%.o: %.S
	$(CC) $(ARCH) -c -o $@ $<

%.o: %.c
	$(CC) $(ARCH) -Wall -c -o $@ $<

kernel.elf: $(KERNEL_OBJS) $(USER_OBJS) linker.ld
	$(LD) -T linker.ld -o kernel.elf $(KERNEL_OBJS) $(USER_OBJS)
	$(OBJCOPY) -O binary kernel.elf kernel.bin

clean:
	rm -f kernel/*.o user/*.o kernel.elf kernel.bin
