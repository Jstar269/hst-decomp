/* HSTMATCH module=EBOOT.BIN start=0x00127870 end=0x00127a20 symbol=FUN_00127870 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q2) corrected by hand: the return type is int, not bool (no 0xff mask in retail); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/motion_obj.h"

extern int DAT_0033b4f0[ID_TABLE_COUNT];

/* True when id is none of the ids in the global id table. */
int FUN_00127870(int id)
{
  return ((((((((((((((((id != DAT_0033b4f0[0] && id != DAT_0033b4f0[1]) &&
                       id != DAT_0033b4f0[2]) && id != DAT_0033b4f0[3]) &&
                     id != DAT_0033b4f0[4]) && id != DAT_0033b4f0[5]) &&
                   id != DAT_0033b4f0[6]) && id != DAT_0033b4f0[7]) &&
                 id != DAT_0033b4f0[8]) && id != DAT_0033b4f0[9]) && id != DAT_0033b4f0[10])
              && id != DAT_0033b4f0[11]) && id != DAT_0033b4f0[12]) && id != DAT_0033b4f0[13])
           && id != DAT_0033b4f0[14]) && id != DAT_0033b4f0[15]) && id != DAT_0033b4f0[16]) &&
         id != DAT_0033b4f0[17];
}
