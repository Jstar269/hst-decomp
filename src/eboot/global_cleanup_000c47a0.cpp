/* HSTMATCH module=EBOOT.BIN start=0x000c47a0 end=0x000c482c symbol=FUN_000c47a0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a6) corrected by hand: pass the global pointer to its setter and use the deleting virtual destructor; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/online_game.h"

extern "C" {
extern int * DAT_00338ac4;
extern void FUN_00000a00(int);
extern u32 FUN_000ba504(int);
extern u32 FUN_000ba78c(int);
}
struct VC_0 { virtual ~VC_0(); };

/* Stops and deletes the global manager object and frees the link. */
extern "C" void FUN_000c47a0(OnlineGame *self)
{
  if (DAT_00338ac4 != (int *)0x0) {
    FUN_000ba78c((int)DAT_00338ac4);
    FUN_000ba504((int)DAT_00338ac4);
    if (DAT_00338ac4 != (int *)0x0) {
      delete ((VC_0 *)DAT_00338ac4);
      DAT_00338ac4 = (int *)0x0;
    }
  }
  if (self->link != 0) {
    FUN_00000a00((int)self->link);
    self->link = 0;
  }
}
