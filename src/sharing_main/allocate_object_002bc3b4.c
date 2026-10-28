/* HSTMATCH module=hstp_trans_main.prx start=0x002bc3b4 end=0x002bc4e4 symbol=FUN_002bc3b4 lang=c99 */
/* Clone of src/eboot/allocate_object_002acbf8.c (hstclone.py tag u5cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: assigned the allocation result in the null-check expression and shared its return path; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002cc260;
extern u8 DAT_003b0a68;
extern char DAT_002dc5a0[];
extern char DAT_002dc5a8[];
extern char DAT_002dc5b0[];
extern int FUN_00000bcc();
extern int FUN_00014934();
extern u32 FUN_00056cac();
extern u32 * FUN_001016c0();
extern u32 * FUN_00101748();
extern u32 * FUN_001017dc();

u32 * FUN_002bc3b4(int param_1,u32 param_2,u8 *param_3)
{
  int iVar1;
  u32 *puVar2;
  
  iVar1 = FUN_00014934(param_2,DAT_002dc5b0);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x54);
    *(int *)(param_1 + 0x54) = iVar1 + -1;
    *param_3 = 0 < iVar1;
  }
  else {
    iVar1 = FUN_00014934(param_2,DAT_002dc5a8);
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x58);
      *(int *)(param_1 + 0x58) = iVar1 + -1;
      *param_3 = 0 < iVar1;
    }
    else {
      iVar1 = FUN_00014934(param_2,DAT_002dc5a0);
      if (iVar1 == 0) {
        iVar1 = *(int *)(param_1 + 0x5c);
        *(int *)(param_1 + 0x5c) = iVar1 + -1;
        *param_3 = 0 < iVar1;
      }
      else {
        *param_3 = 0;
      }
    }
  }
  if ((puVar2 = (u32 *)FUN_00000bcc(0xd0)) == (u32 *)0x0) goto done;
  FUN_001017dc(puVar2);
  FUN_00056cac(puVar2 + 0xc);
  *puVar2 = (unsigned int)(&DAT_003b0a68);
  puVar2[0x1c] = 0;
  puVar2[0x1d] = 0xffffffff;
  puVar2[0x1e] = 0x3f800000;
  puVar2[0x1f] = 0x3f800000;
  FUN_00056cac(puVar2 + 0x20);
  puVar2[0x30] = param_2;
  FUN_00101748(puVar2,&DAT_002cc260);
  FUN_001016c0(puVar2 + 0x20,&DAT_002cc260);
done:
  return puVar2;
}
