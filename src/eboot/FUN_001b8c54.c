/* HSTMATCH module=EBOOT.BIN start=0x001b8c54 end=0x001b8cf8 symbol=FUN_001b8c54 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034179c;
extern void FUN_00000a00();
extern int FUN_001b23c0();
extern void FUN_001b8d2c();
extern void FUN_001b94f8();

/* Destructor of an embedded list object; frees the storage when delete_flag > 0. */
int FUN_001b8c54(int self,short delete_flag)
{
  u8 range_out [4];
  u32 range_end;
  int range_cursor;
  
  if (self != 0) {
    FUN_001b8d2c();
    if ((((self != 0) && (FUN_001b23c0((int)&DAT_0034179c,0), self != 0)) && (self != 0)) &&
       (self != 0)) {
      range_cursor = self + 4;
      range_end = *(u32 *)(self + 8);
      FUN_001b94f8(range_out,self,&range_end,&range_cursor);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
