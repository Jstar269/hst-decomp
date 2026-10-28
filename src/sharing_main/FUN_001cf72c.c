/* HSTMATCH module=hstp_trans_main.prx start=0x001cf72c end=0x001cf7b0 symbol=FUN_001cf72c lang=c99 rodata=0x002d6850 */
/* Clone of src/eboot/FUN_001c1518.c (hstclone.py tag ds1011s2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u16 FUN_001cf72c(char *param_1,u32 param_2)
{
  u16 uVar1;
  
  switch(param_2) {
  case 0:
    uVar1 = *(u16 *)(param_1 + 0x8416);
    break;
  case 1:
    uVar1 = *(u16 *)(param_1 + 0x8418);
    break;
  case 2:
    uVar1 = *(u16 *)(param_1 + 0x841a);
    break;
  case 3:
  case 4:
    uVar1 = *(u16 *)(param_1 + 0x841c);
    break;
  case 5:
    uVar1 = *(u16 *)(param_1 + 0x841e);
    break;
  default:
    uVar1 = 0;
  }
  return uVar1;
}
