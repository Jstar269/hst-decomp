/* HSTMATCH module=EBOOT.BIN start=0x00129b74 end=0x00129f94 symbol=FUN_00129b74 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: the dot product is an inline LengthSq() (a direct FUN_000224d8 call inside the compare loads the threshold global before the call and keeps it in $f20), the walk/run rate is `rate = K / f; rate *= len;` (one expression puts the length first in mul.s), the mode cases are written 0/4/5, 11, 12 (retail tests them in reverse); names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Obj {
    char pad000[0x160];
    Vec4 v160;
    char pad170[0x190 - 0x170];
    int mode;
    char pad194[0x1b0 - 0x194];
    Vec4 pos;
    Vec4 prev_pos;
    char pad1d0[0x220 - 0x1d0];
    unsigned char flag220;
    unsigned char flag221;
    char pad222[0x250 - 0x222];
    int counter;
    char pad254[0x320 - 0x254];
    float walk_speed;
    float run_speed;
};

extern "C" {
extern float DAT_002da3a0;
extern float DAT_002da3a8;
extern float DAT_002da3ac;
extern float DAT_002da3b8;
extern int DAT_002da3dc;
extern int DAT_002da3e0;
int FUN_0012c1c4(int);
void FUN_00128764(Obj *);
void FUN_0012a254(Obj *, int, int, int);
float FUN_000224d8(const Vec4 *, const Vec4 *);
float FUN_00022e44(float);
Vec4 *FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
void FUN_000937a0(Obj *, float, int);
void FUN_00093be0(Obj *, int);
void FUN_0012b2b0(Obj *, int, int, float);
void FUN_0012b360(Obj *, int);
void FUN_0012b3d4(Obj *, int);
}

inline float LengthSq(const Vec4 &v)
{
    return FUN_000224d8(&v, &v);
}

inline float Length(const Vec4 &v)
{
    return FUN_00022e44(LengthSq(v));
}

inline const float &Min(const float &a, const float &b)
{
    return b < a ? b : a;
}

/* Per-frame update of the avatar movement mode: starts/stops walk and run by input length, drives the animation rate, steps the mode counter. */
extern "C" void FUN_00129b74(Obj *self)
{
    Vec4 diff, tmp;

    switch (self->mode) {
    case 0:
    case 4:
    case 5:
        if (FUN_0012c1c4(3) != 0) {
            if (self->flag220 != 0 || self->flag221 != 0) {
                FUN_00128764(self);
                FUN_0012a254(self, 11, -1, 0);
            }
        }
        if (FUN_0012c1c4(1) != 0 && LengthSq(self->v160) >= DAT_002da3ac * DAT_002da3ac) {
            if (self->mode == 4) {
                FUN_0012a254(self, 5, -1, 0);
            }
        } else {
            if (self->mode == 5) {
                FUN_0012a254(self, 4, -1, 0);
            }
        }
        if (self->mode == 4) {
            float len = Length(self->v160);
            float rate = DAT_002da3a0 / self->walk_speed;
            rate *= len;
            FUN_000937a0(self, Min(DAT_002da3b8, rate), -1);
            FUN_00093be0(self, -1);
        } else if (self->mode == 5) {
            float len = Length(self->v160);
            float rate = DAT_002da3a8 / self->run_speed;
            rate *= len;
            FUN_000937a0(self, Min(DAT_002da3b8, rate), -1);
            FUN_00093be0(self, -1);
        }
        break;
    case 11:
        if (self->flag220 != 0) {
            FUN_0012a254(self, 0, -1, 0);
        } else if (FUN_0012c1c4(3) != 0) {
            if (self->counter >= DAT_002da3dc && self->counter <= DAT_002da3dc + DAT_002da3e0) {
                FUN_00128764(self);
            }
        }
        break;
    case 12:
        FUN_00022434(&tmp, &self->prev_pos, &self->pos);
        diff = tmp;
        if (LengthSq(diff) < 1e-5f) {
            FUN_0012b2b0(self, 1, 1, -1.0f);
        } else if (LengthSq(diff) < DAT_002da3a0 * DAT_002da3a0) {
            FUN_0012b360(self, 1);
            FUN_000937a0(self, Min(DAT_002da3b8, Length(diff) / self->walk_speed), -1);
        } else {
            FUN_0012b3d4(self, 1);
            FUN_000937a0(self, Min(DAT_002da3b8, Length(diff) / self->run_speed), -1);
        }
        FUN_00093be0(self, -1);
        break;
    }
    self->counter++;
}
