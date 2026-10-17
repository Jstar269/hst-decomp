/* HSTMATCH module=hstp_trans_main.prx start=0x0016aae4 end=0x0016abec symbol=FUN_0016aae4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Constructor of an object (base ctor FUN_00061cb0, vptr DAT_003b2348) that owns a string buffer allocated in the ctor: the StrBuf body is the inline ctor of src/sharing_main/ctor_string_buf_0016a838.cpp with the constant string DAT_00385d04. Matching idioms: `p = alloc(32); if (p) p->init(..); self->buf = p;` (an inline `new StrBuf(..)` gives a plain beqz instead of the shared-store beqzl), the buffer pointer zeroed first, and the trailing pair cleared by `unsigned k = 0; do { a[k] = 0; } while (++k < 2);` (a for loop unrolls). Names provisional. */
struct Alloc {};
extern "C" {
extern char DAT_003b0678;
extern char DAT_003b2358;
extern char DAT_003b2348;
extern char DAT_00385d04[];
extern int FUN_00000a90(int);
extern char *FUN_000149a8(char *, const char *);
extern int FUN_00014a40(const char *);
extern void FUN_00061cb0(void *);
extern void *FUN_00000bcc(int);
}
struct StrBuf {
    int vptr;
    int f4;
    int f8;
    int fc;
    unsigned char f10;
    int f14, f18, f1c;
    void shrink(int n, Alloc) { f18 -= n; }
    void init(const char *s)
    {
        vptr = (int)&DAT_003b0678;
        f4 = 0;
        vptr = (int)&DAT_003b2358;
        f14 = 0;
        f18 = 0;
        f1c = 0;
        int n = FUN_00014a40(s);
        char *b = (char *)FUN_00000a90(n + 1);
        f8 = (int)b;
        FUN_000149a8(b, s);
        fc = 0;
        f10 = 1;
        int m = f18;
        shrink(m, Alloc());
    }
};
struct Obj {
    int vptr;
    char pad4[0x90 - 4];
    int f90;
    int f94;
    int f98;
    float f9c;
    int fa0;
    unsigned char fa4;
    unsigned char fa5;
    unsigned char fa6;
    unsigned char fa7;
    StrBuf *fa8;
    int fac[2];
};
extern "C" Obj *FUN_0016aae4(Obj *self)
{
    FUN_00061cb0(self);
    self->vptr = (int)&DAT_003b2348;
    self->f90 = 0;
    self->f94 = 1;
    self->f98 = 0;
    self->f9c = 1.0f;
    self->fa0 = 0;
    self->fa4 = 0;
    self->fa5 = 0;
    self->fa6 = 1;
    self->fa7 = 1;
    self->fa8 = 0;
    StrBuf *p = (StrBuf *)FUN_00000bcc(32);
    if (p) p->init(DAT_00385d04);
    self->fa8 = p;
    unsigned k = 0;
    do { self->fac[k] = 0; } while (++k < 2);
    return self;
}
