/* HSTMATCH module=hstp_trans_main.prx start=0x001cf72c end=0x001cf7b0 symbol=FUN_001cf72c lang=c99 rodata=0x002d6850 */
/* Clone of src/eboot/FUN_001c1518.c (hstclone.py tag ds1011s2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/record_table.h"

/* Look up one of the 16-bit values by selector; unknown selectors give 0. */
u16 FUN_001cf72c(RecordTable *self,u32 selector)
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
