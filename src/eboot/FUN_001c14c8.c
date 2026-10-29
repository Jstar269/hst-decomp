/* HSTMATCH module=EBOOT.BIN start=0x001c14c8 end=0x001c1518 symbol=FUN_001c14c8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/record_table.h"

extern void FUN_001beffc();
extern void FUN_001c1344();

/* Reset the base part, refill the records and clear the byte pairs. */
void FUN_001c14c8(RecordTable *self)
{
  int i;
  RecordTable *cur = self;
  
  FUN_001beffc(cur->handle);
  self->unk410 = 0;
  FUN_001c1344(self);
  i = 0;
  do {
    cur->pair[0][0] = 0;
    i = i + 1;
    cur->pair[0][1] = 0;
    cur = (RecordTable *)((char *)cur + 2);
  } while (i < 2);
}
