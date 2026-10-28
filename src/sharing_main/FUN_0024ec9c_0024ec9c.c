/* HSTMATCH module=hstp_trans_main.prx start=0x0024ec9c end=0x0024ed84 symbol=FUN_0024ec9c lang=c99 */
/* Clone of src/eboot/FUN_0023eb04_0023eb04.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: declared the nested delete helper arguments and passed the deleted fields; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00(void *);
extern int FUN_0024ed84();

int * FUN_0024ec9c(int *param_1,short param_2)
{
  u32 *puVar1;
  u32 *puVar2;
  
  if (param_1 != (int *)0x0) {
    puVar1 = (u32 *)(*param_1 + param_1[4] * 0xc);
    puVar2 = puVar1 + param_1[1] * 3;
    if (puVar1 < puVar2) {
      do {
        puVar2 = puVar2 + -3;
        if ((puVar2 != (u32 *)0x0) && ((*puVar2 & 1) != 0)) {
          FUN_00000a00((void *)puVar2[2]);
        }
      } while (puVar1 < puVar2);
      param_1[1] = 0;
    }
    else {
      param_1[1] = 0;
    }
    if ((param_1 != (int *)0x0) && (FUN_0024ed84((int)param_1), *param_1 != 0)) {
      FUN_00000a00((void *)*param_1);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
