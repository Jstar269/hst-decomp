/* HSTMATCH module=EBOOT.BIN start=0x00291868 end=0x002918f0 symbol=FUN_00291868 lang=c99 data=0x002ff9bc */
/* Ghidra pseudocode (hstgen.py tag a7/v21) corrected by hand: replaced raw offsets with a struct and recovered the dropped argument of FUN_002b79a8; readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002ff9bc-0x002ff9db) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/thread_task.h"

extern char DAT_002ff9dc[];
extern void FUN_0028fb44();
extern int FUN_002b78d8();
extern void FUN_002b79a8(int);

/* Starts the already-created thread with the task as its argument; returns 1 on success, 0 on failure. */
int FUN_00291868(ThreadTask *self)
{
  ThreadTask *start_arg;
  int r;

  if (self->thread < 0) {
    FUN_0028fb44("ERROR: thread is not created.\n");
    r = 0;
  } else {
    start_arg = self;
    if (FUN_002b78d8(self->thread, 4, &start_arg) < 0) {
      FUN_0028fb44(DAT_002ff9dc, self->thread);
      if (self->thread >= 1) {
        FUN_002b79a8(self->thread);
        self->thread = -1;
      }
      r = 0;
    } else {
      r = 1;
    }
  }
  return r;
}
