/* HSTMATCH module=hstp_trans_main.prx start=0x00003ab0 end=0x00003ae4 symbol=FUN_00003ab0 lang=c99 */
/* Clone of src/eboot/FUN_00155ea4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/cmd_base.h"

extern u8 DAT_003b021c;
extern u32 * FUN_00003ae4();

/* Constructor: base constructor, then this class's vtable. */
CmdBase * FUN_00003ab0(CmdBase *self)
{
  FUN_00003ae4();
  self->vtable = &DAT_003b021c;
  return self;
}
