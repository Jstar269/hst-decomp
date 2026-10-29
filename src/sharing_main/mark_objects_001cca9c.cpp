/* HSTMATCH module=hstp_trans_main.prx start=0x001cca9c end=0x001ccb74 symbol=FUN_001cca9c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* For each of the 640 kind-2 objects of the manager DAT_003e1e48 (FUN_000dca74 lookup): clear the object's mark byte
   (marks2[index]), then, for an existing object with a non-negative state byte, call FUN_001cd780(self, index, 5) when
   `all` is set, when the state is 1, or when FUN_001c972c(self, 2, index) accepts it. Names provisional. */
#include "hst/flag_tables.h"

extern "C" {
extern void *DAT_003e1e48;
MgrEntry *FUN_000dca74(void *mgr, int kind, int index);
void FUN_001cd780(FlagTables *self, int index, int mode);
int FUN_001c972c(FlagTables *self, int kind, int index);
}

extern "C" void FUN_001cca9c(FlagTables *self, int all)
{
  for (int i = 0; i < MARK_COUNT; i++) {
    MgrEntry *entry = FUN_000dca74(DAT_003e1e48, 2, i);
    self->marks2[i] = 0;
    if (entry != 0 && entry->state >= 0) {
      if (all) {
        FUN_001cd780(self, i, 5);
      } else if (entry->state == 1) {
        FUN_001cd780(self, i, 5);
      } else if (FUN_001c972c(self, 2, i)) {
        FUN_001cd780(self, i, 5);
      }
    }
  }
}
