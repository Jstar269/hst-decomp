/* HSTMATCH module=EBOOT.BIN start=0x001bed48 end=0x001bee20 symbol=FUN_001bed48 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* For each of the 640 kind-2 objects of the manager DAT_00338b08 (FUN_000d8c24 lookup): clear the object's mark byte
   (marks2[index]), then, for an existing object with a non-negative state byte, call FUN_001bf980(self, index, 5) when
   `all` is set, when the state is 1, or when FUN_001bb944(self, 2, index) accepts it. Names provisional. */
#include "hst/flag_tables.h"

extern "C" {
extern void *DAT_00338b08;
MgrEntry *FUN_000d8c24(void *mgr, int kind, int index);
void FUN_001bf980(FlagTables *self, int index, int mode);
int FUN_001bb944(FlagTables *self, int kind, int index);
}

extern "C" void FUN_001bed48(FlagTables *self, int all)
{
  for (int i = 0; i < MARK_COUNT; i++) {
    MgrEntry *entry = FUN_000d8c24(DAT_00338b08, 2, i);
    self->marks2[i] = 0;
    if (entry != 0 && entry->state >= 0) {
      if (all) {
        FUN_001bf980(self, i, 5);
      } else if (entry->state == 1) {
        FUN_001bf980(self, i, 5);
      } else if (FUN_001bb944(self, 2, i)) {
        FUN_001bf980(self, i, 5);
      }
    }
  }
}
