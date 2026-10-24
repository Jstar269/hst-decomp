/* HSTMATCH module=EBOOT.BIN start=0x001bb6e0 end=0x001bb8b8 symbol=FUN_001bb6e0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00011090(void *, const void *, int);
extern void FUN_000149a8(void *, const void *);
extern int FUN_00193474(int);

void FUN_001bb6e0(short *param_1, int param_2, int param_3, int param_4, int param_5,
                  int param_6, int param_7, int param_8,
                  unsigned char s0, unsigned char s4, unsigned char s8, int sC,
                  int s10, int s14, int s18, int s1C, int s20, int s24,
                  unsigned char s28, int s2C, unsigned char s30, int s34, int s38,
                  unsigned char s3C, int s40)
{
    int iVar1;
    unsigned char *b;
    int i;
    unsigned char *p;

    FUN_00011090(param_1, (const void *)s40, 0x9c);
    iVar1 = FUN_00193474(param_3);
    if (iVar1 != 0) {
        param_1[0x45] = *(short *)(iVar1 + 0x8a);
        param_1[0x46] = *(short *)(iVar1 + 0x8c);
        param_1[0x47] = *(short *)(iVar1 + 0x8e);
        param_1[0x48] = *(short *)(iVar1 + 0x90);
        param_1[0x49] = *(short *)(iVar1 + 0x92);
        param_1[0x4a] = *(short *)(iVar1 + 0x94);
        param_1[0x4b] = *(short *)(iVar1 + 0x96);
        param_1[0x4c] = *(short *)(iVar1 + 0x98);
    }
    *param_1 = (short)param_3;
    param_1[1] = (short)param_4;
    param_1[2] = (short)param_5;
    param_1[3] = (short)param_6;
    param_1[4] = (short)param_7;
    param_1[5] = (short)param_8;
    FUN_000149a8(param_1 + 0x66, (const void *)param_2);
    *(unsigned char *)(param_1 + 0x4e) = s0;
    *(unsigned char *)((int)param_1 + 0x9d) = s4;
    *(unsigned char *)(param_1 + 0x4f) = s8;
    *(unsigned char *)((int)param_1 + 0x9f) = s28;
    *(unsigned char *)(param_1 + 0x50) = sC;
    b = (unsigned char *)param_1;
    b[0x64] = s10;
    if (b[0x64] < 0 || b[0x64] >= 0x16)
        b[0x64] = 0;
    *(unsigned char *)((int)param_1 + 0x65) = s14;
    param_1[0x29] = (short)s18;
    FUN_000149a8(param_1 + 0x2a, (const void *)s1C);
    b = (unsigned char *)param_1;
    b[0x66] = s20;
    b[0x67] = s2C;
    i = 0;
    p = b;
    do {
        p[0x7d] = b[0x64];
        param_1[0x3c] = param_1[0x29];
        FUN_000149a8(param_1 + 0x34, param_1 + 0x2a);
        i = i + 1;
        b[0x7c] = b[0x66];
        p[0x7e] = b[0x67];
        p = p + 3;
    } while (i < 4);
    *(unsigned char *)((int)param_1 + 0xc9) = s24;
    *(unsigned char *)((int)param_1 + 0xcb) = s34;
    *(unsigned char *)(param_1 + 0x76) = s38;
    *(unsigned char *)((int)param_1 + 0x101) = s3C;
    *(unsigned char *)(param_1 + 100) = s30;
}
