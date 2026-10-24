/* HSTMATCH module=EBOOT.BIN start=0x0027c018 end=0x0027c2c8 symbol=FUN_0027c018 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" {
extern float DAT_002fe6cc;
extern float DAT_002fe6d0;
extern int DAT_003313c4;

float FUN_0000ce3c(float, float);
void FUN_0016adf8(void *, void *, void *, float);
void FUN_0027c328(void *, int, void *);
void *FUN_0027c764(void *);
void *FUN_0027c76c(void *);
int FUN_0027c8a0(void *);
int FUN_0027c8d0(void *, int);
void FUN_0027cb40(void *);
}

struct TargetObj {
    virtual void D0();
    virtual void Update(int);
};

struct Obj60e2c : public TargetObj {
    char pad[144 - 4];
    Obj60e2c();
    ~Obj60e2c();
};

struct Context {
    char pad0[0x3c];
    TargetObj *f3c;     /* 0x3c */
    char pad1[0x48 - 0x40];
    int f48;            /* 0x48 */
    char pad2[0x6c - 0x4c];
    float f6c;          /* 0x6c */
    float f70;          /* 0x70 */
};

static inline float Clamp(const float &v, const float &lo, const float &hi) {
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

struct Matrix44 {
    float m[16];
};

extern "C" void FUN_0027c018(Context *self)
{
    Matrix44 mat;

    if (self->f6c >= self->f70 && FUN_0027c8a0(self) != 3 && FUN_0027c8d0(self, 0) != 60) {
        FUN_0027cb40(FUN_0027c76c(self));
        TargetObj *t = (TargetObj *)FUN_0027c76c(self);
        t->Update(DAT_003313c4);
        return;
    }

    Obj60e2c local_obj;
    TargetObj *target = &local_obj;
    void *s1 = FUN_0027c764(self);
    void *s0 = FUN_0027c76c(self);
    int mode = FUN_0027c8a0(self);

    float val;
    switch (mode) {
    case 1:
    case 3: {
        float f70 = self->f70;
        float f6c = self->f6c;
        if (f6c >= f70) {
            val = 1.0f;
        } else {
            float diff = f70 - f6c;
            val = 1.0f - FUN_0000ce3c(diff, 2.0f) / FUN_0000ce3c(f70, 2.0f);
        }
        break;
    }
    case 2:
        val = FUN_0000ce3c(self->f6c, 3.0f) / FUN_0000ce3c(self->f70, 3.0f);
        break;
    case 4:
    case 5:
    default:
        val = 0.0f;
        break;
    }

    float fVar6 = Clamp(val, DAT_002fe6cc, DAT_002fe6d0);

    if (FUN_0027c8a0(self) == 3) {
        FUN_0027c328(self, 0, &mat);
        self->f48 = 0;
        target = self->f3c;
    } else {
        if (fVar6 <= 1.0f) {
            FUN_0027cb40(FUN_0027c764(self));
        }
        if (fVar6 >= 0.0f) {
            FUN_0027cb40(FUN_0027c76c(self));
        }
        FUN_0016adf8(target, s1, s0, fVar6);
    }

    target->Update(DAT_003313c4);
}
