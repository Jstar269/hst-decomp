/* HSTMATCH module=hstp_trans_main.prx start=0x002a9b40 end=0x002a9c24 symbol=FUN_002a9b40 lang=c99 */
/* Clone of src/eboot/FUN_0029a8bc_0029a8bc.c (hstclone.py tag u6cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: shared the owner-field assignment and used an explicit zero allocation case; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b3130;
extern u32 DAT_003f4668;
extern int FUN_00000bcc();
extern int FUN_00010184();
extern u32 * FUN_0001ec44();
extern u8 * FUN_002a9c24();

u32 * FUN_002a9b40(u32 *param_1)
{
  u8 *puVar1;
  int iVar2;
  u32 uVar3;
  
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b3130);
  param_1[0xf] = 0;
  DAT_003f4668 = (unsigned int)(param_1);
  puVar1 = (u8 *)FUN_00000bcc(0x2c);
  if (puVar1 != (u8 *)0x0) {
    *puVar1 = 0;
    *(u32 *)(puVar1 + 4) = 0;
    *(u32 *)(puVar1 + 8) = 0;
    *(u32 *)(puVar1 + 0xc) = 0;
    *(u32 *)(puVar1 + 0x10) = 0;
    *(u32 *)(puVar1 + 0x14) = 0;
    *(u32 *)(puVar1 + 0x18) = 0;
    *(u32 *)(puVar1 + 0x1c) = 0;
    *(u32 *)(puVar1 + 0x20) = 0;
    puVar1[0x24] = 0;
    *(u32 *)(puVar1 + 0x28) = 0;
    iVar2 = FUN_00000bcc(0x1583c);
    switch (iVar2) {
    case 0:
      *(u32 *)(puVar1 + 0xc) = iVar2;
      break;
    default:
      uVar3 = (unsigned int)(FUN_002a9c24(iVar2));
      *(u32 *)(puVar1 + 0xc) = uVar3;
      break;
    }
    uVar3 = FUN_00000bcc(0x2c4);
    *(u32 *)(puVar1 + 0x10) = uVar3;
    uVar3 = FUN_00000bcc(0x50);
    *(u32 *)(puVar1 + 0x14) = uVar3;
    uVar3 = FUN_00000bcc(100);
    *(u32 *)(puVar1 + 0x18) = uVar3;
    uVar3 = FUN_00010184(0x40,0x216e00);
    *(u32 *)(puVar1 + 0x1c) = uVar3;
  }
  param_1[0xf] = (unsigned int)(puVar1);
  return param_1;
}
