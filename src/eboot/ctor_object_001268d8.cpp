/* HSTMATCH module=EBOOT.BIN start=0x001268d8 end=0x00126c2c symbol=FUN_001268d8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: the 0x22418 result is returned BY VALUE from an inline wrapper (`self->vec1d0 = Sub(a, b)`: retail's batched f3,f2,f1,f0 copy and the lui hoisting follow); the constant vectors and zero stores are plain per-field stores; names and types await human review. */
#include "hst/avatar_obj.h"

static inline AvatarVec4 Sub(float *a, float *b);
extern "C" {
extern float DAT_002bc410, DAT_002bc414, DAT_002bc418, DAT_002bc41c;
extern float DAT_002bc420, DAT_002bc424, DAT_002bc428, DAT_002bc42c;
extern float DAT_002bc430, DAT_002bc434, DAT_002bc438, DAT_002bc43c;
extern float DAT_002bc440, DAT_002bc444, DAT_002bc448, DAT_002bc44c;
extern float DAT_002da39c, DAT_002da3a4;
extern char DAT_00308050[];
extern char DAT_00308064[];
void FUN_00091830(void);
void FUN_00286790(void *p);
void FUN_00022418(AvatarVec4 *out, float *a, float *b);
void FUN_000d7d80(void *p);
void FUN_0012c2dc(void *p);
void FUN_00128138(void *p);
}

static inline AvatarVec4 Sub(float *a, float *b)
{
    AvatarVec4 r;
    FUN_00022418(&r, a, b);
    return r;
}

/* Avatar constructor: base constructors, then every field set to its starting value (ids are -1, flags 0). */
extern "C" Avatar *FUN_001268d8(Avatar *self)
{
    FUN_00091830();
    FUN_00286790(&self->vtbl2);
    self->vtbl = DAT_00308050;
    self->vtbl2 = DAT_00308064;
    self->unk150 = 0;
    self->unk154 = 0;
    self->unk160 = 0;
    self->unk164 = 0;
    self->unk168 = 0;
    self->unk16c = 0;
    self->vec170.x = DAT_002bc430;
    self->vec170.y = DAT_002bc434;
    self->vec170.z = DAT_002bc438;
    self->vec170.w = DAT_002bc43c;
    self->vec180.x = DAT_002bc410;
    self->vec180.y = DAT_002bc414;
    self->vec180.z = DAT_002bc418;
    self->vec180.w = DAT_002bc41c;
    self->unk190 = 14;
    self->unk194 = 14;
    self->unk198 = 0;
    self->unk1a0 = 0;
    self->unk1a4 = 0;
    self->unk1a8 = 0;
    self->unk1ac = 0;
    self->vec1b0.x = DAT_002bc440;
    self->vec1b0.y = DAT_002bc444;
    self->vec1b0.z = DAT_002bc448;
    self->vec1b0.w = DAT_002bc44c;
    self->vec1c0.x = DAT_002bc440;
    self->vec1c0.y = DAT_002bc444;
    self->vec1c0.z = DAT_002bc448;
    self->vec1c0.w = DAT_002bc44c;
    self->vec1d0 = Sub(&DAT_002bc440, &DAT_002bc430);
    self->unk1e0 = 0;
    self->unk1e4 = 0;
    self->unk1e8 = 0;
    float n3 = -DAT_002bc42c;
    float n2 = -DAT_002bc428;
    float n1 = -DAT_002bc424;
    self->vec1f0.x = -DAT_002bc420;
    self->vec1f0.y = n1;
    self->vec1f0.z = n2;
    self->vec1f0.w = n3;
    self->vec200.x = DAT_002bc430;
    self->vec200.y = DAT_002bc434;
    self->vec200.z = DAT_002bc438;
    self->vec200.w = DAT_002bc43c;
    self->vec210.x = DAT_002bc410;
    self->vec210.y = DAT_002bc414;
    self->vec210.z = DAT_002bc418;
    self->vec210.w = DAT_002bc41c;
    self->unk220 = 1;
    self->unk221 = 1;
    self->unk224 = 0;
    self->vec230.x = DAT_002bc440;
    self->vec230.y = DAT_002bc444;
    self->vec230.z = DAT_002bc448;
    self->vec230.w = DAT_002bc44c;
    n3 = -DAT_002bc42c;
    n2 = -DAT_002bc428;
    n1 = -DAT_002bc424;
    self->vec240.x = -DAT_002bc420;
    self->vec240.y = n1;
    self->vec240.z = n2;
    self->vec240.w = n3;
    self->unk250 = 0;
    self->unk254 = 0;
    FUN_000d7d80(self->parts258);
    self->unk320 = DAT_002da39c;
    self->unk324 = DAT_002da3a4;
    self->unk328 = 1.0f;
    self->unk32c = 0;
    self->unk32d = 0;
    self->unk330 = 0;
    self->unk334 = -1;
    self->unk338 = 0;
    self->unk339 = 0;
    self->unk33c = 0;
    self->unk340 = 0;
    self->unk344 = 0;
    self->unk348 = 0;
    self->unk34c = 0;
    self->unk350 = -1;
    self->unk354 = 0;
    self->unk358 = 0;
    self->unk35c = 0;
    self->unk360 = 0;
    FUN_0012c2dc(&self->parts370);
    self->unk410 = 1;
    self->unk414 = 0;
    self->unk418 = 0;
    self->unk41c = 0;
    self->unk364 = 0;
    self->unk365 = 0;
    self->unk366 = 0;
    self->unk367 = 0;
    self->unk368 = 0;
    self->unk369 = 0;
    FUN_00128138(self);
    return self;
}

