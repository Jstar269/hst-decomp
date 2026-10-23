/* HSTMATCH module=EBOOT.BIN start=0x000e3a74 end=0x000e3b24 symbol=FUN_000e3a74 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void *FUN_00000a90(int);
extern void *FUN_000008d8(void *, void *, int, int, int);
extern void *FUN_00000bcc(int);
extern void *FUN_0005abf4(void *, int, int, int, int, int);
extern void FUN_000e3b24();

void FUN_000e3a74(char *self)
{
    int n;
    void *buf;
    void *p;

    *(int *)(self + 0x44) = 6;
    n = *(short *)(*(int *)(self + 0x3c) + 2);
    buf = FUN_00000a90(n * 0x70 + 0x10);
    *(void **)(self + 0x50) = FUN_000008d8(buf, (void *)&FUN_000e3b24, 0, 0x70, n);
    p = FUN_00000bcc(0x70);
    if (p != 0)
        p = FUN_0005abf4(p, 1, *(short *)(*(int *)(self + 0x3c) + 2) * *(int *)(self + 0x44), 1, 1, 0);
    *(void **)(self + 0x40) = p;
}
