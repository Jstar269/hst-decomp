/* HSTMATCH module=hstp_trans_main.prx start=0x00123d20 end=0x00123d60 symbol=FUN_00123d20 lang=c99 */
/* Clone of src/eboot/FUN_00118b4c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int * FUN_00123d60();
extern u32 FUN_00123e94();

/* Copy-constructs the container from another (the allocator argument is unused). */
u32 FUN_00123d20(u32 self,u32 allocator,u32 other)
{
  FUN_00123e94(self);
  FUN_00123d60(self,other);
  return self;
}
