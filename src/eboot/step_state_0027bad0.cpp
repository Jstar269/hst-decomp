/* HSTMATCH module=EBOOT.BIN start=0x0027bad0 end=0x0027be20 symbol=FUN_0027bad0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed C++ structs, the neg-position path as the else arm of `prev >= 0.0f`, repeated mode calls as written (the 4/1/2 tests are one || chain, bodies of the duplicated float-call arms spelled out twice), the 1.0f step in a non-const local (value-first add.s / shared $f3), table entries indexed `tab[o->f54].f34` (index-first); 0x477eff00 is 65279.0f; exact match verified; names and types await human review. */
struct Entry {
    char pad0[0x24];
    int f24;
    char pad1[0x30 - 0x28];
    int f30;
    int f34;
    char pad2[0x40 - 0x38];
};
struct Sub {
    char pad[0x30];
    int f30;
};
struct Iface {
    virtual void v0();
    virtual void v1(int);
};
struct Obj {
    char pad0[0x50];
    Sub *f50;
    int f54;
    char pad1[4];
    float f5c;
    float f60;
    unsigned char f64;
    char pad2[3];
    float f68;
    float f6c;
    float f70;
    int f74;
};
extern "C" {
extern Entry *DAT_0034a7e4;
extern int DAT_00331b84;
extern int DAT_003313c4;
extern Iface *FUN_0027c75c(Obj *);
extern void FUN_0027cb40(Iface *);
extern int FUN_0027c8a0(Obj *);
extern int FUN_0027c8d0(Obj *, int);
extern int FUN_0027c774(Obj *, int);
extern void FUN_0027c908(Obj *, int);
extern void FUN_0027c018(Obj *);
extern void FUN_0027dc90(int, int *);
extern void FUN_00063d08(float, float, int, int);
}

extern "C" void FUN_0027bad0(Obj *o)
{
    if (o->f64 == 0) {
        return;
    }
    float prev = o->f6c;
    if (prev >= 0.0f) {
        float step = 1.0f;
        float cur = o->f60;
        o->f60 = cur + step;
        o->f6c = cur - (float)o->f74;
        if (o->f5c <= 0.0f && DAT_0034a7e4[o->f54].f34 != 0x3c) {
            float lim = o->f70;
            if (o->f6c == lim - step) {
                if (FUN_0027c8a0(o) == 5) {
                    FUN_00063d08(65279.0f, -1.0f, DAT_00331b84, 6);
                } else if (FUN_0027c8a0(o) == 3) {
                    FUN_00063d08(65279.0f, -1.0f, DAT_00331b84, 6);
                }
            } else if (prev < lim && o->f6c >= lim) {
                if (FUN_0027c8a0(o) == 5) {
                    int a;
                    o->f6c = 0.0f;
                    FUN_0027dc90(o->f50->f30, &a);
                    a = FUN_0027c774(o, a);
                    o->f54 = -1;
                    o->f74 = (int)((float)o->f74 + o->f70);
                    FUN_0027c908(o, a);
                } else if (FUN_0027c8a0(o) == 4 || FUN_0027c8a0(o) == 1 || FUN_0027c8a0(o) == 2) {
                    int b;
                    FUN_0027dc90(o->f50->f30, &b);
                    b = FUN_0027c774(o, b);
                    if (DAT_0034a7e4[b].f24 != 0) {
                        o->f6c = 0.0f;
                        o->f54 = -1;
                        o->f74 = (int)((float)o->f74 + o->f70);
                        FUN_0027c908(o, b);
                    }
                } else if (FUN_0027c8a0(o) == 3 && FUN_0027c8d0(o, 1) != 999) {
                    int c;
                    o->f6c = 0.0f;
                    FUN_0027dc90(DAT_0034a7e4[o->f54].f30, &c);
                    c = FUN_0027c774(o, c);
                    o->f54 = -1;
                    o->f74 = (int)((float)o->f74 + o->f70);
                    FUN_0027c908(o, c);
                }
            }
        }
        FUN_0027c018(o);
    } else {
        FUN_0027cb40(FUN_0027c75c(o));
        FUN_0027c75c(o)->v1(DAT_003313c4);
    }
}
