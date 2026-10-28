/* HSTMATCH module=hstp_trans_main.prx start=0x0008c400 end=0x0008c498 symbol=FUN_0008c400 lang=c99 */
/* Clone of src/eboot/obj_update_slots_0008ad40.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a3/v10) corrected by hand: the u8 flag at +0x4c is unsigned char (lbu) and the loop counter is declared before the pointer for the s-register assignment; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003e19f8;
extern u32 DAT_003e1e30;
extern void FUN_000982d4();

void FUN_0008c400(char *param_1)
{
  u32 uVar2;
  char *iVar1;
  
  if ((DAT_003e19f8 != '\0') && (DAT_003e1e30 != 0)) {
    uVar2 = 0;
    iVar1 = param_1;
    do {
      if (*(int *)(iVar1 + 0x70) != 0) {
        FUN_000982d4(*(int *)(iVar1 + 0x70),*(int *)(param_1 + 0x5c),*(u32 *)(param_1 + 100))
        ;
      }
      uVar2 = uVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (uVar2 < 4);
    if (*(unsigned char *)(param_1 + 0x4c) == 0) {
      *(u8 *)(param_1 + 0x4c) = 1;
      *(u32 *)(param_1 + 0x50) = 0x708;
    }
  }
}
