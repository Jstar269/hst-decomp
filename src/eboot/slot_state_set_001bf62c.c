/* HSTMATCH module=EBOOT.BIN start=0x001bf62c end=0x001bf884 symbol=FUN_001bf62c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag km4 near miss, wip/best_001bf62c.c) corrected by hand: last byte-threshold test written `uVar8 > 1u` instead of `>= 2u` (gives the sltiu at / bnez at pair); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_001bb8b8();
extern void FUN_001bbab8();
extern void FUN_001bf948();
extern void FUN_001bf980();
extern void FUN_001bf9b8();

void FUN_001bf62c(int param_1,int param_2,u8 param_3)
{
  u8 bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  u32 uVar8;
  u8 *pbVar6;
  u8 *pbVar7;
  
  if ((param_2 >= 0) && (param_2 < 0xf)) {
    pbVar7 = (u8 *)(param_1 + param_2 * 0x38 + 4);
  }
  else {
    pbVar7 = (u8 *)0x0;
  }
  if (pbVar7 != (u8 *)0x0) {
    *pbVar7 = param_3;
    uVar8 = (u32)*pbVar7 - 4u;
    if (uVar8 < 2u) {
      iVar2 = FUN_001bb8b8(1,param_2);
      iVar3 = FUN_001bb8b8(1,param_2);
      iVar4 = FUN_001bb8b8(3,param_2);
      iVar5 = FUN_001bb8b8(4,param_2);
      if ((iVar2 >= 0) && (iVar2 < 0x280)) {
        pbVar6 = (u8 *)(param_1 + iVar2 + 0x84c);
      }
      else {
        pbVar6 = (u8 *)0x0;
      }
      uVar8 = (u32)(*pbVar6 - 4);
      if (uVar8 > 1u) {
        FUN_001bf948(param_1,iVar2,4);
      }
      if ((iVar3 >= 0) && (iVar3 < 0x280)) {
        pbVar6 = (u8 *)(param_1 + iVar3 + 0xacc);
      }
      else {
        pbVar6 = (u8 *)0x0;
      }
      uVar8 = (u32)(*pbVar6 - 4);
      if (uVar8 > 1u) {
        FUN_001bf980(param_1,iVar3,4);
      }
      if (iVar4 != 0) {
        if ((iVar4 >= 0) && (iVar4 < 0x280)) {
          pbVar6 = (u8 *)(param_1 + iVar4 + 0xd4c);
        }
        else {
          pbVar6 = (u8 *)0x0;
        }
        uVar8 = (u32)(*pbVar6 - 4);
      if (uVar8 > 1u) {
          FUN_001bf9b8(param_1,iVar4,4);
        }
      }
      if (iVar5 != 0) {
        if ((iVar5 >= 0) && (iVar5 < 0x280)) {
          pbVar6 = (u8 *)(param_1 + iVar5 + 0xd4c);
        }
        else {
          pbVar6 = (u8 *)0x0;
        }
        uVar8 = (u32)(*pbVar6 - 4);
      if (uVar8 > 1u) {
          FUN_001bf9b8(param_1,iVar5,4);
        }
      }
      if (param_2 == 0xb) {
        uVar8 = (u32)*(u8 *)(param_1 + 0xacf) - 4u;
        if (uVar8 > 1u) {
          FUN_001bf980(param_1,3,4);
        }
      }
    }
    uVar8 = (u32)*pbVar7 - 4u;
    if (uVar8 < 2u) {
      FUN_001bbab8(pbVar7);
    }
  }
}
