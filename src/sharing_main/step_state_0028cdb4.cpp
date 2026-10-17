/* HSTMATCH module=hstp_trans_main.prx start=0x0028cdb4 end=0x0028d104 symbol=FUN_0028cdb4 lang=c++ */
/* Clone of src/eboot/step_state_0027bad0.cpp (hstclone.py tag s10170158a3r1s): addresses substituted; exact match verified; names and types await human review. */
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
extern Entry *DAT_003f3b14;
extern int DAT_003daec4;
extern int DAT_003da704;
extern Iface *FUN_0028dacc(Obj *);
extern void FUN_0028deb0(Iface *);
extern int FUN_0028dc10(Obj *);
extern int FUN_0028dc40(Obj *, int);
extern int FUN_0028dae4(Obj *, int);
extern void FUN_0028dc78(Obj *, int);
extern void FUN_0028d388(Obj *);
extern void FUN_0028f060(int, int *);
extern void FUN_00064bcc(float, float, int, int);
}

extern "C" void FUN_0028cdb4(Obj *o)
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
        if (o->f5c <= 0.0f && DAT_003f3b14[o->f54].f34 != 0x3c) {
            float lim = o->f70;
            if (o->f6c == lim - step) {
                if (FUN_0028dc10(o) == 5) {
                    FUN_00064bcc(65279.0f, -1.0f, DAT_003daec4, 6);
                } else if (FUN_0028dc10(o) == 3) {
                    FUN_00064bcc(65279.0f, -1.0f, DAT_003daec4, 6);
                }
            } else if (prev < lim && o->f6c >= lim) {
                if (FUN_0028dc10(o) == 5) {
                    int a;
                    o->f6c = 0.0f;
                    FUN_0028f060(o->f50->f30, &a);
                    a = FUN_0028dae4(o, a);
                    o->f54 = -1;
                    o->f74 = (int)((float)o->f74 + o->f70);
                    FUN_0028dc78(o, a);
                } else if (FUN_0028dc10(o) == 4 || FUN_0028dc10(o) == 1 || FUN_0028dc10(o) == 2) {
                    int b;
                    FUN_0028f060(o->f50->f30, &b);
                    b = FUN_0028dae4(o, b);
                    if (DAT_003f3b14[b].f24 != 0) {
                        o->f6c = 0.0f;
                        o->f54 = -1;
                        o->f74 = (int)((float)o->f74 + o->f70);
                        FUN_0028dc78(o, b);
                    }
                } else if (FUN_0028dc10(o) == 3 && FUN_0028dc40(o, 1) != 999) {
                    int c;
                    o->f6c = 0.0f;
                    FUN_0028f060(DAT_003f3b14[o->f54].f30, &c);
                    c = FUN_0028dae4(o, c);
                    o->f54 = -1;
                    o->f74 = (int)((float)o->f74 + o->f70);
                    FUN_0028dc78(o, c);
                }
            }
        }
        FUN_0028d388(o);
    } else {
        FUN_0028deb0(FUN_0028dacc(o));
        FUN_0028dacc(o)->v1(DAT_003da704);
    }
}
