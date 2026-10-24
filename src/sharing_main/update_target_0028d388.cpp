/* HSTMATCH module=hstp_trans_main.prx start=0x0028d388 end=0x0028d638 symbol=FUN_0028d388 lang=c++ */
/* Clone of src/eboot/update_target_0027c018.cpp (hstclone.py tag c162207): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" {
extern float DAT_003a744c;
extern float DAT_003a7450;
extern int DAT_003da704;

float FUN_0000ce54(float, float);
void FUN_00176fbc(void *, void *, void *, float);
void FUN_0028d698(void *, int, void *);
void *FUN_0028dad4(void *);
void *FUN_0028dadc(void *);
int FUN_0028dc10(void *);
int FUN_0028dc40(void *, int);
void FUN_0028deb0(void *);
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

extern "C" void FUN_0028d388(Context *self)
{
    Matrix44 mat;

    if (self->f6c >= self->f70 && FUN_0028dc10(self) != 3 && FUN_0028dc40(self, 0) != 60) {
        FUN_0028deb0(FUN_0028dadc(self));
        TargetObj *t = (TargetObj *)FUN_0028dadc(self);
        t->Update(DAT_003da704);
        return;
    }

    Obj60e2c local_obj;
    TargetObj *target = &local_obj;
    void *s1 = FUN_0028dad4(self);
    void *s0 = FUN_0028dadc(self);
    int mode = FUN_0028dc10(self);

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
            val = 1.0f - FUN_0000ce54(diff, 2.0f) / FUN_0000ce54(f70, 2.0f);
        }
        break;
    }
    case 2:
        val = FUN_0000ce54(self->f6c, 3.0f) / FUN_0000ce54(self->f70, 3.0f);
        break;
    case 4:
    case 5:
    default:
        val = 0.0f;
        break;
    }

    float fVar6 = Clamp(val, DAT_003a744c, DAT_003a7450);

    if (FUN_0028dc10(self) == 3) {
        FUN_0028d698(self, 0, &mat);
        self->f48 = 0;
        target = self->f3c;
    } else {
        if (fVar6 <= 1.0f) {
            FUN_0028deb0(FUN_0028dad4(self));
        }
        if (fVar6 >= 0.0f) {
            FUN_0028deb0(FUN_0028dadc(self));
        }
        FUN_00176fbc(target, s1, s0, fVar6);
    }

    target->Update(DAT_003da704);
}
