/* HSTMATCH module=hstp_trans_main.prx start=0x001623ac end=0x001623e0 symbol=FUN_001623ac lang=c99 */
/* Clone of src/eboot/FUN_00155ea4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/cmd_base.h"

extern u8 DAT_003b17d4;
extern u32 * FUN_00157f0c();

/* Constructor: base constructor, then this class's vtable. */
CmdBase * FUN_001623ac(CmdBase *self)
{
  FUN_00157f0c();
  self->vtable = &DAT_003b17d4;
  return self;
}
