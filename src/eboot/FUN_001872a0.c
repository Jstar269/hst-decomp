/* HSTMATCH module=EBOOT.BIN start=0x001872a0 end=0x00187308 symbol=FUN_001872a0 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { unsigned int value; unsigned int pad[4]; } Rec;
typedef struct { char pad0[0x2884]; Rec *recs; char pad1[0x2a24 - 0x2888]; int count; } RecOwner;
extern void FUN_000ffb3c(unsigned int value, int mode);

void FUN_001872a0(RecOwner *c)
{
    Rec *r;
    int i;
    r = c->recs;
    for (i = 0; i < c->count; i++) {
        if (r->value != 0) FUN_000ffb3c(r->value, 1);
        r++;
    }
}
