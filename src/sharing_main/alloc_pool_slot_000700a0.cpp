/* HSTMATCH module=hstp_trans_main.prx start=0x000700a0 end=0x000700fc symbol=FUN_000700a0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Rec { char b[0x70]; };
struct Pool {
    unsigned count;
    Rec *recs;
    unsigned char *used;
};

extern "C" Rec *FUN_000700a0(Pool *p)
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
