/* HSTMATCH module=EBOOT.BIN start=0x001f4f80 end=0x001f5260 symbol=FUN_001f4f80 lang=c++ data=0x002ee8f4 */
/* Ghidra pseudocode (hstgen.py tag a3) corrected by hand: typed Obj/Entry/Context structs, const-ref Clamp (double bound loads) with the b521 != 0 arm first, the negated clamp in the other arm, the (int)(x + 0.5f) / -(int)(0.5f - x) rounding as a conditional expression; readability pass; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002ee8f4-0x002ee8fa) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern "C" {
extern float DAT_002ee8dc;
extern float DAT_002ee8e0;
extern float DAT_002ee8e4;
extern float DAT_002ee8e8;
extern float DAT_002ee8ec;
extern float DAT_002ee8f0;
struct Entry { float value; char pad[0x11c]; };
extern Entry DAT_003418cc[];
struct Context { char pad[0x1394]; float unk1394; };
Context *FUN_0016bb88(void);
float FUN_000657e4(void *, char *, int);
int FUN_001bc630(float);
}

/* Limit a value to [lo, hi]. */
static inline float Clamp(const float &value_in, const float &lo, const float &hi)
{
    return value_in < lo ? lo : (!(value_in > hi) ? value_in : hi);
}

struct Obj {
    char pad0[0x3d4];
    int entry_index;
    char pad1[0x521 - 0x3d8];
    unsigned char b521;
    char pad2[0x597 - 0x522];
    unsigned char b597;
    char pad3[0x5e4 - 0x598];
    float cur;
    float delta;
    float target;
    float start;
    unsigned char changed;
    unsigned char down;
    char pad4[2];
    char params[1];
};

/* Reset the animated value: pick a start value, a rounded step and a clamped target, and note whether the target crosses into another bucket. */
extern "C" void FUN_001f4f80(Obj *self, int use_defaults)
{
    self->b597 = 1;
    self->changed = 0;
    self->down = 0;
    self->cur = FUN_0016bb88()->unk1394;
    if (use_defaults != 0) self->cur = 6.3f;
    float base = DAT_003418cc[self->entry_index].value;
    float gain_a = FUN_000657e4(self->params, "A", 1) * 0.01f;
    float gain_b = FUN_000657e4(self->params, "B", 1);
    if (self->b521 != 0) {
        self->delta = Clamp(gain_a + gain_b * (base - self->cur), DAT_002ee8dc, DAT_002ee8e0);
    } else {
        self->delta = -Clamp(gain_a + gain_b * (self->cur - base), DAT_002ee8e4, DAT_002ee8e8);
    }
    if (use_defaults != 0) self->delta = 0.2f;
    float scaled = self->delta * 100.0f;
    int rounded = scaled > 0.0f ? (int)(scaled + 0.5f) : -(int)(0.5f - scaled);
    self->delta = (float)rounded * 0.01f;
    self->target = Clamp(self->cur + self->delta, DAT_002ee8ec, DAT_002ee8f0);
    if (use_defaults != 0) self->target = 7.3f;
    self->start = self->cur;
    int cur_bucket = FUN_001bc630(self->cur);
    int new_bucket = FUN_001bc630(self->target);
    if (cur_bucket != new_bucket) {
        self->changed = 1;
        if (new_bucket < cur_bucket) self->down = 1;
        else self->down = 0;
    }
    if (use_defaults != 0) {
        self->changed = 1;
        self->down = 1;
    }
}
