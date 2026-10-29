/* HSTMATCH module=EBOOT.BIN start=0x001b7150 end=0x001b71c4 symbol=FUN_001b7150 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/inst_obj.h"

extern u8 DAT_0034179c;
extern void FUN_001b3648();
extern void FUN_001b94f8();

/* Empties both lists of the object (erase from the first element to the sentinel), then calls FUN_001b3648. */
void FUN_001b7150(InstObj *self)
{
  u32 ret_a;
  DListLinks *first_a;
  DListLinks *last_a;
  u32 ret_b;
  DListLinks *first_b;
  DListLinks *last_b;
  
  last_a = &self->listf0.sentinel;
  first_a = self->listf0.sentinel.next;
  FUN_001b94f8(&ret_a,&self->listf0,&first_a,&last_a);
  last_b = &self->list3c.sentinel;
  first_b = self->list3c.sentinel.next;
  FUN_001b94f8(&ret_b,&self->list3c,&first_b,&last_b);
  FUN_001b3648((int *)&DAT_0034179c);
}
