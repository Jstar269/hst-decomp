/* HSTMATCH module=EBOOT.BIN start=0x001b646c end=0x001b64fc symbol=FUN_001b646c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: merged if/else-if into single || condition with bitwise OR, struct field access; readability pass; exact match verified; names and types await human review. */
#include "hst/state_obj.h"

extern unsigned char DAT_003386b8;
extern int *DAT_003402a0;
extern unsigned char DAT_003417c8;
extern void *DAT_0034179c;
extern void FUN_001b39e4(const void *, int, int);
extern int FUN_0022cc04(void);

/* Pushes the current mode (minus one) and a flag to the sound manager; the flag is only set in mode 17. */
void FUN_001b646c(StateObj *self)
{
  int mode = *(int *)((char *)DAT_003402a0 + 0x1364);
  int flag = 0;
  if (mode == 17) {
    if ((DAT_003386b8 == 0 && self->unk90 != 0 && FUN_0022cc04() != 0) || DAT_003417c8 != 0) {
      flag |= 1;
    }
  }
  FUN_001b39e4(&DAT_0034179c, mode - 1, flag);
}
