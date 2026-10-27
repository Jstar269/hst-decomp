/* HSTMATCH module=EBOOT.BIN start=0x0022101c end=0x0022115c symbol=FUN_0022101c lang=c++ */
/* Hand-written reconstruction (port of src/sharing_main/init_clamped_entries_00230590.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Twin of EBOOT 0x22101c. Stores the start value, index n - 1 and the active flag, runs FUN_00221298, calls slot 1
   of the fifth entry with 0, sets the two index cells (both fields) from their base globals plus the index, then
   resets the five entries' floats with the const-reference clamp (retail reloads each bound) and finishes with
   FUN_00103480 and FUN_001b2af0(&DAT_0034179c, 0x21). Names provisional. */
extern "C" {
extern unsigned DAT_002eff90;
extern int DAT_002f0cfc;
extern int DAT_002f0cd8;
extern float DAT_002f0d0c;
extern float DAT_002f0d40;
extern float DAT_002f0d44;
extern float DAT_0034a240;
extern float DAT_0034a244;
extern char DAT_0034179c;
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
void FUN_00221298(Obj *);
void FUN_00103480(Obj *);
int FUN_001b2af0(void *, int);
}

extern "C" void FUN_0022101c(Obj *o, int n)
{
    o->f60 = DAT_002eff90;
    o->f54 = n - 1;
    o->f9c = 1;
    FUN_00221298(o);
    o->ents[4]->m(0);
    SetCell(o->f94, DAT_002f0cfc + o->f54);
    SetCell(o->f88, DAT_002f0cd8 + o->f54);
    for (int i = 0; i < 5; i++) {
        o->ents[i]->f60 = DAT_0034a240;
        o->ents[i]->f64 = DAT_0034a244;
        o->ents[i]->f78 = Clamp(DAT_002f0d0c, DAT_002f0d40, DAT_002f0d44);
    }
    FUN_00103480(o);
    FUN_001b2af0(&DAT_0034179c, 0x21);
}
