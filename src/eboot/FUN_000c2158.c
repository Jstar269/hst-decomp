/* HSTMATCH module=EBOOT.BIN start=0x000c2158 end=0x000c24a8 symbol=FUN_000c2158 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/body_obj.h"

extern u32 DAT_00307424;  /* vtable */
extern float DAT_002bc410;
extern float DAT_002bc414;
extern float DAT_002bc418;
extern float DAT_002bc41c;
extern float DAT_002bc420;
extern float DAT_002bc424;
extern float DAT_002bc428;
extern float DAT_002bc42c;
extern float DAT_002bc430;
extern float DAT_002bc434;
extern float DAT_002bc438;
extern float DAT_002bc43c;
extern float DAT_002bc440;
extern float DAT_002bc444;
extern float DAT_002bc448;
extern float DAT_002bc44c;

/* Constructor: zero the vectors, copy the constant block into the three float blocks. */
BodyObj *FUN_000c2158(BodyObj *self)
{
  self->vtbl = &DAT_00307424;
  self->unk04 = 3;
  self->vec10.x = 0;
  self->vec10.y = 0;
  self->vec10.z = 0;
  self->vec10.w = 1.0f;
  self->vec20.x = 0;
  self->vec20.y = 0;
  self->vec20.z = 0;
  self->vec20.w = 0;
  self->vec30.x = 0;
  self->vec30.y = 0;
  self->vec30.z = 0;
  self->vec30.w = 1.0f;
  self->vec40.x = 0;
  self->vec40.y = 0;
  self->vec40.z = 0;
  self->vec40.w = 0;
  self->block50[0] = DAT_002bc410;
  self->block50[1] = DAT_002bc414;
  self->block50[2] = DAT_002bc418;
  self->block50[3] = DAT_002bc41c;
  self->block50[4] = DAT_002bc420;
  self->block50[5] = DAT_002bc424;
  self->block50[6] = DAT_002bc428;
  self->block50[7] = DAT_002bc42c;
  self->block50[8] = DAT_002bc430;
  self->block50[9] = DAT_002bc434;
  self->block50[10] = DAT_002bc438;
  self->block50[11] = DAT_002bc43c;
  self->block50[12] = DAT_002bc440;
  self->block50[13] = DAT_002bc444;
  self->block50[14] = DAT_002bc448;
  self->block50[15] = DAT_002bc44c;
  self->block90[0] = DAT_002bc410;
  self->block90[1] = DAT_002bc414;
  self->block90[2] = DAT_002bc418;
  self->block90[3] = DAT_002bc41c;
  self->block90[4] = DAT_002bc420;
  self->block90[5] = DAT_002bc424;
  self->block90[6] = DAT_002bc428;
  self->block90[7] = DAT_002bc42c;
  self->block90[8] = DAT_002bc430;
  self->block90[9] = DAT_002bc434;
  self->block90[10] = DAT_002bc438;
  self->block90[11] = DAT_002bc43c;
  self->block90[12] = DAT_002bc440;
  self->block90[13] = DAT_002bc444;
  self->block90[14] = DAT_002bc448;
  self->block90[15] = DAT_002bc44c;
  self->blockd0[0] = DAT_002bc410;
  self->blockd0[1] = DAT_002bc414;
  self->blockd0[2] = DAT_002bc418;
  self->blockd0[3] = DAT_002bc41c;
  self->blockd0[4] = DAT_002bc420;
  self->blockd0[5] = DAT_002bc424;
  self->blockd0[6] = DAT_002bc428;
  self->blockd0[7] = DAT_002bc42c;
  self->blockd0[8] = DAT_002bc430;
  self->blockd0[9] = DAT_002bc434;
  self->blockd0[10] = DAT_002bc438;
  self->blockd0[11] = DAT_002bc43c;
  self->blockd0[12] = DAT_002bc440;
  self->blockd0[13] = DAT_002bc444;
  self->blockd0[14] = DAT_002bc448;
  self->blockd0[15] = DAT_002bc44c;
  self->unk134 = 1;
  self->unk170 = 0x7f7fffff;
  self->unk174 = 0;
  self->unk17c = 0;
  self->unk180 = 0;
  self->unk1d0 = 0;
  self->counter = 0;
  self->unk110 = 0x3d05f06f;
  self->unk114 = 0x3d656042;
  self->unk11c = 0x411ccccd;
  self->unk120 = 0;
  self->unk124 = 0;
  self->unk128 = 0;
  self->unk12c = 0;
  self->unk12c = 0;
  return self;
}
