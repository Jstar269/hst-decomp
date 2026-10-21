/* HSTMATCH module=EBOOT.BIN start=0x002a41cc end=0x002a43cc symbol=FUN_002a41cc lang=c++ */
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

extern int DAT_0034179c;
extern int DAT_00331b84;

extern "C" {
void FUN_001b1c44(int *, int);
void FUN_001d1bf0(int);
void FUN_001d2124(int);
void FUN_001d61e4(int);
void FUN_00114fb8(int);
void FUN_00102c54(void *);
void FUN_0019cf80(int);
short FUN_001d6240(int);
short FUN_001d621c(int);
void FUN_001d4088(int, float, float);
float FUN_002a43cc(void *);
void FUN_00063478(int, float);
Vec4 *FUN_0006de18(Vec4 *, float, float, float, float);
void FUN_00063830(int, Vec4 *, Vec4 *, int, int, int, float, float);

void FUN_002a41cc(Self *self)
{
    if (self->state == 1) {
        FUN_001b1c44(&DAT_0034179c, 15);
        self->prev = self->state;
        self->state = 2;
        self->f8 = 0;
        switch (self->state) {
        case 0:
            FUN_001d1bf0((int)self->f0c);
            FUN_0019cf80(DAT_00331b84);
            break;
        case 1:
            if (self->prev != 1) {
                if (self->prev == 0) {
                    self->f0c->f60 = 120.0f;
                    FUN_00102c54(self->f0c);
                }
                FUN_001d2124((int)self->f0c);
                FUN_001d2124(self->f10);
                FUN_001d1bf0(self->f14);
                FUN_001d1bf0(self->f18);
                FUN_00114fb8(self->f1c);
                FUN_001d61e4(self->f20);
                FUN_001d61e4(self->f24);
                FUN_001d61e4(self->f28);
                FUN_0019cf80(DAT_00331b84);
            }
            break;
        case 2: {
            self->f38 = 0;
            self->f34 = FUN_001d6240(self->f2c);
            self->f36 = FUN_001d621c(self->f2c);
            FUN_001d4088(self->f28, self->f38, self->f38);
            FUN_001d2124((int)self->f0c);
            FUN_001d1bf0(self->f10);
            FUN_001d1bf0(self->f14);
            FUN_001d1bf0(self->f18);
            FUN_001d61e4(self->f1c);
            FUN_001d61e4(self->f20);
            FUN_001d61e4(self->f24);
            float f = FUN_002a43cc(self->f0c);
            FUN_00063478(DAT_00331b84, 1.0f + f);
            Vec4 b;
            Vec4 a;
            Vec4 *u = FUN_0006de18(&b, 0.0f, 0.0f, 0.0f, 0.0f);
            Vec4 *w = FUN_0006de18(&a, 0.0f, 0.0f, 0.0f, 0.75f);
            FUN_00063830(DAT_00331b84, u, w, 5, 0, 0, 65534.0f, -1.0f);
            break;
        }
        }
    }
}
}
