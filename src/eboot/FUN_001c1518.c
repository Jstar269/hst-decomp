/* HSTMATCH module=EBOOT.BIN start=0x001c1518 end=0x001c159c symbol=FUN_001c1518 lang=c99 rodata=0x002c6340 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/record_table.h"

/* Look up one of the 16-bit values by selector; unknown selectors give 0. */
u16 FUN_001c1518(RecordTable *self,u32 selector)
{
  u16 value;
  
  switch(selector) {
  case 0:
    value = self->unk8416;
    break;
  case 1:
    value = self->unk8418;
    break;
  case 2:
    value = self->unk841a;
    break;
  case 3:
  case 4:
    value = self->unk841c;
    break;
  case 5:
    value = self->unk841e;
    break;
  default:
    value = 0;
  }
  return value;
}
