/* HSTMATCH module=EBOOT.BIN start=0x001d1fe0 end=0x001d2088 symbol=FUN_001d1fe0 lang=c++ */

struct Obj {
    char pad_00[0x60];
    int w96;
    char pad_64[0x270 - 0x64];
    float f624;
    float f628;
    char pad_278[0x510 - 0x278];
    float f1296;
};

extern "C" void FUN_001d1fe0(struct Obj *self)
{
    if (self->f628 < 0.0f) {
        self->f628 += 6.0f;
    }
    if (self->f628 > 6.0f) {
        self->f628 -= 6.0f;
    }

    float a = (float)(self->w96 + 1);
    const float &b = self->f1296;
    float f = a <= b ? a : b;
    float t = (float)(int)f / self->f1296;

    float f0 = self->f624;
    float f1 = self->f628;
    self->f624 = t * f1 + (1.0f - t) * f0;
}
// Near miss: 5/42 words differ at +0x50..+0x68.
// Retail schedules lwc1 $f1, 1296(a0) during the integer add latency and evaluates (float)(w96 + 1)
// into $f0, comparing c.ngt.s $f0, $f1 with bc1tl 0x1d2050 (delay slot mov.s $f1, $f0).
// Our candidate inverts $f0 and $f1 across the clamp (c.le.s $f1, $f0 with bc1fl).
// All lerp arithmetic and struct stores (+0x68..+0x84) match retail 100%.
// near miss from lane u5fr1-0 (unreviewed)
