/* HSTMATCH module=EBOOT.BIN start=0x001b8da8 end=0x001b8e6c symbol=FUN_001b8da8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a3) corrected by hand: restored the dropped delete argument (FUN_00000a00(param_1)) and passed &DAT_0034179c (lui/addiu) instead of the numeric address; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003092c0;
extern u8 DAT_0034179c;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern void FUN_001b23c0();
extern void FUN_001b3640();
extern void FUN_001b94f8();

/* Scalar-deleting destructor: tears down the object and its embedded list, frees it when count > 0. */
u32 * FUN_001b8da8(u32 *self,short delete_flag)
{
  int *list;
  u32 range_out;
  int range_end;
  u32 *range_cursor;
  
  if (self != (u32 *)0x0) {
    *self = (unsigned int)(&DAT_003092c0);
    FUN_001b3640((int *)&DAT_0034179c);
    if ((char *)self + 0x3c != (char *)0) {
      FUN_001b23c0(&DAT_0034179c,0);
      list = (int *)(self + 0xf);
      if (((list != (int *)0x0) && (list != (int *)0x0)) && (list != (int *)0x0)) {
        range_cursor = self + 0x10;
        range_end = self[0x11];
        FUN_001b94f8(&range_out,list,&range_end,&range_cursor);
      }
    }
    FUN_0001f0f0(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
