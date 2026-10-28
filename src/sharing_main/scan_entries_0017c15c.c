/* HSTMATCH module=hstp_trans_main.prx start=0x0017c15c end=0x0017c208 symbol=FUN_0017c15c lang=c99 */
/* Clone of src/eboot/scan_entries_0016ff10.c (hstclone.py tag km3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: hold the call context and table base in locals before indexed access. */
#include "hst/types.h"

extern void *DAT_003e1e48;
extern int FUN_000dca74(void *, int, int);

#pragma opt_strength_reduction off

u32 FUN_0017c15c(int param_1)
{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  int *piVar4;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 0x200) != 0) {
LOOP_BODY:
      void *context = DAT_003e1e48;
      int **entries = *(int ***)(param_1 + 0x1fc);
      piVar4 = entries[uVar3];
      iVar1 = FUN_000dca74(context,2,*piVar4);
      if (iVar1 != 0) {
        if (*(signed char *)(iVar1 + 0x60) >= 0) {
          if (*(unsigned char *)(param_1 + *piVar4 + 0x8bb) == 4) {
            return 1;
          }
        }
      }
      uVar2 = *(u32 *)(param_1 + 0x200);
      uVar3 = uVar3 + 1;
    if (uVar3 < uVar2) goto LOOP_BODY;
  }
  return 0;
}
