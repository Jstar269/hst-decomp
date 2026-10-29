/* HSTMATCH module=EBOOT.BIN start=0x000db724 end=0x000db788 symbol=FUN_000db724 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/rule_obj.h"

extern u8 DAT_003075f8;
extern RuleObj * DAT_00338b44;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();

/* Rule object destructor; frees the memory when delete_flag is positive. */
RuleObj * FUN_000db724(RuleObj *self,short delete_flag)
{
  if (self != (RuleObj *)0x0) {
    self->vtable = &DAT_003075f8;
    DAT_00338b44 = 0;
    FUN_0001f0f0(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
