/* HSTMATCH module=EBOOT.BIN start=0x00219150 end=0x00219184 symbol=FUN_00219150 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vtable_obj.h"

extern char DAT_003095d8;
extern void * FUN_0005a8ec();

/* Particle constructor: base init, then the particle vtable. */
VtableObj * FUN_00219150(VtableObj *particle)
{
  FUN_0005a8ec();
  particle->vtable = &DAT_003095d8;
  return particle;
}
