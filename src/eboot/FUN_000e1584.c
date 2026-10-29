/* HSTMATCH module=EBOOT.BIN start=0x000e1584 end=0x000e1610 symbol=FUN_000e1584 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d6b10;
extern u8 DAT_003076ac;
extern u32 * FUN_0001f06c();
extern void FUN_000e1674();
extern void FUN_000e1798();

typedef struct TrailObj {
  u32 vtable;             /* 0x00 */
  char pad04[0x3c - 4];
  u32 cfg;                /* 0x3c */
  u32 unk40;              /* 0x40 */
  u32 unk44;              /* 0x44 */
  char pad48[0x54 - 0x48];
  u32 buf;                /* 0x54 */
  u32 owner;              /* 0x58 */
} TrailObj;

/* Constructor: base init, then stores the owner, a second argument and the config (default config when none is given). */
TrailObj * FUN_000e1584(TrailObj *self,u32 owner,u32 arg,int cfg)
{
  FUN_0001f06c(self);
  self->vtable = (unsigned int)(&DAT_003076ac);
  self->buf = 0;
  self->unk40 = 0;
  self->owner = owner;
  self->unk44 = arg;
  self->cfg = (unsigned int)(&DAT_002d6b10);
  if (cfg != 0) {
    self->cfg = cfg;
  }
  FUN_000e1674((int)self);
  FUN_000e1798(self);
  return self;
}
