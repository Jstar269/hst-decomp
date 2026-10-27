/* HSTMATCH module=hstp_trans_main.prx start=0x00230590 end=0x002306d0 symbol=FUN_00230590 lang=c++ */
/* Hand-written reconstruction from the disassembly (modelled on the EBOOT relative src/eboot/init_clamped_entries_002216cc.cpp); exact match verified; names and types await human review. */
/* Twin of EBOOT 0x22101c. Stores the start value, index n - 1 and the active flag, runs FUN_0023080c, calls slot 1
   of the fifth entry with 0, sets the two index cells (both fields) from their base globals plus the index, then
   resets the five entries' floats with the const-reference clamp (retail reloads each bound) and finishes with
   FUN_00108dac and FUN_001c0bb0(&DAT_003eaad8, 0x21). Names provisional. */
extern "C" {
extern unsigned DAT_0039835c;
extern int DAT_003990c8;
extern int DAT_003990a4;
extern float DAT_003990d8;
extern float DAT_0039910c;
extern float DAT_00399110;
extern float DAT_003f3570;
extern float DAT_003f3574;
extern char DAT_003eaad8;
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
    return value < lo ? lo : (!(value > hi) ? value : hi);
}

struct Cell {
    char pad0[0x24];
    int f24;
    int f28;
};

static inline void SetCell(Cell *c, int v)
{
    c->f24 = v;
    c->f28 = v;
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
    char pad78[0x10];
    Cell *f88;
    char pad8c[0x8];
    Cell *f94;
    char pad98[0x4];
    unsigned char f9c;
};

extern "C" {
void FUN_0023080c(Obj *);
void FUN_00108dac(Obj *);
int FUN_001c0bb0(void *, int);
}

extern "C" void FUN_00230590(Obj *o, int n)
{
    o->f60 = DAT_0039835c;
    o->f54 = n - 1;
    o->f9c = 1;
    FUN_0023080c(o);
    o->ents[4]->m(0);
    SetCell(o->f94, DAT_003990c8 + o->f54);
    SetCell(o->f88, DAT_003990a4 + o->f54);
    for (int i = 0; i < 5; i++) {
        o->ents[i]->f60 = DAT_003f3570;
        o->ents[i]->f64 = DAT_003f3574;
        o->ents[i]->f78 = Clamp(DAT_003990d8, DAT_0039910c, DAT_00399110);
    }
    FUN_00108dac(o);
    FUN_001c0bb0(&DAT_003eaad8, 0x21);
}
