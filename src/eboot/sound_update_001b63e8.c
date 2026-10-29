/* HSTMATCH module=EBOOT.BIN start=0x001b63e8 end=0x001b646c symbol=FUN_001b63e8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: switch on DAT_0034a678, struct member access, symbol address DAT_0034179c; readability pass; exact match verified; names and types await human review. */
#include "hst/state_obj.h"

extern int DAT_003417c4;
extern int DAT_0034a678;
extern const char DAT_002e99c4;
extern void *DAT_0034179c;
extern void FUN_00000020(const void *);
extern void FUN_00000028(void);
extern void FUN_001b39ec(const void *);
extern void FUN_001b4dfc(int);
extern void FUN_001b646c(StateObj *);
extern char FUN_0022c860(void);

/* Clears the mode flags, sets them for mode 0x2a, then refreshes the sound manager. */
void FUN_001b63e8(StateObj *self)
{
  FUN_00000020(&DAT_002e99c4);
  self->unk90 = 0;
  self->unk93 = 0;
  switch (DAT_0034a678) {
  case 0x2a:
    self->unk90 = 1;
    self->unk93 = FUN_0022c860();
    break;
  }
  FUN_001b4dfc(DAT_003417c4);
  FUN_001b646c(self);
  FUN_001b39ec(&DAT_0034179c);
  FUN_00000028();
}
