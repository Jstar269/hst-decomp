/* HSTMATCH module=hstp_trans_main.prx start=0x00069080 end=0x00069104 symbol=FUN_00069080 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: proper EABI parameter typing, float function pointer prototype; exact match verified; names and types await human review. */

struct Obj {
    char pad[12];
    float val;
};

void FUN_00069080(struct Obj *self, float (*func)(float, float, float), float t)
{
    if (t < 0.5f) {
        self->val = func(0.0f, 128.0f, 2.0f * t);
    } else {
        self->val = func(0.0f, 128.0f, 2.0f - 2.0f * t);
    }
}
