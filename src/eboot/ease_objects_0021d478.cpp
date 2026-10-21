/* HSTMATCH module=EBOOT.BIN start=0x0021d478 end=0x0021d79c symbol=FUN_0021d478 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
    char pad[0x60];
    float f60;
    float f64;
    char pad68[0x78 - 0x68];
    float f78;
};
struct Flags {
    char pad[0x8b];
    signed char a : 2;
    signed char b : 2;
    signed char c : 2;
    signed char d : 2;
};
struct Self {
    char pad0[0x54];
    unsigned char f54;
    char pad55[0x64 - 0x55];
    int f64;
    int f68;
    int f6c;
    Obj *objs[3];
    int *u7c;
    char pad80[0x88 - 0x80];
    int *u88;
    char pad8c[0x94 - 0x8c];
    int *u94;
    char pad98[0xa0 - 0x98];
    unsigned char fa0;
};

extern int DAT_0034179c;
extern float DAT_0034a1a0;
extern float DAT_0034a1a4;
extern float DAT_0034a1b0;
extern float DAT_002f05e8;
extern float DAT_002f05ec[];
extern int DAT_002eff90;
extern int DAT_002eff94;
extern Flags *DAT_002cfc8c;

extern "C" {
int FUN_001b1f7c(int *, int);
float FUN_000ede98(float, float, float, float);
float FUN_0000bd2c(float);
void FUN_00103480(Self *);
void FUN_000ffb3c(int *, int);
void FUN_001b1c44(int *, int);
void FUN_00103628(Self *, int);
void FUN_00103128(Self *);

void FUN_0021d478(Self *self)
{
    if (self->f6c >= 0) {
        if (FUN_001b1f7c(&DAT_0034179c, self->f6c) == 0) {
            self->f6c = -1;
        }
    }
    int v = self->f64;
    if (v >= 0) {
        Obj *o = self->objs[self->f68];
        float f0 = o->f60;
        float f1 = o->f64;
        float f2 = o->f78;
        float a, b, c;
        if (v < 100) {
            a = FUN_000ede98(f0, 0.0f, DAT_002f05e8, 0.01f);
            b = FUN_000ede98(f1, DAT_002f05ec[self->f68], DAT_002f05e8, 0.01f);
            c = FUN_000ede98(f2, 1.0f, DAT_002f05e8, 0.01f);
        } else {
            a = FUN_000ede98(f0, -DAT_0034a1a0, DAT_002f05e8, 0.01f);
            b = FUN_000ede98(f1, -DAT_0034a1a4 + DAT_002f05ec[self->f68], DAT_002f05e8, 0.01f);
            c = FUN_000ede98(f2, DAT_0034a1b0, DAT_002f05e8, 0.01f);
        }
        self->objs[self->f68]->f60 = FUN_0000bd2c(a);
        self->objs[self->f68]->f64 = FUN_0000bd2c(b);
        self->objs[self->f68]->f78 = c;
        FUN_00103480(self);
        if (self->f64 >= DAT_002eff90 + 20 && self->fa0 != 0) {
            switch (self->f68) {
            case 0:
                FUN_000ffb3c(self->u7c, 0);
                break;
            case 1:
                FUN_000ffb3c(self->u88, 0);
                break;
            case 2:
                FUN_000ffb3c(self->u94, 0);
                break;
            }
            if (DAT_002cfc8c->b == 0) {
                FUN_001b1c44(&DAT_0034179c, 3);
                self->fa0 = 0;
                self->f64 = 100;
            }
        } else {
            FUN_000ffb3c(self->u7c, 1);
            FUN_000ffb3c(self->u88, 1);
            FUN_000ffb3c(self->u94, 1);
            self->f64 = self->f64 + 1;
        }
        if (self->f64 >= DAT_002eff94) {
            FUN_00103628(self, 1);
            self->f54 = 1;
            self->f64 = -1;
        }
    }
    FUN_00103128(self);
}
}
