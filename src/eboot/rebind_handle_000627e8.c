/* HSTMATCH module=EBOOT.BIN start=0x000627e8 end=0x000628b4 symbol=FUN_000627e8 lang=c99 */
/* Clone of src/sharing_main/rebind_handle_000636ac.c (hstclone.py tag s10170158a1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v0) corrected by hand: struct layout with unsigned char flag at +8, early return -1 on negative handle, and non-zero/zero callback branch order; exact match verified; names and types await human review. */
typedef struct {
    int pad0;
    int f4;
    unsigned char f8;
    int f0c;
    int f10;
} Obj_000627e8;

extern int DAT_00331b80;
extern void FUN_00062904(Obj_000627e8 *, int);
extern int FUN_00075eb4(int, int, int);
extern void FUN_00077470(int, int, int);
extern void FUN_0007748c(int, int, int, void (*)(void));
extern void FUN_000627bc(void);

int FUN_000627e8(Obj_000627e8 *self, int param_2)
{
    if (self->f4 < 0) {
        return -1;
    }
    if (self->f8 != 0) {
        FUN_00062904(self, self->f0c);
    }
    int r = FUN_00075eb4(self->f4, param_2, 0);
    if (self->f8 != 0 && r >= 0) {
        if (self->f10 == 0) {
            DAT_00331b80++;
            FUN_0007748c(r, 0, 0x10000, FUN_000627bc);
        } else {
            FUN_00077470(r, 0, 0x10000);
        }
        self->f0c = r;
    }
    return r;
}
