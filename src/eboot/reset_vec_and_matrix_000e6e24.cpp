/* HSTMATCH module=EBOOT.BIN start=0x000e6e24 end=0x000e6fc4 symbol=FUN_000e6e24 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct V4 { float x, y, z, w; V4() {} } __attribute__((aligned(16)));
struct M4 { V4 r0, r1, r2, r3; };
struct EmptyTag {};
struct Pair { V4 a; V4 b; };
struct Vec { Pair *data; unsigned size; unsigned cap; };
struct Self {
    char pad0[0x3c];
    Vec vec;
    char pad48[0x58 - 0x48];
    float unk58;
    unsigned count;          /* 0x5c number of entries kept in vec */
    int unk60;
    int unk64;
    char pad68[0x70 - 0x68];
    M4 m;                    /* 0x70 */
    unsigned char unkb0;
    char padb1[0xc0 - 0xb1];
    float unkc0, unkc4, unkc8;
    int unkcc;
    char padd0[0xf0 - 0xd0];
    unsigned char unkf0;
};
extern "C" {
extern const M4 DAT_002bc410;
void FUN_000e8458(Vec *, unsigned, EmptyTag);
void FUN_000e8468(Vec *, unsigned, Pair *, EmptyTag);
}
#define DEFAULT_COUNT 30

/* Clears the vector, resets the fields and the matrix to defaults, then resizes the vector to count entries (new entries are identity-like pairs). */
extern "C" void FUN_000e6e24(Self *self)
{
    unsigned n = self->vec.size;
    FUN_000e8458(&self->vec, n, EmptyTag());
    self->unk58 = 1.0f;
    self->unk60 = 0;
    self->count = DEFAULT_COUNT;
    self->m = DAT_002bc410;
    self->unk64 = 0;
    self->unkb0 = 0;
    unsigned newn = self->count;
    unsigned oldn = self->vec.size;
    if (oldn < newn) {
        Pair tmp;
        tmp.a.w = 1.0f;
        tmp.a.x = 0.0f;
        tmp.a.y = 0.0f;
        tmp.a.z = 0.0f;
        tmp.b.x = 0.0f;
        tmp.b.y = 0.0f;
        tmp.b.z = 0.0f;
        tmp.b.w = 0.0f;
        FUN_000e8468(&self->vec, newn - oldn, &tmp, EmptyTag());
    } else if (newn < oldn) {
        FUN_000e8458(&self->vec, oldn - newn, EmptyTag());
    }
    self->unkc0 = 1.0f;
    self->unkc4 = 1.0f;
    self->unkc8 = 1.0f;
    self->unkcc = 0;
    self->unkf0 = 1;
}
