/* HSTMATCH module=EBOOT.BIN start=0x0015e558 end=0x0015e660 symbol=FUN_0015e558 lang=c++ data=0x002de748 */
/* Hand-written reconstruction (port of src/sharing_main/ctor_obj_strbuf_0016aae4.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002de748-0x002de74d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Constructor of an object (base ctor FUN_00060e2c, vptr DAT_0030907c) that owns a string buffer allocated in the ctor: the StrBuf body is the inline ctor of src/sharing_main/ctor_string_buf_0016a838.cpp with the constant string DAT_002de748. Matching idioms: `p = alloc(32); if (p) p->init(..); self->buf = p;` (an inline `new StrBuf(..)` gives a plain beqz instead of the shared-store beqzl), the buffer pointer zeroed first, and the trailing pair cleared by `unsigned k = 0; do { a[k] = 0; } while (++k < 2);` (a for loop unrolls). Names provisional. */
struct Alloc {};
extern "C" {
extern char DAT_003073ac;
extern char DAT_0030908c;
extern char DAT_0030907c;
extern int FUN_00000a90(int);
extern char *FUN_000149a8(char *, const char *);
extern int FUN_00014a40(const char *);
extern void FUN_00060e2c(void *);
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
        vptr = (int)&DAT_003073ac;
        f4 = 0;
        vptr = (int)&DAT_0030908c;
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
extern "C" Obj *FUN_0015e558(Obj *self)
{
    FUN_00060e2c(self);
    self->vptr = (int)&DAT_0030907c;
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
    if (p) p->init("root");
    self->fa8 = p;
    unsigned k = 0;
    do { self->fac[k] = 0; } while (++k < 2);
    return self;
}
