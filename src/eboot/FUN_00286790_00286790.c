/* HSTMATCH module=EBOOT.BIN start=0x00286790 end=0x0028686c symbol=FUN_00286790 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: typed the four global values and destination fields as float; readability pass; exact match verified; names and types await human review. */
#include "hst/cmd_actor.h"

extern float DAT_002bc430;
extern float DAT_002bc434;
extern float DAT_002bc438;
extern float DAT_002bc43c;
extern unsigned char DAT_00309cac;
extern void FUN_00286d08(CmdActor *);
extern void *FUN_00289654(char *);

/* CmdActor constructor. */
CmdActor * FUN_00286790(CmdActor *self)
{
  self->vtbl = &DAT_00309cac;
  self->res = 0;
  self->objA = 0;
  self->objB = 0;
  self->name = 0;
  self->pos.x = DAT_002bc430;
  self->pos.y = DAT_002bc434;
  self->pos.z = DAT_002bc438;
  self->pos.w = DAT_002bc43c;
  self->unk30 = 0;
  self->unk34 = 0;
  self->unk38 = 0;
  self->unk3c = -1;
  self->unk40 = -1;
  self->unk4c = -1;
  self->unk50 = 1.5f;
  self->unk54 = 1;
  self->enabled = 0;
  self->unk56 = 0;
  self->unk57 = 1;
  self->unk58 = 0;
  self->unk59 = 0;
  self->unk5a = 0;
  self->unk5b = 0;
  self->unk5c = 0;
  self->unk60 = 0;
  FUN_00289654(self->alloc64);
  FUN_00286d08(self);
  self->unk44 = 1.0f;
  self->unk48 = 1.0f;
  return self;
}
