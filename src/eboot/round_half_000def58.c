/* HSTMATCH module=EBOOT.BIN start=0x000def58 end=0x000defb4 symbol=FUN_000def58 lang=c99 */
/* Hand-written reconstruction from the disassembly; matching idiom: shared bool result with an inner >= half branch; exact match verified; names and types await human review. */
extern unsigned char DAT_00338b48;
#include "hst/types.h"
#include "hst/rule_obj.h"
/* With the global flag set: whether side 1 has any games. Otherwise: true once either side's set count reaches half of numSets (rounded up). */
bool FUN_000def58(RuleObj *self) {
  bool result;
  if (DAT_00338b48 != 0) {
    result = self->games[1] > 0;
  } else {
  int half = (self->numSets + 1) / 2;
  if (self->sets[0] < half) {
      if (self->sets[1] >= half) result = 1;
      else result = 0;
    } else {
      result = 1;
    }
  }
  return result;
}
