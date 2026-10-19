/* HSTMATCH module=hstp_trans_main.prx start=0x0016a3c0 end=0x0016a44c symbol=FUN_0016a3c0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: outer OR-condition restructuring; exact match verified; names and types await human review. */

struct Obj {
    int m0;
    unsigned char m4;
};

extern void *DAT_003e9738;
extern int DAT_003e974c[];
extern int FUN_00166d00(void *, int, int);
extern void FUN_00167c4c(void *, int, int, int);

int FUN_0016a3c0(struct Obj *self, int param_2, int param_3)
{
    if (self->m0 != param_2 || param_3 != 0) {
        if (self->m0 != param_2) {
            self->m0 = FUN_00166d00(DAT_003e9738, param_2 - self->m0, 0);
        }
        if (self->m4 != 0) {
            FUN_00167c4c(DAT_003e9738, DAT_003e974c[self->m0], 0, 0);
        }
    }
    return self->m0;
}
