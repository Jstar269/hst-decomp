/* HSTMATCH module=hstp_trans_main.prx start=0x001587e8 end=0x00158838 symbol=FUN_001587e8 lang=c++ */
/* Clone of src/eboot/FUN_0014cd00.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
#include "hst/module_ctx.h"

struct VC_0 { virtual ~VC_0(); };

/* Drop the running child of a context. */
extern "C" void FUN_001587e8(ModuleCtx *self)
{
  VC_0 *owned;
  
  owned = (VC_0 *)self->owned;
  if ((owned != 0) && (owned != 0)) {
    delete owned;
    self->owned = 0;
  }
}
