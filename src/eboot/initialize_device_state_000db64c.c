/* HSTMATCH module=EBOOT.BIN start=0x000db64c end=0x000db724 symbol=FUN_000db64c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: model byte +0x45 as a field and route the zero flag to the common initializer call. */
#include "hst/types.h"
#include "hst/rule_obj.h"

extern u8 DAT_003075f8;
extern u8 DAT_003386b8;
extern u8 * DAT_00338ac4;
extern RuleObj * DAT_00338b44; /* the live rule object (set by the constructor, cleared by the destructor) */
extern unsigned char DAT_00338b48;
extern u8 DAT_003417b8; /* match settings: doubles flag, sets, games per set */
extern u8 DAT_003417b9;
extern unsigned char DAT_003417ba;
extern u32 * FUN_0001f06c();
extern void FUN_000db788();

/* Rule object constructor. */
RuleObj * FUN_000db64c(RuleObj *self)
{
  FUN_0001f06c(self);
  self->vtable = &DAT_003075f8;
  self->unk3c = 5;
  self->unk40 = 0;
  self->active = 0;
  self->doubles = 1;
  self->numSets = 3;
  self->gamesPerSet = 2;
  self->pointsPerGame = 4;
  DAT_00338b48 = 0;
  self->doubles = DAT_003417b8 == '\0';
  self->numSets = (u32)DAT_003417b9;
  self->gamesPerSet = (u32)DAT_003417ba;
  if ((DAT_003386b8 != '\0') && (2 < *(int *)(DAT_00338ac4 + 0x194))) {
    self->doubles = 0;
  }
  FUN_000db788(self);
  DAT_00338b44 = self;
  return self;
}
