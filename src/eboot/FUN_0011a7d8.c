/* HSTMATCH module=EBOOT.BIN start=0x0011a7d8 end=0x0011a820 symbol=FUN_0011a7d8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/action_pair_obj.h"

typedef struct GlobB {
  char pad[0x8c];
  int unk8c;      /* 0x8c */
} GlobB;

extern GlobB *DAT_00338b44;

/* True when any of the object's action codes is 5 (only checked while unk8c is zero). */
u32 FUN_0011a7d8(ActionPairObj *self)
{
  int i;
  
  if (DAT_00338b44->unk8c == 0) {
    i = 0;
    do {
      if (self->action[i] == 5) {
        return 1;
      }
      i = i + 1;
    } while (i < ACTION_SLOT_COUNT);
  }
  return 0;
}
