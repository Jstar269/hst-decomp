/* HSTMATCH module=EBOOT.BIN start=0x0019953c end=0x00199754 symbol=FUN_0019953c lang=c++ */
struct Col {
    unsigned char r, g, b, a;
};

extern "C" void FUN_001997dc(void *self, int img, Col col, float a);
extern "C" void FUN_00051490(int img, int a, int b, int w, int h, int c, int d);
extern "C" void FUN_00051894(float, float, float, float, float, float, float, float, int, Col, float);
extern "C" void FUN_0005185c(int img);

struct Obj {
    int imgs[6];
    int mode;      /* 0x18 */
    int kind;      /* 0x1c */
    int count;     /* 0x20 */
};

extern "C" void FUN_0019953c(Obj *self)
{
    Col col;
    int mode;
    int w, h, x, y;

    mode = self->mode;
    col.r = 0x80;
    col.g = 0x80;
    col.b = 0x80;
    col.a = 0x80;
    if (mode != 3 && self->kind != 6 && mode >= 0) {
        if (self->kind == 5) {
            w = 256;
            h = 256;
        } else if (self->kind == 4) {
            w = 256;
            h = 64;
        } else {
            w = 512;
            h = 64;
        }
        x = (480 - w) >> 1;
        y = (272 - h) >> 1;
        if (mode == 0) {
            col.a = (signed char)(128 - (self->count * 128) / 15);
        } else if (mode == 2) {
            col.a = (signed char)(((self->count - 1) * 128) / 15);
        }
        if (self->kind < 3) {
            FUN_001997dc(self, self->imgs[self->kind], col, 255.0f);
        } else {
            FUN_00051490(self->imgs[self->kind], 0, 0, 480, 272, 0, 0);
            FUN_00051894(0.0f, 0.0f, (float)x, (float)y, (float)w, (float)h,
                         (float)(x + w), (float)(y + h), self->imgs[self->kind], col, 255.0f);
            FUN_0005185c(self->imgs[self->kind]);
        }
    }
}
// NEAR (sy2): 129/134 words, 123 differ (mostly a shift). New this pass: the object IS the image table - `lw a1,0(self+kind*4)` has no
// offset, so the layout is { int imgs[6]; int mode (0x18); int kind (0x1c); int count (0x20); } (imgs[0..5] cover kinds 0..5), not a pad
// at the front. Tried: nested ifs, `&&` chain (mode != 3 && kind != 6 && mode >= 0), local `kind` loaded inside the nest (122 words),
// mode loaded before the colour stores (retail loads mode into a2 first, then `li v1,128; li a1,3; move s4,a0`). Still open: retail's
// third guard is `bgezl a2,CONT; li v0,5 (copied) ; b EPI; nop` (likely form into the body, explicit `b EPI` on the fall-through)
// and mode lives in a2 / constant 3 in a1, ours bltz+nop with mode in a1.
// improved by lane sy2 (unreviewed): 126 -> 123 differing words
