/* HSTMATCH module=hstp_trans_main.prx start=0x002350ec end=0x002351a8 symbol=FUN_002350ec lang=c99 rodata=0x002d9fc4 */
/* Clone of src/eboot/FUN_00225b78.c (hstclone.py tag ds1011s2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003eaad8;
extern char DAT_0039964c[];
extern char DAT_0039965c[];
extern char DAT_0039966c[];
extern char DAT_0039967c[];
extern char DAT_0039968c[];
extern void FUN_001c0984();

void FUN_002350ec(u32 param_1,u32 param_2)
{
  switch(param_2) {
  case 0:
  case 2:
  case 3:
  case 9:
    FUN_001c0984((int)&DAT_003eaad8,DAT_0039964c);
    break;
  case 1:
  case 4:
  case 5:
    FUN_001c0984((int)&DAT_003eaad8,DAT_0039965c);
    break;
  case 6:
  case 7:
    FUN_001c0984((int)&DAT_003eaad8,DAT_0039966c);
    break;
  case 8:
    FUN_001c0984((int)&DAT_003eaad8,DAT_0039967c);
    break;
  case 10:
    FUN_001c0984((int)&DAT_003eaad8,DAT_0039968c);
  }
}
