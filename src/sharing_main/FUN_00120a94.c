/* HSTMATCH module=hstp_trans_main.prx start=0x00120a94 end=0x00120ac8 symbol=FUN_00120a94 lang=c99 */
/* Clone of src/eboot/FUN_00115b78.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001079b4();

typedef struct Obj_00115b78 {
  char pad00[0x908];
  u16 unk908; /* 0x908 */
} Obj_00115b78;

/* Runs the base action, then stores the 16-bit value. */
void FUN_00120a94(Obj_00115b78 *self,u16 value)
{
  FUN_001079b4();
  self->unk908 = value;
}
