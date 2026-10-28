/* HSTMATCH module=EBOOT.BIN start=0x001e5a34 end=0x001e5a84 symbol=FUN_001e5a34 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
typedef struct { unsigned char pad[0x78]; float limit; } Sub;
typedef struct { unsigned char pad0[0x60]; int state; unsigned char pad1[4]; Sub *sub; } Inner;
typedef struct { unsigned char pad[0x1954]; Inner *obj; } Self;
int FUN_001e5a34(Self *s)
{
    Inner *o = s->obj;
    int b;
    if (o != 0) {
        b = o->state < 0;
        if (!b) b = o->sub->limit <= 0.0f;
        return b;
    }
    return 1;

}
