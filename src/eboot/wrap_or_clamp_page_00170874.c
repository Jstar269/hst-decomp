/* HSTMATCH module=EBOOT.BIN start=0x00170874 end=0x00170930 symbol=FUN_00170874 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a2/v0) corrected by hand: chained condition for upper bound, f4 declared before count for a3/a2 registers; exact match verified; names and types await human review. */

typedef struct Ent {
    int f0;
    unsigned int count;
    int f8;
} Ent;

typedef struct Tbl {
    int f0;
    unsigned int f4;
    char pad08[16];
    Ent *ents;
    int count;
} Tbl;

int FUN_00170874(int param_1, Tbl *t, int cur, int delta, int wrap)
{
    int x = cur + delta;
    unsigned int f4 = t->f4;
    int count = t->count;
    unsigned int u;

    if (x == count - 1 &&
        (u = *(unsigned int *)((char *)t->ents + x * 12 + 4)) < 4 &&
        (u = u - 1) < f4) {
        t->f4 = u;
    } else if (x < 0) {
        if (wrap != 0) {
            x = count - 1;
            if ((u = *(unsigned int *)((char *)t->ents + x * 12 + 4)) < 4 &&
                (u = u - 1) < f4) {
                t->f4 = u;
            }
        } else {
            x = 0;
        }
    } else if (x >= count) {
        if (wrap != 0) {
            x = 0;
        } else {
            x = count - 1;
        }
    }
    return x;
}
