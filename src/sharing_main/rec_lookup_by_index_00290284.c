/* HSTMATCH module=hstp_trans_main.prx start=0x00290284 end=0x002902e0 symbol=FUN_00290284 lang=c99 */
/* Clone of src/eboot/rec_lookup_by_index_0027ee10.c (hstclone.py tag s10181937g11r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { int pad; short flag; unsigned char rest[0x22]; } Rec;
typedef struct {
    int pad0;
    Rec *base;          /* 0x4 */
    unsigned char pad1[8];
    int *idx;           /* 0x10 */
    unsigned int count; /* 0x14 */
} Self;

int FUN_00290284(Self *s, unsigned int i)
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
