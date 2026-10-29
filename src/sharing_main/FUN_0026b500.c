/* HSTMATCH module=hstp_trans_main.prx start=0x0026b500 end=0x0026b540 symbol=FUN_0026b500 lang=c99 */
/* Clone of src/eboot/FUN_00118b4c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int * FUN_0026b540();
extern u32 FUN_0026b674();

/* Copy-constructs the container from another (the allocator argument is unused). */
u32 FUN_0026b500(u32 self,u32 allocator,u32 other)
{
  FUN_0026b674(self);
  FUN_0026b540(self,other);
  return self;
}
