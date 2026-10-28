/* HSTMATCH module=EBOOT.BIN start=0x001fd2e0 end=0x001fd46c symbol=FUN_001fd2e0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003070bc;
extern u8 DAT_003095b0;
extern u32 DAT_0034a13c;
extern void FUN_00000788();
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern int * FUN_00064a08();
extern int FUN_00066338();
extern int FUN_001ffcc0();
extern int FUN_00201a44();
extern void FUN_00204394();
extern void FUN_0005ba00();

u32 * FUN_001fd2e0(u32 *param_1,short param_2)
{
  u32 *puVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003095b0);
    FUN_00204394();
    DAT_0034a13c = 0;
    if ((char *)param_1 + 0x12c4 != (char *)0) {
      puVar1 = param_1 + 0x4b9;
      param_1[0x4b1] = (unsigned int)(&DAT_003070bc);
      if ((((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) &&
          (puVar1 != (u32 *)0x0)) && (puVar1 != (u32 *)0x0)) {
        FUN_00066338((int)puVar1,0);
      }
      puVar1 = param_1 + 0x4b5;
      if (((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) &&
         ((puVar1 != (u32 *)0x0 && (puVar1 != (u32 *)0x0)))) {
        FUN_00066338((int)puVar1,0);
      }
      FUN_00064a08(param_1 + 0x4b1,0);
    }
    if ((char *)param_1 + 0x1294 != (char *)0) {
      puVar1 = param_1 + 0x4ad;
      param_1[0x4a5] = (unsigned int)(&DAT_003070bc);
      if (((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) &&
         ((puVar1 != (u32 *)0x0 && (puVar1 != (u32 *)0x0)))) {
        FUN_00066338((int)puVar1,0);
      }
      puVar1 = param_1 + 0x4a9;
      if ((((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) &&
          (puVar1 != (u32 *)0x0)) && (puVar1 != (u32 *)0x0)) {
        FUN_00066338((int)puVar1,0);
      }
      FUN_00064a08(param_1 + 0x4a5,0);
    }
    FUN_00201a44((int)(param_1 + 0x494),-1);
    FUN_00000788((int)(param_1 + 0x334),FUN_0005ba00,0x2c0,2);
    FUN_001ffcc0((int)(param_1 + 0x32),-1);
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
