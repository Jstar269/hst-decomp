/* HSTMATCH module=hstp_trans_main.prx start=0x001c6940 end=0x001c69e4 symbol=FUN_001c6940 lang=c99 */
/* Clone of src/eboot/FUN_001b8c54.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003eaad8;
extern void FUN_00000a00();
extern int FUN_001c0454();
extern void FUN_001c6a18();
extern void FUN_001c71e4();

int FUN_001c6940(int param_1,short param_2)
{
  u8 auStack_4 [4];
  u32 local_8;
  int local_c;
  
  if (param_1 != 0) {
    FUN_001c6a18();
    if ((((param_1 != 0) && (FUN_001c0454((int)&DAT_003eaad8,0), param_1 != 0)) && (param_1 != 0)) &&
       (param_1 != 0)) {
      local_c = param_1 + 4;
      local_8 = *(u32 *)(param_1 + 8);
      FUN_001c71e4(auStack_4,param_1,&local_8,&local_c);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
