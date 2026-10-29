/* HSTMATCH module=EBOOT.BIN start=0x002ad8cc end=0x002ad938 symbol=FUN_002ad8cc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: expressed the three accepted values in retail test order with a switch; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034a678;
extern int FUN_0016bb88();
extern void FUN_002ad758();

/* Route 1 for modes 0x14, 0x47 and 0x48 (route 0 otherwise). */
void FUN_002ad8cc(void)
{
  u32 table;
  int route;
  
  route = 0;
  switch (DAT_0034a678) {
  case 0x14:
  case 0x47:
  case 0x48:
    route = 1;
    break;
  default:
    break;
  }
  table = FUN_0016bb88();
  FUN_002ad758(route,table,0);
}
