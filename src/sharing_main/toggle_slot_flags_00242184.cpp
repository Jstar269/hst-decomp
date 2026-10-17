/* HSTMATCH module=hstp_trans_main.prx start=0x00242184 end=0x002422f0 symbol=FUN_00242184 lang=c++ */
/* Clone of src/eboot/toggle_slot_flags_00232084.cpp (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
    char pad0[0x64];
    void *w[14];
    char pad1[0x1da - 0x64 - 14 * 4];
    unsigned char f1da;
    char pad2;
    int f1dc;
};

extern "C" void FUN_00105470(void *, int);

static inline bool Ne(int a, int b)
{
    return !(a == b);
}

extern "C" void FUN_00242184(Obj *o, int mode)
{
    int st = o->f1dc;
    int a = Ne(st, 0);
    int b = Ne(st, 1);
    if (mode != 0) {
        for (int i = 2; i <= 13; i++) FUN_00105470(o->w[i], 1);
    } else if (o->f1da != 0) {
        FUN_00105470(o->w[12], a);
        FUN_00105470(o->w[13], b);
        FUN_00105470(o->w[7], a);
        FUN_00105470(o->w[8], a);
        FUN_00105470(o->w[9], a);
        FUN_00105470(o->w[10], a);
        FUN_00105470(o->w[11], 0);
        for (int i = 2; i <= 6; i++) FUN_00105470(o->w[i], 1);
    } else {
        FUN_00105470(o->w[5], a);
        FUN_00105470(o->w[6], b);
        FUN_00105470(o->w[2], a);
        FUN_00105470(o->w[3], a);
        FUN_00105470(o->w[4], 0);
        for (int i = 7; i <= 13; i++) FUN_00105470(o->w[i], 1);
    }
}
