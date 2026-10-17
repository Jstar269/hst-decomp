/* HSTMATCH module=EBOOT.BIN start=0x00152948 end=0x00152a58 symbol=FUN_00152948 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: typed struct instead of pointer arithmetic, the mode is an unsigned int (masked ushort result) tested by `switch (m) { case 2: ...; case 0: ... }` (case 2 body first), goto removed; exact match verified; names and types await human review. */
struct S_00152948 {
    unsigned int vptr;
    unsigned char f4;
    unsigned int f8, fc, f10;
    int f14;
    unsigned int f18;
    unsigned char f1c, f1d;
};
extern "C" {
extern char DAT_0030840c;
extern char DAT_00308bb0;
extern unsigned short FUN_0014f050(unsigned int);
extern int FUN_00159ee0(unsigned int);
}

extern "C" S_00152948 *FUN_00152948(S_00152948 *p, unsigned int r)
{
    unsigned int sVar1;
    p->vptr = (unsigned int)&DAT_0030840c;
    p->f4 = 0;
    p->vptr = (unsigned int)&DAT_00308bb0;
    p->f8 = FUN_0014f050(r);
    p->fc = 0;
    p->f10 = FUN_0014f050(r);
    sVar1 = FUN_0014f050(r);
    p->f14 = (short)FUN_00159ee0(r);
    p->f18 = FUN_0014f050(r);
    p->f1c = 0;
    p->f1d = 0;
    switch (sVar1) {
    case 2:
        p->f1c = 1;
        p->f1d = 1;
        break;
    case 0:
        p->f1d = 1;
        break;
    }
    if (p->f14 < 0) {
        p->f14 = -p->f14;
    }
    int v = p->f14;
    if (v == 0) {
        p->f14 = 1;
    } else if (v == 1) {
        p->f14 = 0;
    }
    return p;
}
