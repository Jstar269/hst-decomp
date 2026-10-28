/* HSTMATCH module=EBOOT.BIN start=0x0005f7d0 end=0x0005f848 symbol=FUN_0005f7d0 lang=c99 data=0x002d0f9c */
/* Clone of src/sharing_main/FUN_000605c0.c (hstclone.py tag s10171846c1r2e): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d0f9c-0x002d0fb3) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: reuse the scaled size for the unsigned boundary and preserve the selected-local branch order; exact match verified; names and types await human review. */
#include "hst/types.h"
extern int FUN_0000d518(void);
extern u8 *FUN_0000fe3c(void);
extern void FUN_0005f300(u32, const char *);
int FUN_0005f7d0(int param_1, u32 param_2)
{
  int iVar1;
  u32 *puVar2;
  u32 uVar3;
  u32 local_4;
  u32 local_8;
  local_8 = param_2;
  uVar3 = *(int *)(param_1 + 8) * 0x20;
  local_4 = uVar3;
  if (-1U - uVar3 < param_2) {
    iVar1 = (int)FUN_0000fe3c();
    FUN_0005f300(*(u32 *)(iVar1 + 0xc), "bitvector length error");
    FUN_0000d518();
  }
  if (uVar3 < local_8) {
    puVar2 = &local_8;
  } else {
    puVar2 = &local_4;
  }
  return uVar3 + *puVar2;
}
