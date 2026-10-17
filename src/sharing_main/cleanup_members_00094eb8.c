/* HSTMATCH module=hstp_trans_main.prx start=0x00094eb8 end=0x00094f00 symbol=FUN_00094eb8 lang=c99 */
/* Clone of src/eboot/cleanup_members_00093024.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: un-merged next statements into two sequential null-checked calls; exact match verified; names and types await human review. */

extern void FUN_00058384(void *);

struct S {
    char pad0[0x58];
    void *m1;
    char pad1[0x64 - 0x5c];
    void *m2;
};

void FUN_00094eb8(struct S *self)
{
    if (self->m1 != 0) {
        FUN_00058384(self->m1);
    }
    if (self->m2 != 0) {
        FUN_00058384(self->m2);
    }
}
