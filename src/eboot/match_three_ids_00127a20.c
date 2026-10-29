/* HSTMATCH module=EBOOT.BIN start=0x00127a20 end=0x00127a68 symbol=FUN_00127a20 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py) corrected by hand: OR chain written as an assignment chain (`if (!b) b = ...; return b;`) to get the xor/sltiu/bnez short-circuit; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/motion_obj.h"

extern u32 DAT_0033b4f0[ID_TABLE_COUNT];

/* True when id is one of three entries (14, 15 and 17) of the global id table. */
int FUN_00127a20(int id)
{
  int found;
  found = id == DAT_0033b4f0[14];
  if (!found) found = id == DAT_0033b4f0[15];
  if (!found) found = id == DAT_0033b4f0[17];
  return found;
}
