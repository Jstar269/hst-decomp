/* HSTMATCH module=EBOOT.BIN start=0x002a00ac end=0x002a0140 symbol=FUN_002a00ac lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag t0), refined by hstperm.py random mutation from try/gen-s256b/v0/FUN_002a00ac.c; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/install_thread.h"

enum { INSTALL_THREAD_PRIORITY = 0x28, INSTALL_THREAD_STACK_SIZE = 0x18000 };

extern char DAT_002cba78[];
extern char DAT_002cba8c[];
extern char DAT_002cbad0[];
extern char DAT_002cbb14[];
extern void FUN_0029e3cc();
extern int FUN_002b78d8();
extern int FUN_002b7920();

/* Creates the worker thread running entry and starts it with self as its argument. */
void FUN_002a00ac(InstallThread *self,u32 entry)
{
  u32 thread;
  int ret;
  InstallThread *start_arg;
  
  ret = FUN_002b7920(DAT_002cbb14,entry,INSTALL_THREAD_PRIORITY,INSTALL_THREAD_STACK_SIZE,0,0);
  self->thread = ret;
  if (ret < 0) {
    FUN_0029e3cc(DAT_002cbad0,ret);
  }
  start_arg = self;
  ret = FUN_002b78d8(self->thread,4,&start_arg);
  if (ret < 0) {
    FUN_0029e3cc(DAT_002cba8c,self->thread);
    thread = self->thread;
  }
  else {
    thread = self->thread;
  }
  FUN_0029e3cc(DAT_002cba78,thread);
}
