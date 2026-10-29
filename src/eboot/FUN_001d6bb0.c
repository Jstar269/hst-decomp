/* HSTMATCH module=EBOOT.BIN start=0x001d6bb0 end=0x001d6bc8 symbol=FUN_001d6bb0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Four-field record, zero-initialised. */
typedef struct Record { u32 unk00; u16 unk04; char pad06[2]; u32 unk08; u8 unk0c; } Record;

Record * FUN_001d6bb0(Record *self)
{
  self->unk00 = 0;
  self->unk04 = 0;
  self->unk08 = 0;
  self->unk0c = 0;
  return self;
}
