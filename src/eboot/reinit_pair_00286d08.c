/* HSTMATCH module=EBOOT.BIN start=0x00286d08 end=0x00286db0 symbol=FUN_00286d08 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: typed struct, merged alloc/ctor pattern, deletion order; exact match verified; names and types await human review. */

extern void *FUN_00000bcc(unsigned int size);
extern void *FUN_0014c794(void *p, int a, int b, int c);
extern void FUN_0014c820(void *p, int flag);

struct Obj_00286d08 {
    int pad0;
    int pad4;
    void *f8;
    void *fC;
};

void FUN_00286d08(struct Obj_00286d08 *self)
{
    void *p;

    if (self->fC != 0) {
        FUN_0014c820(self->fC, 1);
        self->fC = 0;
    }
    if (self->f8 != 0) {
        FUN_0014c820(self->f8, 1);
        self->f8 = 0;
    }

    p = FUN_00000bcc(36);
    if (p != 0) {
        p = FUN_0014c794(p, 0, 0, 0);
    }
    self->f8 = p;

    p = FUN_00000bcc(36);
    if (p != 0) {
        p = FUN_0014c794(p, 0, 0, 0);
    }
    self->fC = p;
}
