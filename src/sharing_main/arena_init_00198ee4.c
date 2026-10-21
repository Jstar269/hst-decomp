/* HSTMATCH module=hstp_trans_main.prx start=0x00198ee4 end=0x00198fe8 symbol=FUN_00198ee4 lang=c99 */
/* Clone of src/eboot/arena_init_0018c704.c (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_002bd3c0(char *self);
extern void FUN_001cc1a4(char *p);
extern void *FUN_000114c0(void *dst, int value, unsigned n);
extern void FUN_0023cd64(char *p);
extern void FUN_0025e1cc(char *p);
char *FUN_00198ee4(char *self)
{
    FUN_002bd3c0(self);
    FUN_001cc1a4(self + 0x80);
    FUN_000114c0(self + 0xea60, 0, 0x7803c);
    FUN_0023cd64(self + 0x86a9c);
    FUN_0025e1cc(self + 0x86c10);
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
