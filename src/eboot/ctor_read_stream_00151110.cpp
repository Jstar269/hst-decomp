/* HSTMATCH module=EBOOT.BIN start=0x00151110 end=0x00151204 symbol=FUN_00151110 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: the flag readers 0x159ef4 return int (no andi; `!f()` gives sltu/xori), and the nested range test is `if (v < 0) {..; flag = 1;} else { if (v == 0) .. = 1; else if (v == 1) .. = 0; flag = 0; }` (one shared flag store); exact match verified; names and types await human review. */
struct Self {
    int vptr;
    unsigned char f4;
    int f8, fc;
    int f10;
    int f14;
    unsigned char f18, f19, f1a;
};
extern "C" {
extern char DAT_0030840c;
extern char DAT_00308db8;
extern unsigned short FUN_0014f050(void *);
extern short FUN_00159ee0(void *);
extern int FUN_00159ef4(void *);
}

extern "C" Self *FUN_00151110(Self *p, void *s)
{
    p->vptr = (int)&DAT_0030840c;
    p->f4 = 0;
    p->vptr = (int)&DAT_00308db8;
    p->f8 = FUN_00159ee0(s);
    p->fc = FUN_00159ee0(s);
    p->f10 = FUN_0014f050(s);
    p->f14 = FUN_00159ee0(s);
    p->f19 = FUN_00159ef4(s) != 0;
    p->f1a = !FUN_00159ef4(s);
    int v = p->f14;
    if (v < 0) {
        p->f14 = -v;
        p->f18 = 1;
    } else {
        if (v == 0)
            p->f14 = 1;
        else if (v == 1)
            p->f14 = 0;
        p->f18 = 0;
    }
    return p;
}
