/* HSTMATCH module=EBOOT.BIN start=0x00003c1c end=0x00003c50 symbol=FUN_00003c1c lang=c99 */
/* Clone of src/eboot/FUN_00155ea4.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/cmd_base.h"

extern u8 DAT_00306f30;
extern u32 * FUN_00003ae4();

/* Constructor: base constructor, then this class's vtable. */
CmdBase * FUN_00003c1c(CmdBase *self)
{
  FUN_00003ae4();
  self->vtable = &DAT_00306f30;
  return self;
}
