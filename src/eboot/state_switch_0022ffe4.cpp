/* HSTMATCH module=EBOOT.BIN start=0x0022ffe4 end=0x0023028c symbol=FUN_0022ffe4 lang=c++ rodata=0x002c9c20 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: typed object and virtual classes, FUN_000487f4 returns int (no andi), 0x34179c is the symbol DAT_0034179c, `if (g) { delete g; g = 0; }` instead of the doubled null test, the range test as `>= 0x28 && < 0x32`; readability pass; exact match verified; names and types await human review. */
#include "hst/stateful_pane.h"

/* Ids 0x28..0x31 select entries of the table; the entry number is the id minus this base. */
enum { ID_RANGE_FIRST = 0x28, ID_RANGE_END = 0x32, ID_RANGE_BASE = 0x27 };

extern "C" {
extern char DAT_0034179c[];
extern void FUN_00103628(void *, int);
extern void FUN_0015dec0(void *);
extern int FUN_000487f4(void);
extern void FUN_0023028c(void *);
extern void FUN_001b1f84(void *, int *);
extern void FUN_001b3130(void *);
extern void FUN_001b3140(void *);
extern void FUN_001b31ac(void *);
extern void FUN_001b3244(void *);
extern void FUN_001b32f8(void *, int);
extern void FUN_001b338c(void *, int);
extern void FUN_001b3ce8(void *, int);
extern void FUN_001b3e2c(void *);
}

struct Deletable { virtual ~Deletable(); };

extern Deletable *DAT_0034a81c;

/* Leave the current state (1..8): undo what its update set up; most arms also call FUN_00103628 on node 214. */
extern "C" void FUN_0022ffe4(StatefulPane *self)
{
  switch (self->state) {
  case 1:
    self->node210->slot1(0);
    if (self->node214 == 0) return;
    FUN_00103628(self->node214, 0);
    break;
  case 2:
    self->sub->unk04 = 0;
    FUN_0015dec0(self->sub);
    if (FUN_000487f4() == 0) FUN_0023028c(self);
    if (self->node214 != 0) FUN_00103628(self->node214, 0);
    break;
  case 3:
    FUN_001b3e2c(DAT_0034179c);
    if (self->unka8 >= ID_RANGE_FIRST && self->unka8 < ID_RANGE_END) FUN_001b32f8(DAT_0034179c, self->unka8 - ID_RANGE_BASE);
    FUN_001b338c(DAT_0034179c, 0);
    FUN_001b338c(DAT_0034179c, 2);
    FUN_001b338c(DAT_0034179c, 6);
    FUN_001b3244(DAT_0034179c);
    self->unka4 = -1;
    self->unka8 = -1;
    FUN_001b3ce8(DAT_0034179c, 1);
    break;
  case 4:
    if (self->handle >= 0) {
      FUN_001b1f84(DAT_0034179c, &self->handle);
      self->handle = -1;
    }
    self->unkac = -1;
    self->unkb4 = -1;
    FUN_001b3130(DAT_0034179c);
    FUN_001b3140(DAT_0034179c);
    FUN_001b31ac(DAT_0034179c);
    FUN_001b3ce8(DAT_0034179c, 1);
    break;
  case 5:
    if (DAT_0034a81c != 0) {
      delete DAT_0034a81c;
      DAT_0034a81c = 0;
    }
    FUN_001b3ce8(DAT_0034179c, 1);
    if (self->node214 != 0) FUN_00103628(self->node214, 0);
    break;
  case 6:
    self->node210->slot1(0);
    if (self->node214 != 0) FUN_00103628(self->node214, 0);
    break;
  case 7:
    self->node210->slot1(0);
    if (self->node214 != 0) FUN_00103628(self->node214, 0);
    break;
  case 8:
    self->unkb8 = 0;
    self->node210->slot1(0);
    if (self->node214 != 0) FUN_00103628(self->node214, 0);
    break;
  }
}
