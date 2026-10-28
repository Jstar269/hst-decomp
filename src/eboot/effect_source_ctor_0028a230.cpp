/* HSTMATCH module=EBOOT.BIN start=0x0028a230 end=0x0028a328 symbol=FUN_0028a230 lang=c++ data=0x002fed44 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002fed44-0x002fed4c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (generated draft FUN_0028a230.c, no tag) corrected by hand: the two new/ctor pairs
   use the null-case-else shape (`if (p != 0) f74 = ctor(p); else f74 = p;`), the selection count is the
   ternary `param_2[2] ? param_2[2] : param_2[0]` and the effect handle is the ternary
   `x ? FUN_0002fe80(x, str) : -1`; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_00309d08;
extern int FUN_00000bcc(...);
extern u32 FUN_0002fe80(...);
extern u32 * FUN_00056b98(...);
extern u32 * FUN_00286790(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void m(int); };

extern "C" u32 * FUN_0028a230(u32 *param_1,int *param_2)
{
  int iVar1;
  u32 uVar2;
  
  FUN_00286790(param_1);
  *param_1 = (unsigned int)(&DAT_00309d08);
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  iVar1 = FUN_00000bcc(0x1b0);
  if (iVar1 != 0) {
    param_1[0x1d] = (unsigned int)(FUN_00056b98(iVar1));
  }
  else {
    param_1[0x1d] = iVar1;
  }
  iVar1 = FUN_00000bcc(0x1b0);
  if (iVar1 != 0) {
    param_1[0x1e] = (unsigned int)(FUN_00056b98(iVar1));
  }
  else {
    param_1[0x1e] = iVar1;
  }
  param_1[0x1c] = param_2[2] ? param_2[2] : *param_2;
  ((VC_0 *)((int *)param_1[0x1d]))->m((int)(*param_2));
  ((VC_1 *)((int *)param_1[0x1e]))->m((int)(param_2[1]));
  param_1[0x1f] = param_2[3];
  *(u8 *)(param_1 + 0x3b) = 0;
  param_1[0x3c] = *(int *)(param_1[0x1c] + 8) ? FUN_0002fe80(*(int *)(param_1[0x1c] + 8),"eff_get") : 0xffffffff;
  return param_1;
}
