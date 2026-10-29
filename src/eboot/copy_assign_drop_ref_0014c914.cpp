/* HSTMATCH module=EBOOT.BIN start=0x0014c914 end=0x0014c9b8 symbol=FUN_0014c914 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: the address-taken `last` (the node-list sentinel address, local_c in Ghidra) assigned after the field copies, just before the call; readability pass; exact match verified; names and types await human review. */
#include "hst/module_ctx.h"

extern "C" {
extern void FUN_0014f32c(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Copy assignment of a context: drop the running child, copy the scalar fields, clear the node list. */
extern "C" ModuleCtx * FUN_0014c914(ModuleCtx *self,ModuleCtx *other)
{
  VC_0 *owned;
  u8 eraseResult [4];
  DListLinks *first;
  DListLinks *last;
  
  owned = (VC_0 *)self->owned;
  if (owned != 0) {
    delete owned;
    self->owned = 0;
  }
  self->table = other->table;
  self->module = other->module;
  self->arg = other->arg;
  self->flag = other->flag;
  self->cur = other->cur;
  self->owned = 0;
  last = &self->nodes.sentinel;
  first = self->nodes.sentinel.next;
  FUN_0014f32c(eraseResult,&self->nodes,&first,&last);
  return self;
}
