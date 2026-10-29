/* HSTMATCH module=EBOOT.BIN start=0x001b7b40 end=0x001b7e24 symbol=FUN_001b7b40 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: plain C (a C++ `int b = !F()` gets an extra andi); the member loads are written twice in `target->unk4 != 0 && target->unk4 != 0` (a named local folds the pair); the clamp bounds are passed by POINTER (`Clamp(t, &DAT_a, &DAT_b)`, inline, bounds dereferenced twice: repeated lui + double load); `FUN_001b210c(&DAT, &self->unk68, x, x)` takes the pointers first; `v.y > K` gives c.ngt.s; Vec4 copied field by field. */
#include "hst/inst_obj.h"

typedef struct Vec4 { float x, y, z, w; } Vec4;
typedef struct Cfg { char pad[0x120]; int unk120; } Cfg;

extern int DAT_0034179c;
extern Cfg *DAT_00340284;
extern float DAT_002e995c;
extern float DAT_002e9a3c, DAT_002e9a40, DAT_002e9a44, DAT_002e9a48, DAT_002e9a4c, DAT_002e9a50;
extern float DAT_002e9a54, DAT_002e9a58, DAT_002e9a5c, DAT_002e9a60, DAT_002e9a64, DAT_002e9a68;
extern float DAT_003417a0;

int FUN_001b1f7c(int *, int);
void FUN_001b871c(InstObj *);
void FUN_001b2218(int *, int *, Vec4 *, int, int);
void FUN_001b210c(int *, int *, float, float);
void FUN_001b21cc(float, int *, int *);

static inline float Clamp(float v, const float *lo, const float *hi)
{
    return v < *lo ? *lo : (v > *hi ? *hi : v);
}

void FUN_001b7b40(InstObj *self)
{
    if (self->target != 0) {
        int finish = 1;
        int decided = !FUN_001b1f7c(&DAT_0034179c, self->unk68);
        if (!decided) {
            decided = !(DAT_00340284->unk120 < 0);
        }
        if (!decided) {
            int active = self->target->unk4 != 0 && self->target->unk4 != 0;
            if (!active) {
                finish = 0;
            }
        }
        if (finish) {
            FUN_001b871c(self);
        } else {
            Vec4 v;
            v.x = self->target->vec[0]; v.y = self->target->vec[1]; v.z = self->target->vec[2]; v.w = self->target->vec[3];
            FUN_001b2218(&DAT_0034179c, &self->unk68, &v, 0, 0);
            if (self->ramp_mode != 0) {
                float blend_a, blend_b;
                if (v.y > DAT_002e9a40) {
                    float t = (v.y - DAT_002e9a3c) / (DAT_002e9a40 - DAT_002e9a3c);
                    float k = Clamp(t, &DAT_002e9a5c, &DAT_002e9a60);
                    blend_a = DAT_002e9a48 + k * (DAT_002e9a4c - DAT_002e9a48);
                    blend_b = DAT_002e9a54 + k * (DAT_002e9a58 - DAT_002e9a54);
                } else {
                    float t = (v.y - DAT_002e9a40) / (DAT_002e9a44 - DAT_002e9a40);
                    float k = Clamp(t, &DAT_002e9a64, &DAT_002e9a68);
                    blend_a = DAT_002e9a4c + k * (DAT_002e9a50 - DAT_002e9a4c);
                    blend_b = DAT_002e9a58 + k * (DAT_003417a0 - DAT_002e9a58);
                }
                FUN_001b21cc(blend_a, &DAT_0034179c, &self->unk68);
                FUN_001b210c(&DAT_0034179c, &self->unk68, blend_b, blend_b);
            
            } else {
                if (self->unk71 == 0 && 0 < self->countdown) {
                    float f = (float)self->countdown / DAT_002e995c;
                    if (f > 0.0f) {
                        FUN_001b210c(&DAT_0034179c, &self->unk68, f, f);
                    }
                    self->countdown = self->countdown - 1;
                    if (self->countdown < 1) {
                        FUN_001b871c(self);
                    }
                }
            }
        }
    }
}
