/* HSTMATCH module=EBOOT.BIN start=0x00222b48 end=0x00222bb8 symbol=FUN_00222b48 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: typed DAT_002eff90 as int and DAT_002f0f48 as float, placed (float)self->timer on the left of >=, and typed the flag as unsigned char; exact match verified; names and types await human review. */
typedef struct Obj_00222b48 {
    char pad60[0x60];
    int timer;
    char pad64[0xb0 - 0x64];
    unsigned char flag;
} Obj_00222b48;

extern int DAT_002eff90;
extern float DAT_002f0f48;

int FUN_00222b48(Obj_00222b48 *self)
{
    int res = 0;
    int ok = 0;
    if (self->timer >= 0 && (float)self->timer >= (float)DAT_002eff90 + DAT_002f0f48 + 20.0f) {
        ok = 1;
    }
    if (ok != 0 && self->flag != 0) {
        res = 1;
    }
    return res;
}
