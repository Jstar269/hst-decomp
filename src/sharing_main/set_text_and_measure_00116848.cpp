/* HSTMATCH module=hstp_trans_main.prx start=0x00116848 end=0x00116a78 symbol=FUN_00116848 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idioms: the string copy is written out in both arms of the `p5 == 0` test, the float accumulators use `+=` and the lower clamp goes through an inline const-reference Max); names and types await human review. */
struct Obj {
    char pad0[0xf8];
    char *f0f8;
    char f0fc[0x800];
    short f8fc;
    char pad1[0x900 - 0x8fe];
    float f900;
    float f904;
    char pad2[0x90a - 0x908];
    unsigned char f90a;
};

extern "C" {
extern void *DAT_003ba2c4;
extern void *DAT_003eaaac;
extern int DAT_003eaae0;
extern float DAT_00380008;
extern char DAT_002d14bc[];
extern void FUN_000430d8(void *, float);
extern void FUN_000149a8(char *, const char *);
extern void FUN_00014788(char *, const char *);
extern void FUN_00043530(void *, char *, float *, float *, int);
extern int FUN_001a517c(void *, char *, char *, int);
extern int FUN_001a54ac(void *, char *, char *);
extern void FUN_001151c4(Obj *, int, int, int, int, int, int, int);
}

static inline const float &Max(const float &a, const float &b) { return a < b ? b : a; }

extern "C" void FUN_00116848(Obj *o, int p2, short p3, const char *p4, const char *p5)
{
    FUN_000430d8(DAT_003ba2c4, 100000.5f);
    o->f8fc = p3;
    if (p5 == 0) {
        FUN_000149a8(o->f0fc, p4);
        o->f0f8 = o->f0fc;
    } else {
        FUN_000149a8(o->f0fc, p4);
        FUN_00014788(o->f0fc, p5);
        o->f0f8 = o->f0fc;
    }
    if (o->f90a != 0) {
        o->f900 = (float)FUN_001a517c(DAT_003eaaac, o->f0f8, DAT_002d14bc, 0);
        o->f904 = (float)FUN_001a54ac(DAT_003eaaac, o->f0f8, DAT_002d14bc);
    } else {
        FUN_00043530(DAT_003ba2c4, o->f0f8, &o->f900, &o->f904, 0);
    }
    float scale;
    if (DAT_003eaae0 < 9) scale = 1.15f;
    else scale = 0.85f;
    float x = o->f900 * scale;
    float y = o->f904 * scale;
    x += 48.0f;
    x += (float)p2;
    x = Max(x, DAT_00380008);
    y += 40.0f;
    y += (float)o->f8fc;
    int s;
    if (o->f904 < 20.0f) s = -2;
    else s = 0;
    FUN_001151c4(o, 0, (short)s, (int)x, (int)y, (int)(-x / 2.0f), (int)(-y / 2.0f), 9);
}
