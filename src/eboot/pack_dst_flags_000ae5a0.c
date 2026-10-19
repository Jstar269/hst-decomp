/* HSTMATCH module=EBOOT.BIN start=0x000ae5a0 end=0x000ae68c symbol=FUN_000ae5a0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Src {
    char pad0[0x41c];
    int f41c;
    char pad1[0x43c - 0x420];
    float f43c;
    char pad2[0x4cf - 0x440];
    unsigned char c4cf;
    char pad3[0x4d8 - 0x4d0];
    unsigned char c4d8;
    unsigned char c4d9;
    unsigned char c4da;
    char pad4[0x4dc - 0x4db];
    signed char c4dc;
    char pad5[0x4e4 - 0x4dd];
    signed char c4e4;
    char pad6[0x4e8 - 0x4e5];
    signed char c4e8;
};

struct Dst {
    char pad0[0x20];
    short s20;
    signed char a : 3;
    signed char b : 5;
    signed char c : 2;
    signed char d : 1;
    signed char e : 1;
    signed char f : 1;
    signed char g : 3;
    float f24;
};

void FUN_000ae5a0(struct Src *src, struct Dst *dst)
{
    dst->s20 = (short)src->f41c;
    dst->a = src->c4e4;
    dst->b = src->c4e8;
    dst->c = src->c4cf;
    dst->d = src->c4d8;
    dst->e = src->c4d9;
    dst->f = src->c4da;
    dst->g = src->c4dc;
    dst->f24 = src->f43c;
}
