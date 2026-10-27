/* HSTMATCH module=EBOOT.BIN start=0x0021f1fc end=0x0021f2d4 symbol=FUN_0021f1fc lang=c++ */
/* Hand-written reconstruction from the disassembly (twin of src/sharing_main/init_clamped_entry_0022e770.cpp with the addresses substituted; same shape as the matched sibling src/eboot/init_clamped_entries_002216cc.cpp: the clamp is an inline helper taking value and bounds by const reference, which gives retail's double loads); exact match verified; names and types await human review. */
/* Stores DAT_002eff90 and the flag 1, calls FUN_0021f30c(o), initialises the entry's two floats from
   globals and its +0x78 float from DAT_0034a1d0 clamped to [DAT_002f0950, DAT_002f0954], calls
   FUN_00103480(o) and keeps the result of FUN_001b2af0(&DAT_0034179c, 12) at +0x60. */
extern "C" {
extern unsigned DAT_002eff90;
extern float DAT_002f0950;
extern float DAT_002f0954;
extern float DAT_0034a1c0;
extern float DAT_0034a1c4;
extern float DAT_0034a1d0;
extern char DAT_0034179c;
void FUN_0021f30c(void *);
void FUN_00103480(void *);
int FUN_001b2af0(void *, int);
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

extern "C" void FUN_0021f1fc(Obj *o)
{
    o->f5c = DAT_002eff90;
    o->f70 = 1;
    FUN_0021f30c(o);
    o->ent->f60 = DAT_0034a1c0;
    o->ent->f64 = DAT_0034a1c4;
    o->ent->f78 = Clamp(DAT_0034a1d0, DAT_002f0950, DAT_002f0954);
    FUN_00103480(o);
    o->f60 = FUN_001b2af0(&DAT_0034179c, 0xc);
}
