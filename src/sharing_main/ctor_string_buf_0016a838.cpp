/* HSTMATCH module=hstp_trans_main.prx start=0x0016a838 end=0x0016a8c8 symbol=FUN_0016a838 lang=c++ */
/* Clone of src/eboot/ctor_string_buf_0015e2ac.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Alloc {};
struct Self_0016a838 {
    int vptr;
    int f4;
    int f8;
    int fc;
    unsigned char f10;
    int f14, f18, f1c;
    void shrink(int n, Alloc) { f18 -= n; }
};
extern "C" {
extern char DAT_003b0678;
extern char DAT_003b2358;
extern int FUN_00000a90(int);
extern char *FUN_000149a8(char *, const char *);
extern int FUN_00014a40(const char *);
}

extern "C" Self_0016a838 *FUN_0016a838(Self_0016a838 *p, const char *s)
{
    p->vptr = (int)&DAT_003b0678;
    p->f4 = 0;
    p->vptr = (int)&DAT_003b2358;
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
