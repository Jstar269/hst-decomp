/* HSTMATCH module=EBOOT.BIN start=0x0008cea4 end=0x0008d07c symbol=FUN_0008cea4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef unsigned char uchar;

extern "C" {
extern int *DAT_003415a8;
extern char s_tADH_SeqInfo__Init___002beaa8[];
extern void FUN_0008d388(int *p, int a, int b, int c, int d, int e, int f);
extern void FUN_0008d2ec(int *p);
extern void FUN_0008d298(void *p);
extern void FUN_0008d264(void *p);
extern void FUN_0008d22c(void *p);
extern void FUN_0008d1ec(void *p);
extern void FUN_0008d148(void *p);
extern void FUN_0008d114(void *p);
extern void FUN_0008d0e4(void *p, void *src);
extern void FUN_0008d0cc(void *p, void *src);
extern void FUN_000114c0(void *p, int a, int b);
extern void FUN_0008cae8(char *msg);
}

extern "C" void *FUN_0008cea4(char *p)
{
    unsigned int i;
    int *q;
    int *b;

    b = (int *)(p + 0x40);
    FUN_0008d388(b, 0, 0, 0, 0, 0, 0);
    FUN_0008d2ec(b);
    b = (int *)(p + 0x160);
    FUN_0008d388(b, 0, 0, 0, 0, 0, 0);
    FUN_0008d2ec(b);
    b = (int *)(p + 0x280);
    FUN_0008d388(b, 0, 0, 0, 0, 0, 0);
    FUN_0008d2ec(b);
    FUN_0008d298(p + 0x3c8);
    FUN_0008d264(p + 0x3dc);
    FUN_0008d22c(p + 0x3dd);
    FUN_0008d1ec(p + 0x3e0);
    FUN_0008d148(p + 0x3a8);
    i = 0;
    q = (int *)p;
    do {
        i++;
        *q++ = -1;
    } while (i < 4);
    ((int *)p)[4] = -1;
    p[0x14] = 0;
    FUN_0008d114(p + 0x18);
    FUN_0008d2ec((int *)(p + 0x40));
    p[0x10c] = 0;
    FUN_0008d2ec((int *)(p + 0x160));
    FUN_0008d2ec((int *)(p + 0x280));
    p[0x22c] = 0;
    p[0x34c] = 0;
    FUN_0008d0e4(p + 0x148, (char *)DAT_003415a8 + 4);
    FUN_0008d0cc(p + 0x158, (char *)DAT_003415a8 + 0x18);
    p[0x3a8] = 0;
    ((int *)p)[0xeb] = 0;
    ((int *)p)[0xec] = 0;
    ((int *)p)[0xed] = 0;
    ((int *)p)[0xf0] = 0;
    ((int *)p)[0xf1] = 0;
    ((int *)p)[0xee] = 0;
    ((int *)p)[0xef] = 0;
    p[0x3c8] = 0;
    p[0x3c9] = 1;
    p[0x3ca] = 2;
    p[0x3cb] = 0;
    p[0x3d1] = 0;
    p[0x3d2] = 0;
    p[0x3d8] = 0;
    p[0x3dc] = 0;
    p[0x3dd] = 0;
    p[0x3de] = 0;
    FUN_000114c0(p + 0x3e0, 0, 0x6c);
    *(short *)(p + 0x448) = -1;
    *(short *)(p + 0x44a) = -1;
    *(short *)(p + 0x404) = -1;
    ((int *)p)[0x113] = 0;
    ((int *)p)[0x114] = 0;
    FUN_0008cae8(s_tADH_SeqInfo__Init___002beaa8);
    return p;
}
