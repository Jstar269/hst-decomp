/* HSTMATCH module=EBOOT.BIN start=0x00118d78 end=0x00118de0 symbol=FUN_00118d78 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p1) corrected by hand: readability pass (names, structs, constants), earlier refined by hstperm.py random mutation (perm-p1/r00/f0277_00118d78_m02.c); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/deque_owner.h"

extern int FUN_00118494();
extern u32 FUN_00118de0();
extern u32 * FUN_00118f5c();
extern u32 FUN_00118f74();

/* Container base constructor taking an allocator: copies via a temporary, then zeroes the two tail words. */
DequeBox * FUN_00118d78(DequeBox *self,u32 other)
{
  u32 alloc;
  u8 allocTmp [4];
  u8 temp [16];
  
  alloc = FUN_00118f74(allocTmp);
  FUN_00118f5c(temp,alloc);
  FUN_00118de0(self,other,temp);
  FUN_00118494(temp,0xffffffff);
  self->unk10 = 0;
  self->unk14 = 0;
  return self;
}
