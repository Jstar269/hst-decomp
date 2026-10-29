/* HSTMATCH module=hstp_trans_main.prx start=0x001c68e8 end=0x001c6940 symbol=FUN_001c68e8 lang=c99 */
/* Clone of src/eboot/FUN_001b8bfc.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001c71e4();
extern u32 * FUN_001c73f4();

/* Constructs an embedded list object: clears it, sets the cleared flag and the initial state value 9. */
int FUN_001c68e8(int self)
{
  u32 range_out;
  int range_end;
  int range_cursor;
  
  FUN_001c73f4((u32 *)self);
  *(u8 *)(self + 0xc) = 0;
  range_cursor = self + 4;
  range_end = *(int *)(self + 8);
  FUN_001c71e4(&range_out,(int *)self,&range_end,&range_cursor);
  *(u32 *)(self + 0x10) = 9;
  return self;
}
