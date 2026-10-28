/* HSTMATCH module=EBOOT.BIN start=0x001c7d30 end=0x001c7df0 symbol=FUN_001c7d30 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inverted readiness guards and typed float/pointer helper arguments; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_0033b574;
extern char DAT_002eaa14[];
extern char DAT_0034179c[];
extern char * FUN_00014d64();
extern void FUN_001b4848(float,void *);
extern void FUN_001b359c(float,void *);
extern u32 FUN_00287418();
extern u32 FUN_00287460();

void FUN_001c7d30(int param_1,u32 param_2,u32 param_3,u32 param_4, u8 param_5)
{
  int iVar1;
  
  *(u32 *)(param_1 + 0xd4) = param_2;
  *(u32 *)(param_1 + 0xd8) = param_3;
  *(u32 *)(param_1 + 0xdc) = param_4;
  *(u8 *)(param_1 + 0xe2) = param_5;
  if (DAT_0033b574 != 0) {
    iVar1 = FUN_00287418(DAT_0033b574 + 0x1320);
    if (iVar1 != 0) {
      iVar1 = FUN_00287460(DAT_0033b574 + 0x1320);
      if (iVar1 != 0) {
        iVar1 = (int)(FUN_00014d64(iVar1,DAT_002eaa14));
        *(bool *)(param_1 + 0xe0) = iVar1 != 0;
      }
    } else {
      *(u8 *)(param_1 + 0xe0) = 0;
    }
  } else {
    *(u8 *)(param_1 + 0xe0) = 0;
  }
  FUN_001b4848(0.2f,DAT_0034179c);
  FUN_001b359c(0.2f,DAT_0034179c);
  *(u32 *)(param_1 + 0xc4) = 3;
  *(u32 *)(param_1 + 200) = 0;
}
