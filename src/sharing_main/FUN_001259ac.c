/* HSTMATCH module=hstp_trans_main.prx start=0x001259ac end=0x001259f4 symbol=FUN_001259ac lang=c99 */
/* Clone of src/eboot/FUN_0011a7d8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/action_pair_obj.h"

typedef struct GlobB {
  char pad[0x8c];
  int unk8c;      /* 0x8c */
} GlobB;

extern GlobB *DAT_003e1e84;

/* True when any of the object's action codes is 5 (only checked while unk8c is zero). */
u32 FUN_001259ac(ActionPairObj *self)
{
  int i;
  
  if (DAT_003e1e84->unk8c == 0) {
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
