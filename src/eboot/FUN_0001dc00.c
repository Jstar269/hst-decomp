/* HSTMATCH module=EBOOT.BIN start=0x0001dc00 end=0x0001dc7c symbol=FUN_0001dc00 lang=c99 */
/* Clone of src/sharing_main/FUN_0001d84c.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: typed the copied globals as bytes to preserve retail u8 loads and stores; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002cfc8c;
extern u8 DAT_0030fc40;
extern u8 DAT_0030fe0c;
extern u8 DAT_0030fe0d;
extern u8 DAT_0030fe0e;
extern u8 DAT_0030fe0f;
extern u8 DAT_0030fe10;
extern u8 DAT_0030fe11;
extern u8 DAT_0030fe12;
extern u8 DAT_0030fe13;
extern void FUN_0001e268();
extern u32 FUN_0001f004();

void FUN_0001dc00(void)
{
  DAT_002cfc8c = (unsigned int)(&DAT_0030fc40);
  DAT_0030fe0c = DAT_0030fe10;
  DAT_0030fe0d = DAT_0030fe11;
  DAT_0030fe0e = DAT_0030fe12;
  DAT_0030fe0f = DAT_0030fe13;
  FUN_0001f004(&DAT_0030fe10);
  FUN_0001e268(DAT_002cfc8c);
}
