/* HSTMATCH module=EBOOT.BIN start=0x001c2250 end=0x001c2370 symbol=FUN_001c2250 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/menu_state.h"

extern u8 DAT_0030933c;
extern u32 * FUN_000114c0();
extern u32 * FUN_001cd810();
extern u32 * FUN_002291cc();

/* MenuState constructor: base init, then every field reset (ids are -1, flags 0). */
MenuState * FUN_001c2250(MenuState *self,void *parent)
{
  FUN_001cd810(self);
  self->vtbl = &DAT_0030933c;
  self->parent = parent;
  self->src = 0;
  self->unk20 = 0;
  self->unk24 = 0;
  self->unk28 = 0;
  self->unk2c = 0;
  self->unk30 = 0;
  FUN_002291cc(self->sub34);
  self->unk54 = 0;
  self->unk58 = 0;
  self->unk5c = 0;
  self->unk60 = 0;
  self->unk61 = 0;
  self->unk62 = 1;
  self->unk63 = 0;
  self->unk64 = 0;
  self->unk65 = 0;
  self->unk68 = 0;
  self->unk6c = -1;
  self->unk70 = 0;
  self->unk74 = -1;
  self->unk78 = -1;
  self->unk90 = 0;
  self->unk91 = 0;
  self->unk94 = 0;
  FUN_000114c0(self->unk98,0,0x10);
  self->unka8 = 0;
  self->unkac = 0;
  self->unkb0 = 0;
  self->triggered = 0;
  self->nextState = 0;
  self->effectId = -1;
  self->unkbc = -1;
  self->triggerTime = -1;
  self->effectPos.x = 0;
  self->effectPos.y = 0;
  self->effectPos.z = 0;
  self->effectPos.w = 0;
  self->unke0 = 0;
  self->unke4 = 0;
  self->unke8 = 0;
  self->unkec = 0;
  self->unkf0 = 0;
  self->unkf1 = 0;
  self->unkf4 = 0;
  self->unkf8 = 0;
  self->unkfc = 0;
  self->unk100 = 0;
  self->unk104 = 0;
  return self;
}
