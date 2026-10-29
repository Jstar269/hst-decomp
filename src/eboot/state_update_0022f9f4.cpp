/* HSTMATCH module=EBOOT.BIN start=0x0022f9f4 end=0x0022fc38 symbol=FUN_0022f9f4 lang=c++ rodata=0x002c9bd8 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/stateful_pane.h"

extern "C" {
extern char DAT_0034179c[];
extern void *DAT_0034a818;
extern void *DAT_003415d4;
extern void *DAT_003415ac;
extern void FUN_00103128(void *);
extern void FUN_00103628(void *, int);
extern int FUN_001155c0(void *);
extern int FUN_00190724(void *);
extern int FUN_001b1f7c(void *, int);
extern int FUN_001b2bc0(void *, int *);
extern void FUN_001b40d8(void *);
extern void FUN_001b4104(void *);
extern void FUN_0022d49c(void *);
extern void FUN_0022da30(void *);
extern void FUN_0022fcdc(void *, int);
extern void FUN_0023028c(void *);
extern int FUN_002911c0(void *);
extern void FUN_002911cc(void *);
extern void FUN_002a4d40(void *);
}

/* Setting bits at byte 0x8b of the global config (2-bit signed fields). */
struct ConfigBits { signed char a : 2; signed char b : 2; signed char c : 2; };
struct Config { char pad[0x8b]; ConfigBits bits; };
extern Config *DAT_002cfc8c;

extern StateMgr *DAT_0034b350;

/* Per-frame update: common refresh, then the work of the current state (0..8); finally slot 2 of node 214. */
extern "C" void FUN_0022f9f4(StatefulPane *self)
{
  FUN_00103128(self);
  switch (self->state) {
  case 0:
    FUN_0023028c(self);
    break;
  case 1:
    FUN_0022da30(self);
    break;
  case 2:
    FUN_0022d49c(self);
    break;
  case 3:
    FUN_0023028c(self);
    break;
  case 4:
    if (FUN_001b1f7c(DAT_0034179c, self->handle) == 0 && self->unkac >= 0) {
      int r = FUN_001b2bc0(DAT_0034179c, &self->unkac);
      self->handle = r;
      if (r < 0) {
        self->unkac = -1;
        FUN_0022fcdc(self, 0);
      }
    }
    FUN_0023028c(self);
    break;
  case 5:
    if (FUN_002911c0(DAT_0034a818) == 0 || DAT_002cfc8c->bits.b == 0 || DAT_002cfc8c->bits.c == 0) {
      FUN_002911cc(DAT_0034a818);
      FUN_0022fcdc(self, 0);
    }
    break;
  case 6:
    if (FUN_00190724(DAT_003415d4) != 0) FUN_0022fcdc(self, 0);
    break;
  case 7:
    if (FUN_00190724(DAT_003415d4) != 0) FUN_0022fcdc(self, 0);
    break;
  case 8:
    if (self->unkb8 != 0) {
      if (FUN_001155c0(DAT_003415ac) != 0) {
        FUN_00103628(DAT_003415ac, 1);
        FUN_002a4d40(DAT_0034b350);
        self->unkb8 = 0;
        FUN_001b40d8(DAT_0034179c);
      }
    } else {
      if (DAT_0034b350 != 0 && DAT_0034b350->busy == 0) {
        FUN_001b4104(DAT_0034179c);
        FUN_0022fcdc(self, 0);
      }
    }
    break;
  }
  if (self->node214 != 0) self->node214->slot2();
}
