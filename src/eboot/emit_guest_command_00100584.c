/* HSTMATCH module=EBOOT.BIN start=0x00100584 end=0x00100614 symbol=FUN_00100584 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: preserved the narrowed flag and typed row indexing; exact match verified; names and types await human review. */
#include "hst/types.h"
typedef struct Row8 { char bytes[8]; } Row8;

extern void FUN_00051478();

void FUN_00100584(int param_1,int param_2)
{
  int sVar1;
  int sVar2;
  int iVar3;
  u8 uVar0;
  
  if ((*(u16 *)(param_2 + 0xe) & 0x600) != 0) {
    uVar0 = ((*(u16 *)(param_2 + 0xe) & 0x200) != 0) ^ 1;
    iVar3 = uVar0 * 8;
    iVar3 += param_1;
    sVar1 = *(short *)(iVar3 + 0x50);
    sVar2 = *(short *)(iVar3 + 0x52);
    FUN_00051478(param_1,(int)*(short *)(iVar3 + 0x4e) << 10 | 0xd4000000U |
                         (int)*(short *)(iVar3 + 0x4c));
    FUN_00051478(param_1,(int)sVar2 << 10 | 0xd5000000U | (int)sVar1);
  }
}
