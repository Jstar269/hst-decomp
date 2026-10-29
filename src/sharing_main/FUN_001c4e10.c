/* HSTMATCH module=hstp_trans_main.prx start=0x001c4e10 end=0x001c4e84 symbol=FUN_001c4e10 lang=c99 */
/* Clone of src/eboot/FUN_001b7150.c (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/inst_obj.h"

extern u8 DAT_003eaad8;
extern void FUN_001c1a30();
extern void FUN_001c71e4();

/* Empties both lists of the object (erase from the first element to the sentinel), then calls FUN_001c1a30. */
void FUN_001c4e10(InstObj *self)
{
  u32 ret_a;
  DListLinks *first_a;
  DListLinks *last_a;
  u32 ret_b;
  DListLinks *first_b;
  DListLinks *last_b;
  
  last_a = &self->listf0.sentinel;
  first_a = self->listf0.sentinel.next;
  FUN_001c71e4(&ret_a,&self->listf0,&first_a,&last_a);
  last_b = &self->list3c.sentinel;
  first_b = self->list3c.sentinel.next;
  FUN_001c71e4(&ret_b,&self->list3c,&first_b,&last_b);
  FUN_001c1a30((int *)&DAT_003eaad8);
}
