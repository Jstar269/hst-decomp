/* HSTMATCH module=EBOOT.BIN start=0x000db90c end=0x000db93c symbol=FUN_000db90c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/rule_obj.h"

/* Returns 1 when the checked rule field is zero for both passes of the loop. */
u32 FUN_000db90c(RuleObj *self)
{
  int i;

  i = 0;
  do {
    if (self->unk8c != 0) {
      return 0;
    }
    i = i + 1;
  } while (i < 2);
  return 1;
}
