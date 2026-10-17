/* HSTMATCH module=EBOOT.BIN start=0x00093024 end=0x0009306c symbol=FUN_00093024 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: un-merged next statements into two sequential null-checked calls; exact match verified; names and types await human review. */

extern void FUN_00057730(void *);

struct S {
    char pad0[0x58];
    void *m1;
    char pad1[0x64 - 0x5c];
    void *m2;
};

void FUN_00093024(struct S *self)
{
    if (self->m1 != 0) {
        FUN_00057730(self->m1);
    }
    if (self->m2 != 0) {
        FUN_00057730(self->m2);
    }
}
