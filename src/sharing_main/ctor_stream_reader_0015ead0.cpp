/* HSTMATCH module=hstp_trans_main.prx start=0x0015ead0 end=0x0015ebe0 symbol=FUN_0015ead0 lang=c++ */
/* Clone of src/eboot/ctor_stream_reader_00152948.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: typed struct instead of pointer arithmetic, the mode is an unsigned int (masked ushort result) tested by `switch (m) { case 2: ...; case 0: ... }` (case 2 body first), goto removed; exact match verified; names and types await human review. */
struct S_0015ead0 {
    unsigned int vptr;
    unsigned char f4;
    unsigned int f8, fc, f10;
    int f14;
    unsigned int f18;
    unsigned char f1c, f1d;
};
extern "C" {
extern char DAT_003b16d8;
extern char DAT_003b1e7c;
extern unsigned short FUN_0015b050(unsigned int);
extern int FUN_00166458(unsigned int);
}

extern "C" S_0015ead0 *FUN_0015ead0(S_0015ead0 *p, unsigned int r)
{
    unsigned int sVar1;
    p->vptr = (unsigned int)&DAT_003b16d8;
    p->f4 = 0;
    p->vptr = (unsigned int)&DAT_003b1e7c;
    p->f8 = FUN_0015b050(r);
    p->fc = 0;
    p->f10 = FUN_0015b050(r);
    sVar1 = FUN_0015b050(r);
    p->f14 = (short)FUN_00166458(r);
    p->f18 = FUN_0015b050(r);
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
