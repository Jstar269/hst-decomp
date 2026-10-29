/* HSTMATCH module=EBOOT.BIN start=0x0015e2ac end=0x0015e33c symbol=FUN_0015e2ac lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Alloc {};
struct StringBuf {
    int vptr;
    int f4;
    int f8;
    int fc;
    unsigned char f10;
    int f14, f18, f1c;
    void shrink(int n, Alloc) { f18 -= n; }
};
extern "C" {
extern char DAT_003073ac;
extern char DAT_0030908c;
extern int FUN_00000a90(int);
extern char *FUN_000149a8(char *, const char *);
extern int FUN_00014a40(const char *);
}

extern "C" StringBuf *FUN_0015e2ac(StringBuf *p, const char *s)
{
    p->vptr = (int)&DAT_003073ac;
    p->f4 = 0;
    p->vptr = (int)&DAT_0030908c;
    p->f14 = 0;
    p->f18 = 0;
    p->f1c = 0;
    int n = FUN_00014a40(s);
    char *b = (char *)FUN_00000a90(n + 1);
    p->f8 = (int)b;
    FUN_000149a8(b, s);
    p->fc = 0;
    p->f10 = 1;
    int m = p->f18;
    p->shrink(m, Alloc());
    return p;
}
