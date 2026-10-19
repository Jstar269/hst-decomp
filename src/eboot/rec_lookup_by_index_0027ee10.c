/* HSTMATCH module=EBOOT.BIN start=0x0027ee10 end=0x0027ee6c symbol=FUN_0027ee10 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { int pad; short flag; unsigned char rest[0x22]; } Rec;
typedef struct {
    int pad0;
    Rec *base;          /* 0x4 */
    unsigned char pad1[8];
    int *idx;           /* 0x10 */
    unsigned int count; /* 0x14 */
} Self;

int FUN_0027ee10(Self *s, unsigned int i)
{
    Rec *r;
    if ((int)i >= 0 && i < s->count) {
        r = &s->base[s->idx[i]];
        if (r->flag < 0) goto zero;
        return (int)r;
    }
zero:
    return 0;
}
