/* HSTMATCH module=EBOOT.BIN start=0x000adb10 end=0x000adc94 symbol=FUN_000adb10 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Direction clamp/quantise: four SIGNED 2-bit bitfields at +0x89 (read in the order f3, f1, f0, f2) override the
   x/y direction, then atan2 -> +pi/8 -> mod 2pi -> /(pi/4) picks a table index through the pair of extern bounds.
   `pick_index` takes its bounds by const reference so the two global loads are not CSE-ed, and the high clamp is
   written `v > hi ? hi : v` so the compare emits retail's `slt at,v1,a0` (hi < v); the mirror spelling
   `hi > v ? hi : v` is the same clamp but swaps the slt operands (the one word this was parked on). */


extern "C" float FUN_0000c6dc(float a, float b);
extern "C" float FUN_0000c9c4(float a, float b);
extern "C" float DAT_002bfef8[];
extern "C" float DAT_002bfefc[];
extern "C" int DAT_002d470c;
extern "C" int DAT_002d4710;

struct Obj {
    char pad0[0x89];
    signed char f0 : 2;
    signed char f1 : 2;
    signed char f2 : 2;
    signed char f3 : 2;
    char pad1[0x16];
    float fx;
    float pad2;
    float fy;
};

static inline int pick_index(int v, const int &lo, const int &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" void FUN_000adb10(int self, float *outc, float *outs, struct Obj *obj)
{
    float x;
    float y;
    float r;
    float t;
    float w;
    int i;
    int n;

    *outc = 0.0f;
    *outs = 0.0f;
    x = obj->fx;
    y = obj->fy;
    if (obj->f3 >= 0)
        x = -1.0f;
    if (obj->f1 >= 0)
        x = 1.0f;
    if (obj->f0 >= 0)
        y = 1.0f;
    if (obj->f2 >= 0)
        y = -1.0f;
    if (x * x + y * y >= 0.16000001f) {
        r = FUN_0000c6dc(x, y);
        t = r + 0.39269908f;
        w = FUN_0000c9c4(6.2831855f + t, 6.2831855f);
        i = (int)(w / 0.78539816f);
        n = pick_index(i, DAT_002d470c, DAT_002d4710);
        *outc = DAT_002bfef8[n * 2];
        *outs = DAT_002bfefc[n * 2];
    }
}
