/* HSTMATCH module=EBOOT.BIN start=0x0015de34 end=0x0015dec0 symbol=FUN_0015de34 lang=c99 */
/* Clone of src/sharing_main/voice_update_0016a3c0.c (hstclone.py tag s10172123g5r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: outer OR-condition restructuring; exact match verified; names and types await human review. */

struct Obj {
    int m0;
    unsigned char m4;
};

extern void *DAT_003403f8;
extern int DAT_0034040c[];
extern int FUN_0015a728(void *, int, int);
extern void FUN_0015b6a4(void *, int, int, int);

int FUN_0015de34(struct Obj *self, int param_2, int param_3)
{
    if (self->m0 != param_2 || param_3 != 0) {
        if (self->m0 != param_2) {
            self->m0 = FUN_0015a728(DAT_003403f8, param_2 - self->m0, 0);
        }
        if (self->m4 != 0) {
            FUN_0015b6a4(DAT_003403f8, DAT_0034040c[self->m0], 0, 0);
        }
    }
    return self->m0;
}
