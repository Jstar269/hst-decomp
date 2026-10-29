/* HSTMATCH module=EBOOT.BIN start=0x0010c2b4 end=0x0010c2c0 symbol=FUN_0010c2b4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/stream_obj.h"

/* Clears two integer fields of the stream. */
void FUN_0010c2b4(StreamObj *self)
{
  self->unk08 = 0;
  self->unk68 = 0;
}
