/* HSTMATCH module=hstp_trans_main.prx start=0x000eeaf0 end=0x000eebe4 symbol=FUN_000eeaf0 lang=c++ */
/* Clone of src/eboot/matrix_history_push_000e9a1c.cpp (hstclone.py tag c055807): addresses substituted; exact match verified; names and types await human review. */
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

int FUN_000eeaf0(Self *self)
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
