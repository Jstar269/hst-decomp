/* HSTMATCH module=hstp_trans_main.prx start=0x00123fb4 end=0x00123ff4 symbol=FUN_00123fb4 lang=c99 */
/* Clone of src/eboot/FUN_00118b4c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int * FUN_00123ff4();
extern u32 FUN_00124128();

/* Copy-constructs the container from another (the allocator argument is unused). */
u32 FUN_00123fb4(u32 self,u32 allocator,u32 other)
{
  FUN_00124128(self);
  FUN_00123ff4(self,other);
  return self;
}
