/* HSTMATCH module=EBOOT.BIN start=0x000e1674 end=0x000e1724 symbol=FUN_000e1674 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void *FUN_00000a90(int);
extern void *FUN_000008d8(void *, void *, int, int, int);
extern void *FUN_00000bcc(int);
extern void *FUN_0005aa44(void *, int, int, int, int, int);
extern void FUN_000e1724();

void FUN_000e1674(char *self)
{
    int n;
    int m;
    int count;
    void *buf;
    void *p;

    *(int *)(self + 0x48) = 2;
    n = *(short *)(*(int *)(self + 0x3c) + 2);
    *(int *)(self + 0x4c) = n;
    m = n + 3;
    *(int *)(self + 0x50) = m;
    count = m + 3;
    buf = FUN_00000a90(count * 0x10 + 0x10);
    *(void **)(self + 0x54) = FUN_000008d8(buf, (void *)&FUN_000e1724, 0, 0x10, count);
    p = FUN_00000bcc(0x70);
    if (p != 0)
        p = FUN_0005aa44(p, 1, *(int *)(self + 0x48) * count, 1, 1, 0);
    *(void **)(self + 0x40) = p;
}
