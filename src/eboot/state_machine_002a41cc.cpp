/* HSTMATCH module=EBOOT.BIN start=0x002a41cc end=0x002a43cc symbol=FUN_002a41cc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Obj60 { char pad[0x60]; float unk60; };

struct Machine {
    int state;
    int prevState;
    int unk8;
    Obj60 *unk0c;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int pad30;
    short unk34;
    short unk36;
    float unk38;
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

/* Advance from state 1 to state 2 and run the state-entry setup. */
void FUN_002a41cc(Machine *self)
{
    if (self->state == 1) {
        FUN_001b1c44(&DAT_0034179c, 15);
        self->prevState = self->state;
        self->state = 2;
        self->unk8 = 0;
        switch (self->state) {
        case 0:
            FUN_001d1bf0((int)self->unk0c);
            FUN_0019cf80(DAT_00331b84);
            break;
        case 1:
            if (self->prevState != 1) {
                if (self->prevState == 0) {
                    self->unk0c->unk60 = 120.0f;
                    FUN_00102c54(self->unk0c);
                }
                FUN_001d2124((int)self->unk0c);
                FUN_001d2124(self->unk10);
                FUN_001d1bf0(self->unk14);
                FUN_001d1bf0(self->unk18);
                FUN_00114fb8(self->unk1c);
                FUN_001d61e4(self->unk20);
                FUN_001d61e4(self->unk24);
                FUN_001d61e4(self->unk28);
                FUN_0019cf80(DAT_00331b84);
            }
            break;
        case 2: {
            self->unk38 = 0;
            self->unk34 = FUN_001d6240(self->unk2c);
            self->unk36 = FUN_001d621c(self->unk2c);
            FUN_001d4088(self->unk28, self->unk38, self->unk38);
            FUN_001d2124((int)self->unk0c);
            FUN_001d1bf0(self->unk10);
            FUN_001d1bf0(self->unk14);
            FUN_001d1bf0(self->unk18);
            FUN_001d61e4(self->unk1c);
            FUN_001d61e4(self->unk20);
            FUN_001d61e4(self->unk24);
            float f = FUN_002a43cc(self->unk0c);
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
