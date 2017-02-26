AS      := nasm
ASFLAGS := -f elf64
MEMM_LDFLAGS := -m elf_x86_64_fbsd -T memm.ld -z max-page-size=0x1000
STUB_LDFLAGS := -m elf_x86_64_fbsd -T boot.ld -z max-page-size=0x1000

CFLAGS  := --std=c11 -g $(TOASM)  -Wall -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations -Wredundant-decls -Wnested-externs -Winline -Wno-long-long -Wuninitialized -Wconversion -Wstrict-prototypes -Wno-empty-body -Wextra -pedantic -ffreestanding -I ../../include

STUB_OBJS = start.o main.o serial.o
MEMM_OBJS = mem_detect.o mem_init.o

all: xlii_memmgr.elf bootrd boot_stub

bootrd:
	ls mem_*.o | cpio -o > bootrd.img
	ld -r -b binary -o bootrd.o bootrd.img

xlii_memmgr.elf: $(MEMM_OBJS)
	$(LD) $(MEMM_LDFLAGS) -o xlii_memmgr.elf $(MEMM_OBJS)

boot_stub: $(STUB_OBJS)
	$(LD) $(STUB_LDFLAGS) -o xlii_boot.elf $(STUB_OBJS) bootrd.o

clean:
	@-$(RM) -v $(shell find . -type f -name "*.o") *.elf
