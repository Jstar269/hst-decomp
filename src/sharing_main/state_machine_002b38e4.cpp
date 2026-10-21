/* HSTMATCH module=hstp_trans_main.prx start=0x002b38e4 end=0x002b3ae4 symbol=FUN_002b38e4 lang=c++ */
/* Clone of src/eboot/state_machine_002a41cc.cpp (hstclone.py tag c21sn1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Obj60 { char pad[0x60]; float f60; };

struct Self {
    int state;
    int prev;
    int f8;
    Obj60 *f0c;
    int f10, f14, f18, f1c, f20, f24, f28, f2c;
    int pad30;
    short f34;
    short f36;
    float f38;
};

extern int DAT_003eaad8;
extern int DAT_003daec4;

extern "C" {
void FUN_001bfc3c(int *, int);
void FUN_001df9f4(int);
void FUN_001dff28(int);
void FUN_001e3fe8(int);
void FUN_0011fc80(int);
void FUN_00108558(void *);
void FUN_001aa4bc(int);
short FUN_001e4030(int);
short FUN_001e400c(int);
void FUN_001e1e8c(int, float, float);
float FUN_002b3ae4(void *);
void FUN_0006433c(int, float);
Vec4 *FUN_0006f4b4(Vec4 *, float, float, float, float);
void FUN_000646f4(int, Vec4 *, Vec4 *, int, int, int, float, float);

void FUN_002b38e4(Self *self)
{
    if (self->state == 1) {
        FUN_001bfc3c(&DAT_003eaad8, 15);
        self->prev = self->state;
        self->state = 2;
        self->f8 = 0;
        switch (self->state) {
        case 0:
            FUN_001df9f4((int)self->f0c);
            FUN_001aa4bc(DAT_003daec4);
            break;
        case 1:
            if (self->prev != 1) {
                if (self->prev == 0) {
                    self->f0c->f60 = 120.0f;
                    FUN_00108558(self->f0c);
                }
                FUN_001dff28((int)self->f0c);
                FUN_001dff28(self->f10);
                FUN_001df9f4(self->f14);
                FUN_001df9f4(self->f18);
                FUN_0011fc80(self->f1c);
                FUN_001e3fe8(self->f20);
                FUN_001e3fe8(self->f24);
                FUN_001e3fe8(self->f28);
                FUN_001aa4bc(DAT_003daec4);
            }
            break;
        case 2: {
            self->f38 = 0;
            self->f34 = FUN_001e4030(self->f2c);
            self->f36 = FUN_001e400c(self->f2c);
            FUN_001e1e8c(self->f28, self->f38, self->f38);
            FUN_001dff28((int)self->f0c);
            FUN_001df9f4(self->f10);
            FUN_001df9f4(self->f14);
            FUN_001df9f4(self->f18);
            FUN_001e3fe8(self->f1c);
            FUN_001e3fe8(self->f20);
            FUN_001e3fe8(self->f24);
            float f = FUN_002b3ae4(self->f0c);
            FUN_0006433c(DAT_003daec4, 1.0f + f);
            Vec4 b;
            Vec4 a;
            Vec4 *u = FUN_0006f4b4(&b, 0.0f, 0.0f, 0.0f, 0.0f);
            Vec4 *w = FUN_0006f4b4(&a, 0.0f, 0.0f, 0.0f, 0.75f);
            FUN_000646f4(DAT_003daec4, u, w, 5, 0, 0, 65534.0f, -1.0f);
            break;
        }
        }
    }
}
}
