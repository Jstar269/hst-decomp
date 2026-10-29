/* HSTMATCH module=EBOOT.BIN start=0x002190e4 end=0x00219150 symbol=FUN_002190e4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vtable_obj.h"

extern char DAT_0030702c;
extern char DAT_003095d8;
extern void FUN_00000a00();
extern void * FUN_0005a410();

/* Deleting destructor of one particle. */
VtableObj * FUN_002190e4(VtableObj *particle,short flags)
{
  if (particle != (VtableObj *)0x0) {
    particle->vtable = &DAT_003095d8;
    if (particle != (VtableObj *)0x0) {
      particle->vtable = &DAT_0030702c;
      FUN_0005a410(particle,0);
    }
    if (0 < flags) {
      FUN_00000a00(particle);
    }
  }
  return particle;
}
