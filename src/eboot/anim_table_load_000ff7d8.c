/* HSTMATCH module=EBOOT.BIN start=0x000ff7d8 end=0x000ff98c symbol=FUN_000ff7d8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: DAT_0033a6dc is an unsigned char (lbu), and iVar6 declared before iVar5 so the loop index gets s1 and the byte offset s0; exact match verified; names and types await human review. */
#include "hst/types.h"

extern unsigned char DAT_0033a6dc;
extern int FUN_00000a90();
extern u32 * FUN_000149a8();
extern int * FUN_000649c0();
extern int * FUN_00064a08();
extern u32 FUN_00064bf4();
extern u32 FUN_000650e0();
extern int FUN_00065104();
extern int FUN_0006517c();

u32 FUN_000ff7d8(int *param_1,u32 param_2,u32 param_3,u32 param_4)
{
  u8 cVar1;
  u16 uVar2;
  int iVar3;
  u32 uVar4;
  int iVar6;
  int iVar5;
  u8 auStack_10 [16];
  
  FUN_000649c0(auStack_10);
  cVar1 = FUN_00064bf4(auStack_10,param_2,param_3,param_4);
  if (cVar1 == '\0') {
    *param_1 = 0;
    FUN_00064a08(auStack_10,0xffffffff);
    uVar4 = 0;
  }
  else {
    iVar3 = FUN_000650e0(auStack_10);
    *param_1 = iVar3;
    iVar3 = FUN_00000a90((iVar3 + -1) * 8);
    param_1[1] = iVar3;
    iVar3 = *param_1 + -1;
    iVar6 = 0;
    if (0 < iVar3) {
      iVar5 = 0;
      do {
        uVar2 = FUN_00065104(auStack_10,iVar6 + 1,1);
        *(u16 *)(param_1[1] + iVar5) = uVar2;
        uVar2 = FUN_00065104(auStack_10,iVar6 + 1,2);
        *(u16 *)(param_1[1] + iVar5 + 2) = uVar2;
        uVar2 = FUN_00065104(auStack_10,iVar6 + 1,3);
        *(u16 *)(param_1[1] + iVar5 + 4) = uVar2;
        uVar2 = FUN_00065104(auStack_10,iVar6 + 1,4);
        iVar6 = iVar6 + 1;
        *(u16 *)(param_1[1] + iVar5 + 6) = uVar2;
        iVar3 = *param_1 + -1;
        iVar5 = iVar5 + 8;
      } while (iVar6 < iVar3);
    }
    if (DAT_0033a6dc != '\0') {
      iVar3 = FUN_00000a90(iVar3 << 7);
      param_1[2] = iVar3;
      iVar3 = 0;
      if (0 < *param_1 + -1) {
        iVar6 = 0;
        do {
          uVar4 = FUN_0006517c(auStack_10,iVar3 + 1,0);
          FUN_000149a8(param_1[2] + iVar6,uVar4);
          iVar3 = iVar3 + 1;
          iVar6 = iVar6 + 0x80;
        } while (iVar3 < *param_1 + -1);
      }
    }
    FUN_00064a08(auStack_10,0xffffffff);
    uVar4 = 1;
  }
  return uVar4;
}
