/* HSTMATCH module=hstp_trans_main.prx start=0x0012524c end=0x00125340 symbol=FUN_0012524c lang=c99 */
/* Clone of src/eboot/init_indexed_entry_0011a078.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: corrected helper prototypes and argument order, index arithmetic, and switch layout; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e1f60;
extern u8 FUN_000587ac(int, float, int, int);
extern void FUN_00059ac0(int, int, int);
extern void FUN_00059ba8(int, float, int);
extern void FUN_00059c1c(int, float, int);
extern void FUN_00059d68(int, int);
extern void FUN_00100c80();

void FUN_0012524c(int param_1,int param_2)
{
  int iVar1;
  u32 *puVar2;
  
  iVar1 = param_2 * 4;
  iVar1 += param_1;
  puVar2 = (u32 *)(iVar1 + 0x48);
  FUN_000587ac(*puVar2,0.0f,0,0);
  FUN_00059c1c(*puVar2,0.0f,0xffffffff);
  FUN_00059ba8(*puVar2,1.0f,0xffffffff);
  FUN_00059ac0(*puVar2,0,0xffffffff);
  FUN_00059d68(*puVar2,0xffffffff);
  *(u8 *)(param_2 + param_1 + 0xb4) = 1;
  switch (param_2) {
  case 9:
  case 1:
  case 5:
  case 0x11:
  case 0xb:
    *(u8 *)(param_1 + 0x44) = 1;
    FUN_00100c80(DAT_003e1f60);
    break;
  default:
    break;
  }
}
