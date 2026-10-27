/* HSTMATCH module=EBOOT.BIN start=0x001f4f80 end=0x001f5260 symbol=FUN_001f4f80 lang=c++ data=0x002ee8f4 */
/* Ghidra pseudocode (hstgen.py tag a3) corrected by hand: typed Obj/Ent/Ctx structs, const-ref Clamp (double bound loads) with the b521 != 0 arm first, the negated clamp in the other arm, the (int)(x + 0.5f) / -(int)(0.5f - x) rounding as a conditional expression; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002ee8f4-0x002ee8fa) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern "C" {
extern float DAT_002ee8dc;
extern float DAT_002ee8e0;
extern float DAT_002ee8e4;
extern float DAT_002ee8e8;
extern float DAT_002ee8ec;
extern float DAT_002ee8f0;
struct Ent { float f0; char pad[0x11c]; };
extern Ent DAT_003418cc[];
struct Ctx { char pad[0x1394]; float f1394; };
Ctx *FUN_0016bb88(void);
float FUN_000657e4(void *, char *, int);
int FUN_001bc630(float);
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

extern "C" void FUN_001f4f80(Obj *o, int flag)
{
    o->b597 = 1;
    o->b5f4 = 0;
    o->b5f5 = 0;
    o->f5e4 = FUN_0016bb88()->f1394;
    if (flag != 0) o->f5e4 = 6.3f;
    float base = DAT_003418cc[o->i3d4].f0;
    float a = FUN_000657e4(o->sub, "A", 1) * 0.01f;
    float b = FUN_000657e4(o->sub, "B", 1);
    if (o->b521 != 0) {
        o->f5e8 = Clamp(a + b * (base - o->f5e4), DAT_002ee8dc, DAT_002ee8e0);
    } else {
        o->f5e8 = -Clamp(a + b * (o->f5e4 - base), DAT_002ee8e4, DAT_002ee8e8);
    }
    if (flag != 0) o->f5e8 = 0.2f;
    float s = o->f5e8 * 100.0f;
    int r = s > 0.0f ? (int)(s + 0.5f) : -(int)(0.5f - s);
    o->f5e8 = (float)r * 0.01f;
    o->f5ec = Clamp(o->f5e4 + o->f5e8, DAT_002ee8ec, DAT_002ee8f0);
    if (flag != 0) o->f5ec = 7.3f;
    o->f5f0 = o->f5e4;
    int x = FUN_001bc630(o->f5e4);
    int y = FUN_001bc630(o->f5ec);
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
