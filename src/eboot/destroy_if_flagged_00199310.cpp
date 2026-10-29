/* HSTMATCH module=EBOOT.BIN start=0x00199310 end=0x00199398 symbol=FUN_00199310 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/install_flow.h"

extern "C" {
extern int DAT_00309194[];
extern char DAT_00341771;
extern int FUN_002b7cd0(void *);
extern void FUN_002b7c30();
extern void FUN_0001f0f0(void *, int);
extern void FUN_00000a00(void *);
}

/* Deleting destructor of the install flow: finishes the pending status 3, clears the global flag. */
extern "C" InstallFlow *FUN_00199310(InstallFlow *self, short flag)
{
  if (self != 0) {
    self->vtable = DAT_00309194;
    switch (FUN_002b7cd0(self)) {
    case 3:
      FUN_002b7c30();
      break;
    }
    DAT_00341771 = 0;
    FUN_0001f0f0(self, 0);
    if (0 < (int)flag)
      FUN_00000a00(self);
  }
  return self;
}
