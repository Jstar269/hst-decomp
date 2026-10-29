/* HSTMATCH module=hstp_trans_main.prx start=0x00228668 end=0x0022869c symbol=FUN_00228668 lang=c99 */
/* Clone of src/eboot/FUN_00155ea4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/cmd_base.h"

extern u8 DAT_003b28a4;
extern u32 * FUN_0005b6bc();

/* Constructor: base constructor, then this class's vtable. */
CmdBase * FUN_00228668(CmdBase *self)
{
  FUN_0005b6bc();
  self->vtable = &DAT_003b28a4;
  return self;
}
