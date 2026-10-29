/* HSTMATCH module=EBOOT.BIN start=0x00118ae4 end=0x00118b4c symbol=FUN_00118ae4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p1) corrected by hand: readability pass (names, structs, constants), earlier refined by hstperm.py random mutation (perm-p1/r00/f0276_00118ae4_m00.c); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/deque_owner.h"

extern int FUN_001183cc();
extern u32 FUN_00118b4c();
extern u32 * FUN_00118cc8();
extern u32 FUN_00118ce0();

/* Container base constructor taking an allocator: copies via a temporary, then zeroes the two tail words. */
DequeBox * FUN_00118ae4(DequeBox *self,u32 other)
{
  u32 alloc;
  u8 allocTmp [4];
  u8 temp [16];
  
  alloc = FUN_00118ce0(allocTmp);
  FUN_00118cc8(temp,alloc);
  FUN_00118b4c(self,other,temp);
  FUN_001183cc(temp,0xffffffff);
  self->unk10 = 0;
  self->unk14 = 0;
  return self;
}
