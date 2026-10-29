/* HSTMATCH module=EBOOT.BIN start=0x0027c018 end=0x0027c2c8 symbol=FUN_0027c018 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/blend_obj.h"

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

static inline float Clamp(const float &v, const float &lo, const float &hi) {
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

/* 4x4 float matrix filled in by the callee. */
struct Matrix44 {
    float m[16];
};

extern "C" void FUN_0027c018(BlendObj *self)
{
    Matrix44 pose;

    if (self->elapsed >= self->duration && FUN_0027c8a0(self) != 3 && FUN_0027c8d0(self, 0) != 60) {
        FUN_0027cb40(FUN_0027c76c(self));
        TargetObj *t = (TargetObj *)FUN_0027c76c(self);
        t->Update(DAT_003313c4);
        return;
    }

    Obj60e2c scratch;
    TargetObj *target = &scratch;
    void *srcA = FUN_0027c764(self);
    void *srcB = FUN_0027c76c(self);
    int mode = FUN_0027c8a0(self);

    float ratio;
    switch (mode) {
    case 1:
    case 3: {
        float duration = self->duration;
        float elapsed = self->elapsed;
        if (elapsed >= duration) {
            ratio = 1.0f;
        } else {
            float remaining = duration - elapsed;
            ratio = 1.0f - FUN_0000ce3c(remaining, 2.0f) / FUN_0000ce3c(duration, 2.0f);
        }
        break;
    }
    case 2:
        ratio = FUN_0000ce3c(self->elapsed, 3.0f) / FUN_0000ce3c(self->duration, 3.0f);
        break;
    case 4:
    case 5:
    default:
        ratio = 0.0f;
        break;
    }

    float blend = Clamp(ratio, DAT_002fe6cc, DAT_002fe6d0);

    if (FUN_0027c8a0(self) == 3) {
        FUN_0027c328(self, 0, &pose);
        self->unk48 = 0;
        target = (TargetObj *)self->target;
    } else {
        if (blend <= 1.0f) {
            FUN_0027cb40(FUN_0027c764(self));
        }
        if (blend >= 0.0f) {
            FUN_0027cb40(FUN_0027c76c(self));
        }
        FUN_0016adf8(target, srcA, srcB, blend);
    }

    target->Update(DAT_003313c4);
}
