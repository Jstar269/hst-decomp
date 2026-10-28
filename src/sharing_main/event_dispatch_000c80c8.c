/* HSTMATCH module=hstp_trans_main.prx start=0x000c80c8 end=0x000c8170 symbol=FUN_000c80c8 lang=c99 */
/* Clone of src/eboot/event_dispatch_000c482c.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
extern u32 DAT_003e1e04;
extern u32 DAT_003e1e84;
extern u32 FUN_000bdad0(u32);
extern int FUN_000e3144();

u32 FUN_000c80c8(int param_1,int param_2)
{
  int iVar1;

  switch (param_2) {
  case 0x13:
    if (DAT_003e1e04 != 0) {
      FUN_000bdad0(DAT_003e1e04);
    }
    break;
  case 0x14:
    iVar1 = FUN_000e3144(DAT_003e1e84);
    if (iVar1 != 0) {
      *(u8 *)(*(int *)(param_1 + 0x784) + 4) = 1;
    }
    break;
  case 0x19:
    iVar1 = FUN_000e3144(DAT_003e1e84);
    if (iVar1 != 0) {
      *(u8 *)(*(int *)(param_1 + 0x784) + 4) = 1;
    }
    break;
  }
  return 0;
}
