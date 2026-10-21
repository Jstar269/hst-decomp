/* HSTMATCH module=EBOOT.BIN start=0x0018c704 end=0x0018c808 symbol=FUN_0018c704 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_002adb98(char *self);
extern void FUN_001be450(char *p);
extern void *FUN_000114c0(void *dst, int value, unsigned n);
extern void FUN_0022cc64(char *p);
extern void FUN_0024df94(char *p);
char *FUN_0018c704(char *self)
{
    FUN_002adb98(self);
    FUN_001be450(self + 0x80);
    FUN_000114c0(self + 0xea60, 0, 0x7803c);
    FUN_0022cc64(self + 0x86a9c);
    FUN_0024df94(self + 0x86c10);
    FUN_000114c0(self + 0x86d10, 0, 0x414);
    FUN_000114c0(self + 0x87128, 0, 0x10890);
    *(int *)(self + 0x4c) = (int)(self + 0x80) - (int)self;
    *(int *)(self + 0x50) = (int)(self + 0x84) - (int)self;
    *(int *)(self + 0x68) = 15;
    *(int *)(self + 0x54) = (int)(self + 0x3cc) - (int)self;
    *(int *)(self + 0x6c) = 640;
    *(int *)(self + 0x58) = (int)(self + 0x8cc) - (int)self;
    *(int *)(self + 0x70) = 640;
    *(int *)(self + 0x5c) = (int)(self + 0xb4c) - (int)self;
    *(int *)(self + 0x74) = 640;
    *(int *)(self + 0x60) = (int)(self + 0xdcc) - (int)self;
    *(int *)(self + 0x78) = 640;
    *(int *)(self + 0x64) = (int)(self + 0x80) - (int)self;
    return self;
}
