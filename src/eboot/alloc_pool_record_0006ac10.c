/* HSTMATCH module=EBOOT.BIN start=0x0006ac10 end=0x0006ac74 symbol=FUN_0006ac10 lang=c99 */
/* Clone of src/sharing_main/alloc_pool_record_0006c1f8.c (hstclone.py tag s10170158a1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: the in-use flags are unsigned char (lbu) and the result is initialised to 0 and assigned before a break out of the search loop; exact match verified; names and types await human review. */
typedef unsigned char uchar;
typedef unsigned int uint;
typedef struct Rec { char data[0x1b0]; } Rec;
typedef struct Pool {
    uint count;
    Rec *recs;
    uchar *used;
} Pool;

Rec *FUN_0006ac10(Pool *pool)
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
