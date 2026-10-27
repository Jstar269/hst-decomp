/* HSTMATCH module=EBOOT.BIN start=0x0022115c end=0x00221260 symbol=FUN_0022115c lang=c++ */
/* Clone of src/sharing_main/reset_clamped_entries_002306d0.cpp (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Follows the sibling src/sharing_main/init_clamped_entries_00230c40.cpp (same entry loop and const-reference Clamp, five entries here); FUN_00221298 takes the object Ghidra dropped; the +0x70 entry is the polymorphic object whose second virtual is called with 0. */
extern "C" {
extern unsigned DAT_002eff90;
extern float DAT_002f0d0c;
extern float DAT_002f0d48;
extern float DAT_002f0d4c;
extern float DAT_0034a240;
extern float DAT_0034a244;
extern char DAT_0034179c;
void FUN_00221298(void *);
void FUN_00103480(void *);
int FUN_001b2af0(void *, int);
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
    return value < lo ? lo : (!(value > hi) ? value : hi);
}

struct Ent {
    virtual void d0();
    virtual void m(int);
    char pad4[0x5c];
    float f60;
    float f64;
    char pad68[0x10];
    float f78;
};

struct Obj {
    char pad0[0x54];
    int f54;
    char pad58[0x8];
    unsigned f60;
    Ent *ents[5];
    char pad78[0x24];
    unsigned char f9c;
};

extern "C" void FUN_0022115c(Obj *o)
{
    o->f60 = DAT_002eff90;
    o->f54 = 0;
    o->f9c = 1;
    FUN_00221298(o);
    o->ents[3]->m(0);
    for (int i = 0; i < 5; i++) {
        o->ents[i]->f60 = DAT_0034a240;
        o->ents[i]->f64 = DAT_0034a244;
        o->ents[i]->f78 = Clamp(DAT_002f0d0c, DAT_002f0d48, DAT_002f0d4c);
    }
    FUN_00103480(o);
    FUN_001b2af0(&DAT_0034179c, 0x21);
}
