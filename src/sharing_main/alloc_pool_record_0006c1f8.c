/* HSTMATCH module=hstp_trans_main.prx start=0x0006c1f8 end=0x0006c25c symbol=FUN_0006c1f8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: the in-use flags are unsigned char (lbu) and the result is initialised to 0 and assigned before a break out of the search loop; exact match verified; names and types await human review. */
typedef unsigned char uchar;
typedef unsigned int uint;
typedef struct Rec { char data[0x1b0]; } Rec;
typedef struct Pool {
    uint count;
    Rec *recs;
    uchar *used;
} Pool;

Rec *FUN_0006c1f8(Pool *pool)
{
    Rec *r = 0;
    uint i;
    for (i = 0; i < pool->count; i++) {
        if (pool->used[i] == 0) {
            r = pool->recs + i;
            pool->used[i] = 1;
            break;
        }
    }
    return r;
}
