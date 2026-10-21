/* HSTMATCH module=hstp_trans_main.prx start=0x001dfde4 end=0x001dfe8c symbol=FUN_001dfde4 lang=c++ */
/* Clone of src/eboot/lerp_val_001d1fe0.cpp (hstclone.py tag c21rt3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: typed the object layout, wrote the min as `(float)(w96+1) > b ? b : (float)(w96+1)` (the repeated expression is what puts the computed value in $f0 and the bound in $f1) and kept the trunc/div lerp; exact match verified; names and types await human review. */

struct Obj {
    char pad_00[0x60];
    int w96;
    char pad_64[0x270 - 0x64];
    float f624;
    float f628;
    char pad_278[0x510 - 0x278];
    float f1296;
};

extern "C" void FUN_001dfde4(struct Obj *self)
{
    if (self->f628 < 0.0f) {
        self->f628 += 6.0f;
    }
    if (self->f628 > 6.0f) {
        self->f628 -= 6.0f;
    }

    const float &b = self->f1296;
    float f = (float)(self->w96 + 1) > b ? b : (float)(self->w96 + 1);
    float t = (float)(int)f / self->f1296;

    float f0 = self->f624;
    float f1 = self->f628;
    self->f624 = t * f1 + (1.0f - t) * f0;
}
