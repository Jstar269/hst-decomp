/* HSTMATCH module=hstp_trans_main.prx start=0x002af3f0 end=0x002af484 symbol=FUN_002af3f0 lang=c99 */
/* Clone of src/eboot/FUN_002a00ac.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/install_thread.h"

enum { INSTALL_THREAD_PRIORITY = 0x28, INSTALL_THREAD_STACK_SIZE = 0x18000 };

extern char DAT_002dbb18[];
extern char DAT_002dbb2c[];
extern char DAT_002dbb70[];
extern char DAT_002dbbb4[];
extern void FUN_002ad710();
extern int FUN_002c7678();
extern int FUN_002c76c0();

/* Creates the worker thread running entry and starts it with self as its argument. */
void FUN_002af3f0(InstallThread *self,u32 entry)
{
  u32 thread;
  int ret;
  InstallThread *start_arg;
  
  ret = FUN_002c76c0(DAT_002dbbb4,entry,INSTALL_THREAD_PRIORITY,INSTALL_THREAD_STACK_SIZE,0,0);
  self->thread = ret;
  if (ret < 0) {
    FUN_002ad710(DAT_002dbb70,ret);
  }
  start_arg = self;
  ret = FUN_002c7678(self->thread,4,&start_arg);
  if (ret < 0) {
    FUN_002ad710(DAT_002dbb2c,self->thread);
    thread = self->thread;
  }
  else {
    thread = self->thread;
  }
  FUN_002ad710(DAT_002dbb18,thread);
}
