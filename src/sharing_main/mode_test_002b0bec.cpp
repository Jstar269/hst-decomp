/* HSTMATCH module=hstp_trans_main.prx start=0x002b0bec end=0x002b0c34 symbol=FUN_002b0bec lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* 1 when the mode at +0x1b0 is 1..3, or 5 with the int behind +0x1d0 equal to 2; else 0.
   The flag is the value-context compare `b = mode == 5; if (b) b = ..` (a `bool` adds an andi). */
struct Obj {
    char pad0[0x1b0];
    int mode;
    char pad1[0x1c];
    int *sub;
};

extern "C" int FUN_002b0bec(Obj *o)
{
    int r = 1;
    if ((unsigned)(o->mode - 1) > 2) {
        int b = o->mode == 5;
        if (b) b = *o->sub == 2;
        if (!b) r = 0;
    }
    return r;
}
