/* HSTMATCH module=hstp_trans_main.prx start=0x000636ac end=0x00063778 symbol=FUN_000636ac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v0) corrected by hand: struct layout with unsigned char flag at +8, early return -1 on negative handle, and non-zero/zero callback branch order; exact match verified; names and types await human review. */
typedef struct {
    int pad0;
    int f4;
    unsigned char f8;
    int f0c;
    int f10;
} Obj_000636ac;

extern int DAT_003daec0;
extern void FUN_000637c8(Obj_000636ac *, int);
extern int FUN_00077674(int, int, int);
extern void FUN_00078c30(int, int, int);
extern void FUN_00078c4c(int, int, int, void (*)(void));
extern void FUN_00063644(void);

int FUN_000636ac(Obj_000636ac *self, int param_2)
{
    if (self->f4 < 0) {
        return -1;
    }
    if (self->f8 != 0) {
        FUN_000637c8(self, self->f0c);
    }
    int r = FUN_00077674(self->f4, param_2, 0);
    if (self->f8 != 0 && r >= 0) {
        if (self->f10 == 0) {
            DAT_003daec0++;
            FUN_00078c4c(r, 0, 0x10000, FUN_00063644);
        } else {
            FUN_00078c30(r, 0, 0x10000);
        }
        self->f0c = r;
    }
    return r;
}
