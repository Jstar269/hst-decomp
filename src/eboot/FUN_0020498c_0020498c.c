/* HSTMATCH module=EBOOT.BIN start=0x0020498c end=0x00204ac8 symbol=FUN_0020498c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: shared the allocation and table store across the null path and used a zeroed four-word local array; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/chrsel_unit.h"

#define SHARED_OBJECT_SIZE 0xe0 /* size of one shared object */

extern u8 DAT_002bc410;
extern void *DAT_0034b340[]; /* shared object per kind, created on first use */
extern int FUN_00000bcc();
extern u32 * FUN_00091830(void *);
extern void FUN_00093434();
extern void FUN_0009345c();
extern void FUN_00093484(float param_1,int param_2);

/* Unit constructor: attaches the shared object of the given kind (creating it the first time), resets its
   transform and clears the unit's own state. */
ChrSelUnit * FUN_0020498c(ChrSelUnit *self,int kind,u8 flag)
{
  u32 *shared;
  u32 local_values[4];
  
  self->unk0c = 0;
  self->unk10 = 0;
  self->unk14 = 0;
  self->unk20 = 0;
  self->unk24 = 0;
  self->unk28 = 0;
  self->unk2c = 0;
  self->unk30 = 0;
  self->unk34 = 0;
  self->unk38 = 0;
  self->unk3c = 0;
  self->unk08 = flag;
  self->unk09 = 0;
  self->kind = kind;
  if (DAT_0034b340[kind] == 0) {
    shared = (u32 *)FUN_00000bcc(SHARED_OBJECT_SIZE);
    if (shared != (u32 *)0x0) {
      shared = FUN_00091830(shared);
    }
    DAT_0034b340[self->kind] = shared;
  }
  self->handle = DAT_0034b340[self->kind];
  local_values[0] = 0;
  local_values[1] = 0;
  local_values[2] = 0;
  local_values[3] = 0;
  FUN_0009345c(self->handle,local_values);
  FUN_00093484(1.0f,(int)self->handle);
  FUN_00093434(self->handle,&DAT_002bc410);
  self->unk44 = 0;
  self->unk48 = 0;
  self->unk4c = 0;
  self->unk50 = 0;
  self->unk40 = 1.0f;
  self->unk20 = 0;
  self->unk24 = 0;
  self->unk28 = 0;
  self->unk2c = 1.0f;
  self->unk6c = 0;
  self->flag = 0;
  self->unk75 = 0;
  self->unk76 = 0;
  self->unk77 = 0;
  self->unk78 = 0;
  return self;
}
