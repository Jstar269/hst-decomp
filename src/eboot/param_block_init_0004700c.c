/* HSTMATCH module=EBOOT.BIN start=0x0004700c end=0x00047054 symbol=FUN_0004700c lang=c99 */
/* Hand-written reconstruction from the disassembly (EBOOT twin of src/sharing_main/param_block_init_00047364.c); exact match verified; names and types await human review. */
typedef struct Rec {
    float f0;
    float f4;
    short s8;
    float fc;
    float f10;
    float f14;
    float f18;
    unsigned char b1c;
    short s1e;
    short s20;
    short s22;
    short s24;
} Rec;

Rec *FUN_0004700c(Rec *r, float a, float b, short c, float d, float e, float f, float g,
                  unsigned char h, signed char i, signed char j, signed char k, signed char l)
{
    r->f0 = a;
    r->f4 = b;
    r->s8 = c;
    r->fc = d;
    r->f10 = e;
    r->f14 = f;
    r->f18 = g;
    r->b1c = h;
    r->s1e = i;
    r->s20 = j;
    r->s22 = k;
    r->s24 = l;
    return r;
}
