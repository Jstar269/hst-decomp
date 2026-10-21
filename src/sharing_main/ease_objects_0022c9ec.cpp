/* HSTMATCH module=hstp_trans_main.prx start=0x0022c9ec end=0x0022cd10 symbol=FUN_0022c9ec lang=c++ */
/* Clone of src/eboot/ease_objects_0021d478.cpp (hstclone.py tag c21sn1s): addresses substituted; exact match verified; names and types await human review. */
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

extern int DAT_003eaad8;
extern float DAT_003f34d0;
extern float DAT_003f34d4;
extern float DAT_003f34e0;
extern float DAT_003989b4;
extern float DAT_003989b8[];
extern int DAT_0039835c;
extern int DAT_00398360;
extern Flags *DAT_003751d4;

extern "C" {
int FUN_001c0010(int *, int);
float FUN_000f3560(float, float, float, float);
float FUN_0000bd44(float);
void FUN_00108dac(Self *);
void FUN_00105470(int *, int);
void FUN_001bfc3c(int *, int);
void FUN_00108f54(Self *, int);
void FUN_00108a2c(Self *);

void FUN_0022c9ec(Self *self)
{
    if (self->f6c >= 0) {
        if (FUN_001c0010(&DAT_003eaad8, self->f6c) == 0) {
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
            a = FUN_000f3560(f0, 0.0f, DAT_003989b4, 0.01f);
            b = FUN_000f3560(f1, DAT_003989b8[self->f68], DAT_003989b4, 0.01f);
            c = FUN_000f3560(f2, 1.0f, DAT_003989b4, 0.01f);
        } else {
            a = FUN_000f3560(f0, -DAT_003f34d0, DAT_003989b4, 0.01f);
            b = FUN_000f3560(f1, -DAT_003f34d4 + DAT_003989b8[self->f68], DAT_003989b4, 0.01f);
            c = FUN_000f3560(f2, DAT_003f34e0, DAT_003989b4, 0.01f);
        }
        self->objs[self->f68]->f60 = FUN_0000bd44(a);
        self->objs[self->f68]->f64 = FUN_0000bd44(b);
        self->objs[self->f68]->f78 = c;
        FUN_00108dac(self);
        if (self->f64 >= DAT_0039835c + 20 && self->fa0 != 0) {
            switch (self->f68) {
            case 0:
                FUN_00105470(self->u7c, 0);
                break;
            case 1:
                FUN_00105470(self->u88, 0);
                break;
            case 2:
                FUN_00105470(self->u94, 0);
                break;
            }
            if (DAT_003751d4->b == 0) {
                FUN_001bfc3c(&DAT_003eaad8, 3);
                self->fa0 = 0;
                self->f64 = 100;
            }
        } else {
            FUN_00105470(self->u7c, 1);
            FUN_00105470(self->u88, 1);
            FUN_00105470(self->u94, 1);
            self->f64 = self->f64 + 1;
        }
        if (self->f64 >= DAT_00398360) {
            FUN_00108f54(self, 1);
            self->f54 = 1;
            self->f64 = -1;
        }
    }
    FUN_00108a2c(self);
}
}
