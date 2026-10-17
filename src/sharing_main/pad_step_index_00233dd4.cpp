/* HSTMATCH module=hstp_trans_main.prx start=0x00233dd4 end=0x00233f50 symbol=FUN_00233dd4 lang=c++ */
/* Clone of src/eboot/pad_step_index_00224860.cpp (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: pad flags as signed 2-bit fields (layout of debug_camera_update_000b94b8.cpp), the two clamps as an inline Clamp(v, const lo&, const hi&), virtual hook call; matching idiom: hi = count-1 is computed into a local before v = cur+-1; exact match verified; names and types await human review. */
struct Pad {
    char pad0[0x89];
    signed char a0 : 2;
    signed char a1 : 2;
    signed char a2 : 2;
    signed char a3 : 2;
    char pad8a;
    signed char b0 : 2;
    signed char b1 : 2;
    signed char b2 : 2;
    signed char b3 : 2;
};
struct Hook {
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
struct Obj {
    char pad0[0x54];
    unsigned char f54;
    char pad55[0x88 - 0x55];
    Hook *hook;
    void *p8c;
    int cur;
    int count;
    char pad98[0x118 - 0x98];
    unsigned char f118;
};
extern Pad *DAT_003751d4;
extern int DAT_003995d4;
extern int DAT_003995d8;
extern char DAT_003eaad8;
extern "C" void FUN_00108a2c(Obj *o);
extern "C" void FUN_00111b58(void *p, int v, int z);
extern "C" void FUN_001bfc3c(void *p, int v);
extern "C" void FUN_00233cac(Obj *o, int v);
inline int Clamp(int v, const int &lo, const int &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}
extern "C" void FUN_00233dd4(Obj *o)
{
    if (o->f54 == 0 && o->f118 == 0) {
        int old = o->cur;
        if (DAT_003751d4->a3 == 0) {
            int hi = o->count - 1;
            int v = old - 1;
            o->cur = Clamp(v, DAT_003995d4, hi);
        } else if (DAT_003751d4->a1 == 0) {
            int hi = o->count - 1;
            int v = old + 1;
            o->cur = Clamp(v, DAT_003995d8, hi);
        } else if (DAT_003751d4->b1 == 0) {
            FUN_001bfc3c(&DAT_003eaad8, 3);
            o->f118 = 1;
        }
        if (old != o->cur) {
            FUN_00111b58(o->p8c, o->cur, 0);
            FUN_00233cac(o, o->cur);
            FUN_001bfc3c(&DAT_003eaad8, 1);
        }
    }
    FUN_00108a2c(o);
    if (o->hook != 0) {
        o->hook->v2();
    }
}
