/* HSTMATCH module=hstp_trans_main.prx start=0x00203580 end=0x00203860 symbol=FUN_00203580 lang=c++ */
/* Clone of src/eboot/set_scaled_floats_001f4f80.cpp (hstclone.py tag c060607): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a3) corrected by hand: typed Obj/Ent/Ctx structs, const-ref Clamp (double bound loads) with the b521 != 0 arm first, the negated clamp in the other arm, the (int)(x + 0.5f) / -(int)(0.5f - x) rounding as a conditional expression; exact match verified; names and types await human review. */
extern "C" {
extern float DAT_003968dc;
extern float DAT_003968e0;
extern float DAT_003968e4;
extern float DAT_003968e8;
extern float DAT_003968ec;
extern float DAT_003968f0;
extern char DAT_003968f4;
extern char DAT_003968f8;
struct Ent { float f0; char pad[0x11c]; };
extern Ent DAT_003eac04[];
struct Ctx { char pad[0x1394]; float f1394; };
Ctx *FUN_00177d4c(void);
float FUN_00066bb0(void *, char *, int);
int FUN_001ca418(float);
}

static inline float Clamp(const float &v, const float &lo, const float &hi)
{
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

struct Obj {
    char pad0[0x3d4];
    int i3d4;
    char pad1[0x521 - 0x3d8];
    unsigned char b521;
    char pad2[0x597 - 0x522];
    unsigned char b597;
    char pad3[0x5e4 - 0x598];
    float f5e4;
    float f5e8;
    float f5ec;
    float f5f0;
    unsigned char b5f4;
    unsigned char b5f5;
    char pad4[2];
    char sub[1];
};

extern "C" void FUN_00203580(Obj *o, int flag)
{
    o->b597 = 1;
    o->b5f4 = 0;
    o->b5f5 = 0;
    o->f5e4 = FUN_00177d4c()->f1394;
    if (flag != 0) o->f5e4 = 6.3f;
    float base = DAT_003eac04[o->i3d4].f0;
    float a = FUN_00066bb0(o->sub, &DAT_003968f4, 1) * 0.01f;
    float b = FUN_00066bb0(o->sub, &DAT_003968f8, 1);
    if (o->b521 != 0) {
        o->f5e8 = Clamp(a + b * (base - o->f5e4), DAT_003968dc, DAT_003968e0);
    } else {
        o->f5e8 = -Clamp(a + b * (o->f5e4 - base), DAT_003968e4, DAT_003968e8);
    }
    if (flag != 0) o->f5e8 = 0.2f;
    float s = o->f5e8 * 100.0f;
    int r = s > 0.0f ? (int)(s + 0.5f) : -(int)(0.5f - s);
    o->f5e8 = (float)r * 0.01f;
    o->f5ec = Clamp(o->f5e4 + o->f5e8, DAT_003968ec, DAT_003968f0);
    if (flag != 0) o->f5ec = 7.3f;
    o->f5f0 = o->f5e4;
    int x = FUN_001ca418(o->f5e4);
    int y = FUN_001ca418(o->f5ec);
    if (x != y) {
        o->b5f4 = 1;
        if (y < x) o->b5f5 = 1;
        else o->b5f5 = 0;
    }
    if (flag != 0) {
        o->b5f4 = 1;
        o->b5f5 = 1;
    }
}
