/* HSTMATCH module=hstp_trans_main.prx start=0x001bd3ac end=0x001bd448 symbol=FUN_001bd3ac lang=c99 */
/* Clone of src/eboot/FUN_001afcd4.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: the do-while rewritten as a for loop with an inclusive bound (i <= 0x179); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0038d214;
extern u8 DAT_0038d21c;
extern u8 DAT_0038d224;
extern u8 DAT_0038d238;
extern void FUN_001bde64();
extern void FUN_001be2d4();

void FUN_001bd3ac(int param_1)
{
  int iVar1;
  
  for (iVar1 = 0x16a; iVar1 <= 0x179; iVar1++) {
    FUN_001bde64(param_1,iVar1);
  }
  *(u32 *)(param_1 + 0x788) = 0;
  FUN_001be2d4(param_1,&DAT_0038d238,4);
  FUN_001be2d4(param_1,&DAT_0038d224,5);
  FUN_001be2d4(param_1,&DAT_0038d21c,2);
  FUN_001be2d4(param_1,&DAT_0038d214,2);
}
