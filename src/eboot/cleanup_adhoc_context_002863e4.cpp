/* HSTMATCH module=EBOOT.BIN start=0x002863e4 end=0x00286490 symbol=FUN_002863e4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: pass the global object to FUN_000ba78c and dispatch Release through the second vtable slot. */
#include "hst/screen_mgr.h"

struct RefObj {
  virtual void Release(int);
};
extern "C" unsigned char DAT_003386b8;
extern "C" void *DAT_00338ac4;
extern "C" ScreenMgr *DAT_003415ac;
extern "C" void FUN_000ba504(void *);
extern "C" void FUN_000ba78c(void *);
extern "C" void FUN_00103628(void *, int);

/* Closes the top page when it is idle in mode 6, then tears down the global ad-hoc session object. */
extern "C" void FUN_002863e4(void)
{
  if (((*DAT_003415ac->pageList->pages)->flags & 3) == 0 && DAT_003415ac->mode == 6) {
    FUN_00103628(DAT_003415ac,1);
  }
  void *object = DAT_00338ac4;
  if (object != 0) {
    FUN_000ba78c(DAT_00338ac4);
    FUN_000ba504(DAT_00338ac4);
    if (DAT_00338ac4 != 0) {
      if (DAT_00338ac4 != 0) {
      ((RefObj *)DAT_00338ac4)->Release(1);
      }
      DAT_00338ac4 = 0;
    }
    DAT_003386b8 = 0;
  }
}
