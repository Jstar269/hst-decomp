/* HSTMATCH module=EBOOT.BIN start=0x001ec518 end=0x001ec564 symbol=FUN_001ec518 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/overlay_obj.h"

extern void FUN_001e88c0();
extern void FUN_001eb960();

void FUN_001ec518(OverlayObj *self,int param_2)
{
  if (self->part_a != 0) {
    FUN_001eb960(self->part_a);
    FUN_001e88c0(*self->link,param_2);
  }
}
