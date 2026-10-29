/* HSTMATCH module=EBOOT.BIN start=0x002a796c end=0x002a79fc symbol=FUN_002a796c lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py) corrected by hand: struct offsets +0x1668/+0x166c/+0x1670 on the receiver, signed global compare, and the global address computed before the two zero stores; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_panel_obj.h"

extern int DAT_00301c90;
extern int DAT_003415a8;
extern void FUN_002a734c();
extern void FUN_002a761c();
extern u32 FUN_002af274();

#define TARGET_UNKDC_INIT 0xc /* value stored into the target's unkdc */

void FUN_002a796c(ModePanel *self)
{
  char *addr;
  int local;
  int val;
  int *p;
  ModePanelTarget *target;

  addr = (char *)DAT_003415a8 + 0x87128;
  self->unk1668 = 0;
  self->unk166c = 0;
  local = FUN_002af274(addr);
  /* val = max(global, local) */
  p = (DAT_00301c90 < local) ? &local : &DAT_00301c90;
  val = *p;
  self->unk1670 = val;
  target = self->target;
  target->unkd8 = val;
  target->unkdc = TARGET_UNKDC_INIT;
  FUN_002a734c(self);
  FUN_002a761c(self);
}
