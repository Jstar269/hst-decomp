/* HSTMATCH module=EBOOT.BIN start=0x0014c820 end=0x0014c8cc symbol=FUN_0014c820 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/module_ctx.h"

extern "C" {
extern void FUN_00000a00(...);
extern void FUN_0014f32c(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Deleting destructor of a context: drop the running child, clear the node list, free when flags > 0. */
extern "C" ModuleCtx * FUN_0014c820(ModuleCtx *self,short flags)
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
      FUN_0014f32c(eraseResult,nodes,&first,&last);
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
