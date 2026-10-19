/* HSTMATCH module=EBOOT.BIN start=0x00067c2c end=0x00067cb0 symbol=FUN_00067c2c lang=c99 */
/* Clone of src/sharing_main/fade_eval_00069080.c (hstclone.py tag s10172123g5r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: proper EABI parameter typing, float function pointer prototype; exact match verified; names and types await human review. */

struct Obj {
    char pad[12];
    float val;
};

void FUN_00067c2c(struct Obj *self, float (*func)(float, float, float), float t)
{
    if (t < 0.5f) {
        self->val = func(0.0f, 128.0f, 2.0f * t);
    } else {
        self->val = func(0.0f, 128.0f, 2.0f - 2.0f * t);
    }
}
