/* HSTMATCH module=hstp_trans_main.prx start=0x00158308 end=0x001583b4 symbol=FUN_00158308 lang=c++ */
/* Clone of src/eboot/FUN_0014c820.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
#include "hst/module_ctx.h"

extern "C" {
extern void FUN_00000a00(...);
extern void FUN_0015b32c(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Deleting destructor of a context: drop the running child, clear the node list, free when flags > 0. */
extern "C" ModuleCtx * FUN_00158308(ModuleCtx *self,short flags)
{
  VC_0 *owned;
  DListHead *nodes;
  u8 eraseResult [4];
  DListLinks *first;
  DListLinks *last;
  
  if (self != 0) {
    owned = (VC_0 *)self->owned;
    if (owned != 0) {
      delete owned;
      self->owned = 0;
    }
    nodes = &self->nodes;
    if (((nodes != 0) && (nodes != 0)) && (nodes != 0)) {
      last = &self->nodes.sentinel;
      first = self->nodes.sentinel.next;
      FUN_0015b32c(eraseResult,nodes,&first,&last);
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
