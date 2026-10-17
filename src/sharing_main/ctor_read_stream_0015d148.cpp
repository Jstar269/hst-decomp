/* HSTMATCH module=hstp_trans_main.prx start=0x0015d148 end=0x0015d23c symbol=FUN_0015d148 lang=c++ */
/* Clone of src/eboot/ctor_read_stream_00151110.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
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
extern char DAT_003b16d8;
extern char DAT_003b2084;
extern unsigned short FUN_0015b050(void *);
extern short FUN_00166458(void *);
extern int FUN_0016646c(void *);
}

extern "C" Self *FUN_0015d148(Self *p, void *s)
{
    p->vptr = (int)&DAT_003b16d8;
    p->f4 = 0;
    p->vptr = (int)&DAT_003b2084;
    p->f8 = FUN_00166458(s);
    p->fc = FUN_00166458(s);
    p->f10 = FUN_0015b050(s);
    p->f14 = FUN_00166458(s);
    p->f19 = FUN_0016646c(s) != 0;
    p->f1a = !FUN_0016646c(s);
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
