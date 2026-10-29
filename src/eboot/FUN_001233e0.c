/* HSTMATCH module=EBOOT.BIN start=0x001233e0 end=0x00123470 symbol=FUN_001233e0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/match_input.h"

extern int DAT_0033b49c;
extern int DAT_0033b4a0;

/* Mode handler: mode 8 resets the flag bytes and two globals. */
int FUN_001233e0(MatchInput *self, int mode)
{
  switch (mode) {
  case 0:
  case 1:
    break;
  case 8:
    self->unk8c = 0;
    self->unk7a = 1;
    self->unk7b = 0;
    self->unk7c = 0;
    DAT_0033b49c = 0;
    DAT_0033b4a0 = 0;
    break;
  case 9:
  case 10:
  case 11:
  case 14:
  case 15:
    break;
  default:
    break;
  }
  return 0;
}
