/* HSTMATCH module=EBOOT.BIN start=0x0014d788 end=0x0014d7fc symbol=FUN_0014d788 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q4) corrected by hand: the 4-bit field extracted as (x >> 12) & 0xf; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/script_node.h"
#include "hst/stream_cursor.h"

extern u8 DAT_0030832c;
extern u8 DAT_0030840c;
extern u32 FUN_0014f028();
extern u16 FUN_0014f050();

/* Reads a set-variable command: 16-bit word (4-bit type, 12-bit index) then the 32-bit value. */
VarCmd * FUN_0014d788(VarCmd *self,StreamCursor *stream)
{
  u32 packed;
  u32 value;

  self->base.vtable = &DAT_0030840c;
  self->base.unk04 = 0;
  self->base.vtable = &DAT_0030832c;
  packed = FUN_0014f050(stream);
  self->type = (packed >> 0xc) & 0xf;
  self->index = packed & 0xfff;
  value = FUN_0014f028(stream);
  self->value.i = value;
  return self;
}
