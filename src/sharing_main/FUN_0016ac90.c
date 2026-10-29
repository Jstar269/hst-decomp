/* HSTMATCH module=hstp_trans_main.prx start=0x0016ac90 end=0x0016acf0 symbol=FUN_0016ac90 lang=c99 */
/* Clone of src/eboot/FUN_0015e704.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003751d4;
extern void FUN_0001e7ac();
extern void FUN_0001eb84();
extern bool FUN_0001eb98();
extern void FUN_0016acf0();

void FUN_0016ac90(u32 arg)
{
  u8 held;
  
  held = FUN_0001eb98();
  if (held != '\0') {
    FUN_0001eb84();
  }
  FUN_0016acf0(arg,DAT_003751d4);
  if (held != '\0') {
    FUN_0001e7ac();
  }
}
