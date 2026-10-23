/* HSTMATCH module=EBOOT.BIN start=0x0019953c end=0x00199754 symbol=FUN_0019953c lang=c++ */
struct Col {
    unsigned char r, g, b, a;
};

extern "C" void FUN_001997dc(int self, int img, Col col, float a);
extern "C" void FUN_00051490(int img, int a, int b, int w, int h, int c, int d);
extern "C" void FUN_00051894(float, float, float, float, float, float, float, float, int, Col, float);
extern "C" void FUN_0005185c(int img);

struct Obj {
    unsigned char pad0[0x18];
    int mode;
    int kind;
    int count;
    int imgs[1];
};

extern "C" void FUN_0019953c(Obj *self)
{
    Col col;
    col.r = 0x80;
    col.g = 0x80;
    col.b = 0x80;
    col.a = 0x80;
    int mode = self->mode;
    int kind;
    int w, h, x, y;

    if (mode == 3) {
        return;
    }
    kind = self->kind;
    if (kind == 6) {
        return;
    }
    if (mode < 0) {
        return;
    }
    if (kind == 5) {
        w = 256;
        h = 256;
    } else if (kind == 4) {
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
    if (kind < 3) {
        FUN_001997dc((int)self, self->imgs[kind], col, 255.0f);
    } else {
        FUN_00051490(self->imgs[kind], 0, 0, 480, 272, 0, 0);
        FUN_00051894(0.0f, 0.0f, (float)x, (float)y, (float)w, (float)h,
                     (float)(x + w), (float)(y + h), self->imgs[kind], col, 255.0f);
        FUN_0005185c(self->imgs[kind]);
    }
}
// NEAR 126/134 words, function #3 of batch fm4-00.
// Colours live in a 4-byte by-value struct (struct Col { unsigned char r,g,b,a; }) so the callee gets it
// in a2 with `lw`. A braced initializer `Col c = {0x80,0x80,0x80,0x80}` is NOT what retail does: MWCC
// emits a 4-byte .data template (UNPLACED_SECTION) and copies it; four separate member stores give
// retail's four `sb v1,60..63(sp)`.
// WHAT DIFFERS: return layout. Retail merges the three early returns through `beq a2,3,EPI` (plain),
// `beql v1,6,EPI+4` and `bgezl a2,CONTINUE` + `b EPI`, i.e. it uses the likely form for `mode >= 0`
// (source probably nests the body under `if (mode >= 0) { ... }` with one trailing return); ours emits
// plain `beql`/`bltz` and never homes self in a saved register (retail `move s4,a0` immediately), so all
// of self's offsets differ. Width/height selection matched as `if (kind == 5) {w=256;h=256;} else if
// (kind == 4) {w=256;h=64;} else {w=512;h=64;}` - retail's `move s2,s3` for the first arm confirms it.
// The two colour byte formulas compile to retail's 0x88888889 magic (signed /15) as written:
// (signed char)(128 - (count*128)/15) and (signed char)(((count-1)*128)/15).
// Ruled out (this round): braced initializer (wrong, see above). Not yet tried: nesting the body under
// `if (mode >= 0)`, passing Col through a pointer.
// near miss from lane fm4 (unreviewed)
