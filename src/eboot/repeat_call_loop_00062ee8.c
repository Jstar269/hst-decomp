/* HSTMATCH module=EBOOT.BIN start=0x00062ee8 end=0x00062f68 symbol=FUN_00062ee8 lang=c99 */
/* Clone of src/sharing_main/repeat_call_loop_00063dac.c (hstclone.py tag c034920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00331b80;
extern void FUN_00062150(float);
extern void FUN_002b7a78();

int FUN_00062ee8(int param_1)
{
  int r;
  int i;

  r = 0;
  for (i = 0; i < param_1; i++) {
    if (DAT_00331b80 == 0) {
      r = 1;
      break;
    }
    FUN_00062150(30.0f);
    FUN_002b7a78();
    FUN_002b7a78();
  }
  return r;
}
