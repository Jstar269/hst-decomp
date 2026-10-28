/* HSTMATCH module=EBOOT.BIN start=0x001a2370 end=0x001a2450 symbol=FUN_001a2370 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: invert the state gates and combine the probe comparisons; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00338ac4;
extern u32 DAT_003415ac;
extern u32 DAT_0034a678;
extern void FUN_00114168();
extern void FUN_001aee54();
extern u8 * FUN_001fea10();
extern int FUN_001feec4();

u32 FUN_001a2370(int param_1)
{
  bool bVar1;
  int iVar2;
  u32 uVar3;
  
  bVar1 = false;
  if (*(u8 *)(param_1 + 0x2a4) != '\0') {
    if (*(u8 *)(param_1 + 0x4d) == '\0') {
      if (*(u8 *)(DAT_00338ac4 + 0x178) != '\0') {
        bVar1 = true;
      }
      else {
        iVar2 = FUN_001feec4();
        if ((*(int *)(iVar2 + 0x3ac) != DAT_0034a678) ||
            (*(int *)(iVar2 + 0x3b8) != 0xe)) {
          bVar1 = true;
        }
      }
      if (bVar1) {
        *(u32 *)(param_1 + 0x44) = 0x13;
        uVar3 = (unsigned int)(FUN_001fea10(0x11,0x10,2));
        FUN_00114168(DAT_003415ac,1,uVar3,0,0);
        FUN_001aee54(param_1 + 0x68,1);
        return 1;
      }
    }
  }
  return 0;
}
