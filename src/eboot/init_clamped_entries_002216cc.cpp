/* HSTMATCH module=EBOOT.BIN start=0x002216cc end=0x002217b8 symbol=FUN_002216cc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
extern unsigned DAT_002eff90;
extern float DAT_002f0d94;
extern float DAT_002f0dc8;
extern float DAT_002f0dcc;
extern float DAT_0034a250;
extern float DAT_0034a254;
extern char DAT_0034179c;
void FUN_002217f0(void *);
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
    Ent *ents[2];
    char pad68[0xc];
    unsigned char f74;
};

extern "C" void FUN_002216cc(Obj *o)
{
    o->f5c = DAT_002eff90;
    o->f74 = 1;
    FUN_002217f0(o);
    for (int i = 0; i < 2; i++) {
        o->ents[i]->f60 = DAT_0034a250;
        o->ents[i]->f64 = DAT_0034a254;
        o->ents[i]->f78 = Clamp(DAT_002f0d94, DAT_002f0dc8, DAT_002f0dcc);
    }
    FUN_00103480(o);
    FUN_001b2af0(&DAT_0034179c, 0x21);
}
