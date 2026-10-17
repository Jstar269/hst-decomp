/* HSTMATCH module=hstp_trans_main.prx start=0x00298404 end=0x002984ac symbol=FUN_00298404 lang=c99 */
/* Clone of src/eboot/reinit_pair_00286d08.c (hstclone.py tag u5fr4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: typed struct, merged alloc/ctor pattern, deletion order; exact match verified; names and types await human review. */

extern void *FUN_00000bcc(unsigned int size);
extern void *FUN_0015827c(void *p, int a, int b, int c);
extern void FUN_00158308(void *p, int flag);

struct Obj_00298404 {
    int pad0;
    int pad4;
    void *f8;
    void *fC;
};

void FUN_00298404(struct Obj_00298404 *self)
{
    void *p;

    if (self->fC != 0) {
        FUN_00158308(self->fC, 1);
        self->fC = 0;
    }
    if (self->f8 != 0) {
        FUN_00158308(self->f8, 1);
        self->f8 = 0;
    }

    p = FUN_00000bcc(36);
    if (p != 0) {
        p = FUN_0015827c(p, 0, 0, 0);
    }
    self->f8 = p;

    p = FUN_00000bcc(36);
    if (p != 0) {
        p = FUN_0015827c(p, 0, 0, 0);
    }
    self->fC = p;
}
