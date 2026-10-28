/* HSTMATCH module=EBOOT.BIN start=0x000464ec end=0x00046518 symbol=FUN_000464ec lang=c99 */
/* Clone of src/sharing_main/FUN_000465ec.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00310fcc;
extern int FUN_002b77e0();

bool FUN_000464ec(void)
{
  int iVar1;
  
  iVar1 = FUN_002b77e0();
  return DAT_00310fcc == iVar1;
}
