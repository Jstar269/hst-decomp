/* HSTMATCH module=EBOOT.BIN start=0x00232084 end=0x002321f0 symbol=FUN_00232084 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
    char pad0[0x64];
    void *w[14];
    char pad1[0x1da - 0x64 - 14 * 4];
    unsigned char f1da;
    char pad2;
    int f1dc;
};

extern "C" void FUN_000ffb3c(void *, int);

static inline bool Ne(int a, int b)
{
    return !(a == b);
}

extern "C" void FUN_00232084(Obj *o, int mode)
{
    int st = o->f1dc;
    int a = Ne(st, 0);
    int b = Ne(st, 1);
    if (mode != 0) {
        for (int i = 2; i <= 13; i++) FUN_000ffb3c(o->w[i], 1);
    } else if (o->f1da != 0) {
        FUN_000ffb3c(o->w[12], a);
        FUN_000ffb3c(o->w[13], b);
        FUN_000ffb3c(o->w[7], a);
        FUN_000ffb3c(o->w[8], a);
        FUN_000ffb3c(o->w[9], a);
        FUN_000ffb3c(o->w[10], a);
        FUN_000ffb3c(o->w[11], 0);
        for (int i = 2; i <= 6; i++) FUN_000ffb3c(o->w[i], 1);
    } else {
        FUN_000ffb3c(o->w[5], a);
        FUN_000ffb3c(o->w[6], b);
        FUN_000ffb3c(o->w[2], a);
        FUN_000ffb3c(o->w[3], a);
        FUN_000ffb3c(o->w[4], 0);
        for (int i = 7; i <= 13; i++) FUN_000ffb3c(o->w[i], 1);
    }
}
