/* HSTMATCH module=hstp_trans_main.prx start=0x00134de4 end=0x00135204 symbol=FUN_00134de4 lang=c++ */
/* Clone of src/eboot/avatar_mode_update_00129b74.cpp (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: the dot product is an inline LengthSq() (a direct FUN_00022500 call inside the compare loads the threshold global before the call and keeps it in $f20), the walk/run rate is `rate = K / f; rate *= len;` (one expression puts the length first in mul.s), the mode cases are written 0/4/5, 11, 12 (retail tests them in reverse); names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Obj {
    char pad000[0x160];
    Vec4 v160;
    char pad170[0x190 - 0x170];
    int mode;
    char pad194[0x1b0 - 0x194];
    Vec4 v1b0;
    Vec4 v1c0;
    char pad1d0[0x220 - 0x1d0];
    unsigned char f220;
    unsigned char f221;
    char pad222[0x250 - 0x222];
    int counter;
    char pad254[0x320 - 0x254];
    float f320;
    float f324;
};

extern "C" {
extern float DAT_00381420;
extern float DAT_00381428;
extern float DAT_0038142c;
extern float DAT_00381438;
extern int DAT_0038145c;
extern int DAT_00381460;
int FUN_00137630(int);
void FUN_001339d4(Obj *);
void FUN_001354c4(Obj *, int, int, int);
float FUN_00022500(const Vec4 *, const Vec4 *);
float FUN_00022e6c(float);
Vec4 *FUN_0002245c(Vec4 *, const Vec4 *, const Vec4 *);
void FUN_000956c4(Obj *, float, int);
void FUN_00095b04(Obj *, int);
void FUN_0013671c(Obj *, int, int, float);
void FUN_001367cc(Obj *, int);
void FUN_00136840(Obj *, int);
}

inline float LengthSq(const Vec4 &v)
{
    return FUN_00022500(&v, &v);
}

inline float Length(const Vec4 &v)
{
    return FUN_00022e6c(LengthSq(v));
}

inline const float &Min(const float &a, const float &b)
{
    return b < a ? b : a;
}

extern "C" void FUN_00134de4(Obj *self)
{
    Vec4 diff, tmp;

    switch (self->mode) {
    case 0:
    case 4:
    case 5:
        if (FUN_00137630(3) != 0) {
            if (self->f220 != 0 || self->f221 != 0) {
                FUN_001339d4(self);
                FUN_001354c4(self, 11, -1, 0);
            }
        }
        if (FUN_00137630(1) != 0 && LengthSq(self->v160) >= DAT_0038142c * DAT_0038142c) {
            if (self->mode == 4) {
                FUN_001354c4(self, 5, -1, 0);
            }
        } else {
            if (self->mode == 5) {
                FUN_001354c4(self, 4, -1, 0);
            }
        }
        if (self->mode == 4) {
            float len = Length(self->v160);
            float rate = DAT_00381420 / self->f320;
            rate *= len;
            FUN_000956c4(self, Min(DAT_00381438, rate), -1);
            FUN_00095b04(self, -1);
        } else if (self->mode == 5) {
            float len = Length(self->v160);
            float rate = DAT_00381428 / self->f324;
            rate *= len;
            FUN_000956c4(self, Min(DAT_00381438, rate), -1);
            FUN_00095b04(self, -1);
        }
        break;
    case 11:
        if (self->f220 != 0) {
            FUN_001354c4(self, 0, -1, 0);
        } else if (FUN_00137630(3) != 0) {
            if (self->counter >= DAT_0038145c && self->counter <= DAT_0038145c + DAT_00381460) {
                FUN_001339d4(self);
            }
        }
        break;
    case 12:
        FUN_0002245c(&tmp, &self->v1c0, &self->v1b0);
        diff = tmp;
        if (LengthSq(diff) < 1e-5f) {
            FUN_0013671c(self, 1, 1, -1.0f);
        } else if (LengthSq(diff) < DAT_00381420 * DAT_00381420) {
            FUN_001367cc(self, 1);
            FUN_000956c4(self, Min(DAT_00381438, Length(diff) / self->f320), -1);
        } else {
            FUN_00136840(self, 1);
            FUN_000956c4(self, Min(DAT_00381438, Length(diff) / self->f324), -1);
        }
        FUN_00095b04(self, -1);
        break;
    }
    self->counter++;
}
