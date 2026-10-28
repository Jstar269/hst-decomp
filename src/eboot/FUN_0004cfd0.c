/* HSTMATCH module=EBOOT.BIN start=0x0004cfd0 end=0x0004d028 symbol=FUN_0004cfd0 lang=c99 */
/* Clone of src/sharing_main/FUN_0004d2c4.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030ab9c;
extern u8 DAT_0030fbfd;
extern u32 DAT_00311158;
extern void FUN_0001c810();
extern int FUN_002b7738();

u32 FUN_0004cfd0(void)
{
  u32 uVar1;
  
  if (DAT_00311158 == 0) {
    if (DAT_0030fbfd != '\0') {
      FUN_0001c810((int)&DAT_0030ab9c);
      return 0;
    }
  }
  else {
    DAT_00311158 = DAT_00311158 + -1;
  }
  uVar1 = FUN_002b7738();
  return uVar1;
}
