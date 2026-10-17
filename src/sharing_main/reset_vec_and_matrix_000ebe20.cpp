/* HSTMATCH module=hstp_trans_main.prx start=0x000ebe20 end=0x000ebfc0 symbol=FUN_000ebe20 lang=c++ */
/* Clone of src/eboot/reset_vec_and_matrix_000e6e24.cpp (hstclone.py tag s10170158a2r1s): addresses substituted; exact match verified; names and types await human review. */
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
    float f58;
    unsigned f5c;
    int f60;
    int f64;
    char pad68[0x70 - 0x68];
    M4 m;
    unsigned char fb0;
    char padb1[0xc0 - 0xb1];
    float fc0, fc4, fc8;
    int fcc;
    char padd0[0xf0 - 0xd0];
    unsigned char ff0;
};
extern "C" {
extern const M4 DAT_002cc260;
void FUN_000ed52c(Vec *, unsigned, EmptyTag);
void FUN_000ed53c(Vec *, unsigned, Pair *, EmptyTag);
}
extern "C" void FUN_000ebe20(Self *p)
{
    unsigned n = p->vec.size;
    FUN_000ed52c(&p->vec, n, EmptyTag());
    p->f58 = 1.0f;
    p->f60 = 0;
    p->f5c = 30;
    p->m = DAT_002cc260;
    p->f64 = 0;
    p->fb0 = 0;
    unsigned newn = p->f5c;
    unsigned oldn = p->vec.size;
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
        FUN_000ed53c(&p->vec, newn - oldn, &tmp, EmptyTag());
    } else if (newn < oldn) {
        FUN_000ed52c(&p->vec, oldn - newn, EmptyTag());
    }
    p->fc0 = 1.0f;
    p->fc4 = 1.0f;
    p->fc8 = 1.0f;
    p->fcc = 0;
    p->ff0 = 1;
}
