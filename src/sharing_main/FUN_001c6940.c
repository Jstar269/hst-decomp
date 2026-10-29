/* HSTMATCH module=hstp_trans_main.prx start=0x001c6940 end=0x001c69e4 symbol=FUN_001c6940 lang=c99 */
/* Clone of src/eboot/FUN_001b8c54.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003eaad8;
extern void FUN_00000a00();
extern int FUN_001c0454();
extern void FUN_001c6a18();
extern void FUN_001c71e4();

/* Destructor of an embedded list object; frees the storage when delete_flag > 0. */
int FUN_001c6940(int self,short delete_flag)
{
  u8 range_out [4];
  u32 range_end;
  int range_cursor;
  
  if (self != 0) {
    FUN_001c6a18();
    if ((((self != 0) && (FUN_001c0454((int)&DAT_003eaad8,0), self != 0)) && (self != 0)) &&
       (self != 0)) {
      range_cursor = self + 4;
      range_end = *(u32 *)(self + 8);
      FUN_001c71e4(range_out,self,&range_end,&range_cursor);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
