/* HSTMATCH module=EBOOT.BIN start=0x001f4c04 end=0x001f4c54 symbol=FUN_001f4c04 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: split the byte guard so the dependent object load fills its delay slot before the global-pointer check; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_group.h"

extern u32 DAT_00338714;
extern void FUN_0005c7a4(int param_1, int param_2, float *param_3);

/* Pass the child's float field to the global handler when the group is active and the child's kind is 1. */
void FUN_001f4c04(SlotGroup *self)
{
  GroupChild *child;
  int kind;
  u32 global;

  if (self->active == 0) return;
  child = self->child;
  global = DAT_00338714;
  if (global == 0) return;
  kind = child->kind;
  if (kind != 1) return;
  FUN_0005c7a4(global, 0, &child->unk110);
}
