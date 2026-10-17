/* HSTMATCH module=EBOOT.BIN start=0x0015088c end=0x00150924 symbol=FUN_0015088c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Self_0015088c {
    void *vptr;
    int f4;
    void *f8;
    void *fc;
};
extern "C" {
extern char DAT_0030840c;
extern char DAT_00308ec4;
extern void FUN_000009e4(void *);
extern void FUN_00000a00(void *);
}

extern "C" Self_0015088c *FUN_0015088c(Self_0015088c *p, short flag)
{
    if (p != 0) {
        p->vptr = &DAT_00308ec4;
        if (p->fc != 0) {
            FUN_000009e4(p->fc);
            p->fc = 0;
        }
        if (p->f8 != 0) {
            FUN_000009e4(p->f8);
            p->f8 = 0;
        }
        if (p != 0) {
            p->vptr = &DAT_0030840c;
        }
        if (0 < flag) {
            FUN_00000a00(p);
        }
    }
    return p;
}
