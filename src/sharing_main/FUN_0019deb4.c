/* HSTMATCH module=hstp_trans_main.prx start=0x0019deb4 end=0x0019def4 symbol=FUN_0019deb4 lang=c99 */
/* Clone of src/eboot/FUN_00118b4c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int * FUN_0019def4();
extern u32 FUN_0019e028();

/* Copy-constructs the container from another (the allocator argument is unused). */
u32 FUN_0019deb4(u32 self,u32 allocator,u32 other)
{
  FUN_0019e028(self);
  FUN_0019def4(self,other);
  return self;
}
