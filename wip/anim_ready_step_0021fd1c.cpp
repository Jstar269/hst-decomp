/* HSTMATCH module=EBOOT.BIN start=0x0021fd1c end=0x00220080 symbol=FUN_0021fd1c lang=c++ */
struct Obj8 {
    char pad[8];
    float f8;
};
struct Entry {
    Obj8 **ptr;
    char pad[0x10 - 4];
    float f10;
    char pad1[0x34 - 0x14];
};
struct Anim {
    char pad0[0xf4];
    Entry ent[1];
    char pad1[0x158 - 0xf4 - 0x34];
    int first;
    volatile int last;
};
struct Dest {
    char pad0[0x60];
    float f60;
    float f64;
    char pad1[0x78 - 0x68];
    float f78;
};
struct Self {
    char pad0[0x54];
    unsigned char f54;
    unsigned char f55;
    char pad1[0x60 - 0x56];
    int f60;
    Dest *f64;
    unsigned *f68[8];
    int pad8;
    Anim *f8c;
};
extern float DAT_002f0a5c;
extern int DAT_002f0a60;
extern int DAT_002f0a64;
extern int DAT_002eff94;
extern unsigned DAT_002f0af0[];
extern float DAT_0034a1e0;
extern float DAT_0034a1e4;
extern float DAT_0034a1f0;
extern int DAT_0034179c;
extern "C" {
void FUN_00059174(Anim *);
void FUN_0005f0d8(Anim *);
float FUN_000ede98(float, float, float, float);
float FUN_0000bd2c(float);
void FUN_00103480(Self *);
void FUN_001b1c44(int *, int);
void FUN_00103628(Self *, int);
void FUN_00103128(Self *);
}

static inline float Level(Entry *e)
{
    return e->ptr != 0 ? (*e->ptr)->f8 : 0.0f;
}

static inline bool Ready(Anim *p)
{
    int i = p->first;
    if (i <= p->last) {
        do {
            float t = Level(&p->ent[i]);
            if (p->ent[i].f10 < t) {
                return false;
            }
            i++;
        } while (i <= p->last);
    }
    return true;
}

extern "C" void FUN_0021fd1c(Self *self)
{
    if (self->f55 != 0) {
        Anim *a = self->f8c;
        if (a != 0) {
            FUN_00059174(a);
            FUN_0005f0d8(a);
            if (Ready(self->f8c)) {
                self->f55 = 0;
            }
        }
    }
    if (self->f54 == 0 && self->f60 >= 0) {
        Dest *d = self->f64;
        float a1;
        float a2;
        float a3;
        float v60 = d->f60;
        float v64 = d->f64;
        float v78 = d->f78;
        if (self->f60 < 100) {
            a1 = FUN_000ede98(v60, 0.0f, DAT_002f0a5c, 0.01f);
            a2 = FUN_000ede98(v64, 0.0f, DAT_002f0a5c, 0.01f);
            a3 = FUN_000ede98(v78, 1.0f, DAT_002f0a5c, 0.01f);
        } else {
            a1 = FUN_000ede98(v60, -DAT_0034a1e0, DAT_002f0a5c, 0.01f);
            a2 = FUN_000ede98(v64, -DAT_0034a1e4, DAT_002f0a5c, 0.01f);
            a3 = FUN_000ede98(v78, DAT_0034a1f0, DAT_002f0a5c, 0.01f);
        }
        self->f64->f60 = FUN_0000bd2c(a1);
        self->f64->f64 = FUN_0000bd2c(a2);
        self->f64->f78 = a3;
        FUN_00103480(self);
        int base = DAT_002f0a60 + DAT_002f0a64;
        int k = self->f60;
        if (k == base) {
            FUN_001b1c44(&DAT_0034179c, 9);
        } else {
            if (base < k) {
                unsigned d = k - base;
                int i = 0;
                do {
                    if (d < 8) {
                        unsigned c = DAT_002f0af0[d] & 0xff;
                        *self->f68[3 - i] = c | (c << 8) | ((DAT_002f0af0[d] - 0x80) * 0x1000000) | (c << 16);
                    } else {
                        *self->f68[3 - i] = 0x808080;
                    }
                    *self->f68[7 - i] = 0x80808080;
                    i++;
                } while (i < 4);
            }
        }
        self->f60 = self->f60 + 1;
        if (self->f60 >= DAT_002eff94) {
            FUN_00103628(self, 1);
            self->f54 = 1;
            self->f60 = -1;
        }
    }
    FUN_00103128(self);
}
// NEAR ~44 words (second pass; was ~80): the Ready scan is now exact (see MWCC-NOTES 0x002a10d8: Anim has `Entry ent[1]` at +0xf4, `volatile int last`, Level() as a ternary,
//  `if (i <= p->last) { do { ... if (p->ent[i].f10 < t) return false; i++; } while (i <= p->last); } return true;`), as is the colour update (v60/v64/v78 loaded before the branch) and the
//  `self->f60 = self->f60 + 1; if (self->f60 >= DAT_002eff94)` tail (both paths reload f60: the call arm's reload sits in the `b` delay slot).
// Open: register colours of the 4-iteration colour-word loop. Retail: d = k - base in a0, table pointer v1, i = a1, hoisted constants 3 = v0, 7 = t1, 0x808080 = t2, 0x80808080 = t0;
//  ours: d = v1, pointer v0, i = a0, 3 = t2, 7 = a3, 0x808080 = t1. Declaration order of {i, d, tp} (all six), named d / table pointer / loaded element, do-while vs for: no change.
// near miss from lane sn6 (unreviewed)
