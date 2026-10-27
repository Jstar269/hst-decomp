/* HSTMATCH module=hstp_trans_main.prx start=0x0022e770 end=0x0022e848 symbol=FUN_0022e770 lang=c++ */
/* Hand-written reconstruction from the disassembly (same shape as the matched siblings src/sharing_main/init_clamped_entries_00230c40.cpp and apply_float_range_0022f7ac.cpp: the clamp is an inline helper taking value and bounds by const reference, which gives retail's double loads of each bound and of the value); exact match verified; names and types await human review. */
/* Stores DAT_0039835c and the flag 1, calls FUN_0022e880(o), initialises the entry's two floats from
   globals and its +0x78 float from DAT_003f3500 clamped to [DAT_00398d1c, DAT_00398d20], calls
   FUN_00108dac(o) and keeps the result of FUN_001c0bb0(&DAT_003eaad8, 12) at +0x60. */
extern "C" {
extern unsigned DAT_0039835c;
extern float DAT_00398d1c;
extern float DAT_00398d20;
extern float DAT_003f34f0;
extern float DAT_003f34f4;
extern float DAT_003f3500;
extern char DAT_003eaad8;
void FUN_0022e880(void *);
void FUN_00108dac(void *);
int FUN_001c0bb0(void *, int);
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
    return value < lo ? lo : (!(value > hi) ? value : hi);
}

struct Ent {
    char pad0[0x60];
    float f60;
    float f64;
    char pad68[0x10];
    float f78;
};

struct Obj {
    char pad0[0x5c];
    unsigned f5c;
    int f60;
    Ent *ent;
    char pad68[0x8];
    unsigned char f70;
};

extern "C" void FUN_0022e770(Obj *o)
{
    o->f5c = DAT_0039835c;
    o->f70 = 1;
    FUN_0022e880(o);
    o->ent->f60 = DAT_003f34f0;
    o->ent->f64 = DAT_003f34f4;
    o->ent->f78 = Clamp(DAT_003f3500, DAT_00398d1c, DAT_00398d20);
    FUN_00108dac(o);
    o->f60 = FUN_001c0bb0(&DAT_003eaad8, 0xc);
}
