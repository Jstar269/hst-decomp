/* HSTMATCH module=EBOOT.BIN start=0x0014cd00 end=0x0014cd50 symbol=FUN_0014cd00 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/module_ctx.h"

struct VC_0 { virtual ~VC_0(); };

/* Drop the running child of a context. */
extern "C" void FUN_0014cd00(ModuleCtx *self)
{
  VC_0 *owned;
  
  owned = (VC_0 *)self->owned;
  if ((owned != 0) && (owned != 0)) {
    delete owned;
    self->owned = 0;
  }
}
