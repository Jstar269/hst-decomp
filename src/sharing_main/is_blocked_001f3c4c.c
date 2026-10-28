/* HSTMATCH module=hstp_trans_main.prx start=0x001f3c4c end=0x001f3c9c symbol=FUN_001f3c4c lang=c99 */
/* Clone of src/eboot/is_blocked_001e5a34.c (hstclone.py tag s10200333g2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
typedef struct { unsigned char pad[0x78]; float limit; } Sub;
typedef struct { unsigned char pad0[0x60]; int state; unsigned char pad1[4]; Sub *sub; } Inner;
typedef struct { unsigned char pad[0x1954]; Inner *obj; } Self;
int FUN_001f3c4c(Self *s)
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
