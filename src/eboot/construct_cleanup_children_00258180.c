/* HSTMATCH module=EBOOT.BIN start=0x00258180 end=0x00258294 symbol=FUN_00258180 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a3) corrected by hand: typed the pointer walk and ordered the cursor and count locals to match the loop registers; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309380;
extern u8 DAT_00309968;
extern u8 DAT_0034179c;
extern void FUN_00000788();
extern void FUN_00000a00(void *);
extern u32 FUN_00049094();
extern int FUN_0005ba00();
extern u32 * FUN_00102ea4();
extern void FUN_001b3008();
extern void FUN_001b3e2c();
extern int FUN_0025a0e8();
extern void FUN_0008d72c();

u32 * FUN_00258180(u32 *param_1,short param_2)
{
  u32 uVar2;
  u32 *puVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309968);
    FUN_001b3e2c((int *)&DAT_0034179c);
    FUN_001b3008((int *)&DAT_0034179c);
    FUN_00000788((int)(param_1 + 0x1bc),FUN_0008d72c,0x458,4);
    if ((char *)param_1 + 0x60 != (char *)0) {
      FUN_00049094(1);
      uVar2 = 0;
      puVar1 = param_1;
      do {
        if (puVar1[0x30] != 0) {
          FUN_0005ba00(puVar1[0x30],1);
          puVar1[0x30] = 0;
        }
        uVar2 = uVar2 + 1;
        puVar1 = puVar1 + 1;
      } while (uVar2 < 4);
      puVar1 = param_1 + 0x93;
      if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
        FUN_0025a0e8((int)puVar1,0);
      }
    }
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_00309380);
      FUN_00102ea4(param_1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
