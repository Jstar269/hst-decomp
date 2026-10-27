/* HSTMATCH module=hstp_trans_main.prx start=0x002306d0 end=0x002307d4 symbol=FUN_002306d0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Follows the sibling src/sharing_main/init_clamped_entries_00230c40.cpp (same entry loop and const-reference Clamp, five entries here); FUN_0023080c takes the object Ghidra dropped; the +0x70 entry is the polymorphic object whose second virtual is called with 0. */
extern "C" {
extern unsigned DAT_0039835c;
extern float DAT_003990d8;
extern float DAT_00399114;
extern float DAT_00399118;
extern float DAT_003f3570;
extern float DAT_003f3574;
extern char DAT_003eaad8;
void FUN_0023080c(void *);
void FUN_00108dac(void *);
int FUN_001c0bb0(void *, int);
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

extern "C" void FUN_002306d0(Obj *o)
{
    o->f60 = DAT_0039835c;
    o->f54 = 0;
    o->f9c = 1;
    FUN_0023080c(o);
    o->ents[3]->m(0);
    for (int i = 0; i < 5; i++) {
        o->ents[i]->f60 = DAT_003f3570;
        o->ents[i]->f64 = DAT_003f3574;
        o->ents[i]->f78 = Clamp(DAT_003990d8, DAT_00399114, DAT_00399118);
    }
    FUN_00108dac(o);
    FUN_001c0bb0(&DAT_003eaad8, 0x21);
}
