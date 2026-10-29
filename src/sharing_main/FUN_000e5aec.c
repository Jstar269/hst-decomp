/* HSTMATCH module=hstp_trans_main.prx start=0x000e5aec end=0x000e5b78 symbol=FUN_000e5aec lang=c99 */
/* Clone of src/eboot/FUN_000e1584.c (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0037d870;
extern u8 DAT_003b0978;
extern u32 * FUN_0001ec44();
extern void FUN_000e5bdc();
extern void FUN_000e5d60();

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
TrailObj * FUN_000e5aec(TrailObj *self,u32 owner,u32 arg,int cfg)
{
  FUN_0001ec44(self);
  self->vtable = (unsigned int)(&DAT_003b0978);
  self->buf = 0;
  self->unk40 = 0;
  self->owner = owner;
  self->unk44 = arg;
  self->cfg = (unsigned int)(&DAT_0037d870);
  if (cfg != 0) {
    self->cfg = cfg;
  }
  FUN_000e5bdc((int)self);
  FUN_000e5d60(self);
  return self;
}
