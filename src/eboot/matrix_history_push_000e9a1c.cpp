/* HSTMATCH module=EBOOT.BIN start=0x000e9a1c end=0x000e9b10 symbol=FUN_000e9a1c lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
extern "C" {
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) Vec4;
struct Matrix {
    Vec4 lo, hi;
    Matrix(Vec4 a, Vec4 b) : lo(a), hi(b) {}
};
typedef struct {
    unsigned char pad0[0x40];
    Matrix frames[40];
    unsigned char pad1[0xb8];
    int count;
    unsigned char pad2[0x14];
    Matrix pending;
} Self;

int FUN_000e9a1c(Self *self)
{
    int i = self->count;

    if (i >= 40)
        return 1;
    Matrix m(self->pending.lo, self->pending.hi);
    self->count = i + 1;
    Matrix *dst = &self->frames[i];
    *dst = m;
    return 0;
}
}
