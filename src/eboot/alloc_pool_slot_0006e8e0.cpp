/* HSTMATCH module=EBOOT.BIN start=0x0006e8e0 end=0x0006e93c symbol=FUN_0006e8e0 lang=c++ */
/* Clone of src/sharing_main/alloc_pool_slot_000700a0.cpp (hstclone.py tag c025720): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Rec { char b[0x70]; };
struct Pool {
    unsigned count;
    Rec *recs;
    unsigned char *used;
};

extern "C" Rec *FUN_0006e8e0(Pool *p)
{
    Rec *r = 0;
    unsigned i = 0;
    if (p->count != 0) {
        unsigned char *q = p->used;
        do {
            if (*q == 0) {
                r = p->recs + i;
                p->used[i] = 1;
                break;
            }
            i++;
            q++;
        } while (i < p->count);
    }
    return r;
}
