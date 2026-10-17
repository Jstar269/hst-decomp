/* HSTMATCH module=EBOOT.BIN start=0x00224860 end=0x002249dc symbol=FUN_00224860 lang=c++ */
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
extern Pad *DAT_002cfc8c;
extern int DAT_002f1208;
extern int DAT_002f120c;
extern char DAT_0034179c;
extern "C" void FUN_00103128(Obj *o);
extern "C" void FUN_0010b980(void *p, int v, int z);
extern "C" void FUN_001b1c44(void *p, int v);
extern "C" void FUN_00224738(Obj *o, int v);
inline int Clamp(int v, const int &lo, const int &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}
extern "C" void FUN_00224860(Obj *o)
{
    if (o->f54 == 0 && o->f118 == 0) {
        int old = o->cur;
        if (DAT_002cfc8c->a3 == 0) {
            int hi = o->count - 1;
            int v = old - 1;
            o->cur = Clamp(v, DAT_002f1208, hi);
        } else if (DAT_002cfc8c->a1 == 0) {
            int hi = o->count - 1;
            int v = old + 1;
            o->cur = Clamp(v, DAT_002f120c, hi);
        } else if (DAT_002cfc8c->b1 == 0) {
            FUN_001b1c44(&DAT_0034179c, 3);
            o->f118 = 1;
        }
        if (old != o->cur) {
            FUN_0010b980(o->p8c, o->cur, 0);
            FUN_00224738(o, o->cur);
            FUN_001b1c44(&DAT_0034179c, 1);
        }
    }
    FUN_00103128(o);
    if (o->hook != 0) {
        o->hook->v2();
    }
}
